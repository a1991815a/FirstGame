#include "RenderEngine.h"
#include "Map.h"
#include "Director.h"
#include "CustomUtils.h"
#include <stdarg.h>

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
	system("cls");
	for (int row=0; row < MAX_HEIGHT; row++)
	{	
		if(display_data[row][0] == -51 || display_data[row][0] == 0)
			continue;
		cout << display_data[row];
		renderSideText(row);
		cout << endl;
	}
	renderSubText();
}

void RenderEngine::readyBuf()
{
	if (_director->getCurrentScene() == nullptr)
	{
		throw "没有可加载的场景！";
	}
	_director->getCurrentScene()->assembleFragment();
	assembleFragment();
	cutBuf();
}

void RenderEngine::clear()
{
	for (int row = 0; row < MAX_HEIGHT; row++)
	{
		memset(display_data[row], '\0', MAX_WIDTH + 1);
		for (int col = 0; col < MAX_WIDTH + 1; col++)
		{
			display_data[row][col] = '\0';
		}
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
	for (int row = 0; row < MAX_HEIGHT; row++)
	{
		
	}
	
}

void RenderEngine::assembleSideText()
{

}

void RenderEngine::cutBuf()
{
	for (int row=CUT_HEIGHT+1; row < MAX_HEIGHT; row++)
	{
		for (int col=0; col < MAX_WIDTH; col++)
		{
			display_data[row][col] = '\0';
		}
	}

	for (int col=CUT_WIDTH; col < MAX_WIDTH; col++)
	{
		for (int row=0; row < CUT_HEIGHT + 1; row++)
		{
			display_data[row][col] = '\0';
		}
	}

}

void RenderEngine::setSubText( string format, ... )
{
	va_list ap;
	va_start(ap,format);
	char out_text[1024] = {0};
	vsprintf_s(out_text, 1024, format.c_str(), ap);
	va_end(ap);
	sub_text += out_text;
}


void RenderEngine::setSideText(int row, string format, ... )
{
	va_list ap;
	va_start(ap,format);
	char out_text[1024];
	vsprintf_s(out_text, 1024, format.c_str(), ap);
	va_end(ap);
	side_text[row] += out_text;
}

void RenderEngine::renderSubText()
{
	int i = 0;
	while(true)
	{
		const int offset = i*SUB_TEXT_SIZE_WIDTH;
		char show_text[SUB_TEXT_SIZE_WIDTH + 1]={0};
		if(offset >= sub_text.size())
			break;
		sub_text.copy(show_text,SUB_TEXT_SIZE_WIDTH,offset);
		if(show_text[0] == '\0')
			break;
		cout << show_text << endl;
		i++;
	}

}

void RenderEngine::renderSideText(int row)
{
	if (row >= MAX_HEIGHT)
	{
		return;
	}
	cout << "　　*" << side_text[row].c_str();
}

void RenderEngine::clearSubTextBuf()
{

}

void RenderEngine::clearSideTextBuf()
{

}
