#include "RenderEngine.h"
#include "Map.h"
#include "Director.h"
#include "CustomUtils.h"
#include <stdarg.h>
#include "ConsoleBufferUtils.h"

RenderEngine* RenderEngine::_instance = nullptr;

RenderEngine::RenderEngine()
{
	display_data = new char*[MAX_HEIGHT];
	for (int row = 0; row < MAX_HEIGHT; row++)
	{
		display_data[row] = new char[MAX_WIDTH + 1];
	}
}

RenderEngine* RenderEngine::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new RenderEngine();
	}
	return _instance;
}

void RenderEngine::RenderAll()
{
	_consoleBufferUtils->renderAll();
}

void RenderEngine::readyBuf()
{
	if (_director->getCurrentScene() == nullptr)
		throw "没有可加载的场景！";

	_director->getCurrentScene()->assembleFragment();
	assembleFragment();
	assembleSideText();
	assembleSubText();
	for (int row = 0; row < MAX_HEIGHT; row++)
	{
		out_text += display_data[row];
		out_text.erase(out_text.size() - 1);
		out_text += '\n';
	}
}

void RenderEngine::clear()
{
	for (int row = 0; row < MAX_HEIGHT; row++)
	{
		memset(display_data[row], '\0', MAX_WIDTH + 1);
	}
}

void RenderEngine::sendCommand( Node* node, Vec2 pos )
{
	_command_list.push_back(RenderCommand(node, pos));
}

void RenderEngine::assembleFragment()
{
	for (int i=0; i<_command_list.size(); i++)
	{
		RenderCommand& _command = _command_list.at(i);
		_command.node->visit(_customUtils->transMapVec2(
			_director->getCurrentScene()->getMap()
			,_command.renderPos
			));
	}
	_command_list.clear();
}

void RenderEngine::assembleSubText()
{
	for (int row = SUB_TEXT_POS_Y; row < MAX_HEIGHT; row++)
	{
		int row_index = (row - SUB_TEXT_POS_Y)* MAX_WIDTH;

		for (int col = 0; col < MAX_WIDTH; col++)
		{
			if (row_index + col >= sub_text.size())
				break;
			display_data[row][col] = sub_text.at(row_index + col);
		}
	}
	
}

void RenderEngine::assembleSideText()
{
	for (int row = 0; row < MAX_HEIGHT; row++)
	{
		for (int col = CUT_WIDTH - 1; col < SIDE_TEXT_POS_X; col++)
		{
			display_data[row][col] = ' ';
		}
		for (int col = SIDE_TEXT_POS_X; col < MAX_WIDTH; col++)
		{
			if (col - SIDE_TEXT_POS_X >= side_text[row].size())
				break;
			display_data[row][col] = side_text[row].at(col - SIDE_TEXT_POS_X);
		}
	}
}

void RenderEngine::setSubText( string format, ... )
{
	clearSubTextBuf();
	va_list ap;
	va_start(ap,format);
	char out_text[1024] = {0};
	vsprintf_s(out_text, 1024, format.c_str(), ap);
	va_end(ap);
	sub_text += out_text;
}


void RenderEngine::setSideText(int row, string format, ... )
{
	clearSideTextBuf();
	va_list ap;
	va_start(ap,format);
	char out_text[1024] = {0};
	vsprintf_s(out_text, 1024, format.c_str(), ap);
	va_end(ap);
	side_text[row] += out_text;
}

void RenderEngine::clearSubTextBuf()
{
	sub_text.clear();
}

void RenderEngine::clearSideTextBuf()
{
	for (int row = 0; row < MAX_HEIGHT; row++)
	{
		side_text[row].clear();
	}
}
