#include "RenderEngine.h"
#include "Map.h"
#include "Director.h"
#include "CustomUtils.h"

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
		cout << display_data[row] << endl;
	}
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

void RenderEngine::cutBuf()
{
	for (int row=CUT_HEIGHT+1; row < MAX_HEIGHT; row++)
	{
		for (int col=0; col < MAX_WIDTH; col++)
		{
			display_data[row][col] = '\0';
		}
	}

	for (int col=0; col < MAX_WIDTH; col++)
	{
		for (int row=CUT_WIDTH; row < MAX_HEIGHT; row++)
		{
			display_data[row][col] = '\0';
		}
	}

}
