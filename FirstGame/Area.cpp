#include "Area.h"
#include "GameManager.h"
#include "Player.h"

void Area::trigger()
{
	bool condition = false;
	for (int i = 0; i < pos_list.size(); i++)
	{
		if (pos_list.at(i) == _gameManager->getPlayer()->getPos())
		{
			condition = true;
			break;
		}
	}

	if (condition)
		for (int i = 0; i < script_list.size(); i++)
		{
			script_list.at(i).excute();
		}
}

void Area::pushPos(Vec2 pos)
{
	pos_list.push_back(pos);
}

void Area::pushScript(Script script)
{
	script_list.push_back(script);
}
