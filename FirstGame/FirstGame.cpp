// FirstGame.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "Director.h"
#include <iostream>
#include "FileIO.h"
#include "Map.h"
#include "Player.h"
#include "TextOut.h"

#define GameVersion 1.0

int _tmain(int argc, _TCHAR* argv[])
{
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
	player->setTexture("Ҽ");
	player->setPos(1,13);
	map->addChild(player, 5);
	scene->setActor(player);

	showSideText("��ʼ��Ϸ");
	showSubText("������Ϸ");
}



