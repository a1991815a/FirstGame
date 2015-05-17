// FirstGame.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "Director.h"
#include <iostream>
#include "FileIO.h"
#include "Map.h"
#include "TextOutUtils.h"
#include <assert.h>

#define GameVersion 6.0f

int _tmain(int argc, _TCHAR* argv[])
{
	float d = GameVersion;
	DEBUG_STRING(true, "DEBUG模式开启!%ff", 0.6f);
	try
	{
		_director->initAll();
		_director->mainloop();
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}

void GameMain(){
	Scene* scene = Scene::create();

	Map* map = _fileIO->loadMapFromFile("map.txt");

	scene->addChild(map);

	_director->setScene(scene);
	Player* player = Player::create();
	player->setTexture("二");
	player->setPos(1,13);
	map->addChild(player, 5);
	scene->setActor(player);

	showSideText("开始游戏");
	showSubText("结束游戏");
}



