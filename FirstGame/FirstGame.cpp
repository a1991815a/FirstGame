// FirstGame.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "Director.h"
#include <iostream>
#include "FileIO.h"
#include "Map.h"

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

}



