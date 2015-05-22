// FirstGame.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "Director.h"
#include <iostream>
#include "FileIO.h"
#include "Map.h"
#include "TextOutUtils.h"
#include <assert.h>
#include "Player.h"
#include "Sprite.h"
#include "Npc.h"
#include "SimplePhysicsEngine.h"
#include "ItemManager.h"
#include "FightSystem.h"
#include "GuiManager.h"
#include "GameManager.h"

#define GameVersion 6.0f

int _tmain(int argc, _TCHAR* argv[])
{
	float d = GameVersion;
	DEBUG_STRING(true, "DEBUG模式开启!%f", 0.6f);
	try
	{
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
	_fightSystem;

	Scene* scene = _guiManager->getFree_scene();

	Map* map = _fileIO->loadMapFromFile("map.txt");
	_guiManager->setFree_ui(map);

	scene->addChild(map);
	Player* player = Player::create();
	player->setName("玩家1");
	player->setTexture("△");
	player->setPos(1,13);
	player->setAttack(30);
	map->addChild(player, 5);
	scene->setActor(player);

	Actor* actor = Npc::create();
	actor->setDefence(4);
	actor->setName("敌人");
	actor->setTexture("●");
	actor->setHp(500);
	actor->setPos(3, 13);
	map->addChild(actor);
	_simplePhysicsEngine->setBody(actor, BodyType::RigidBody);

	showSideText(0, "开始游戏1");
	showSideText(1, "开始游戏2");
	showSideText(2, "开始游戏3");
	showSubText("结束游戏\n我是第一个测试程序！");
}

void GameDefence(){
	
};

void GameNormal(){

}

void GameHint(){

}


