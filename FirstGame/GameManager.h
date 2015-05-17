#ifndef __MAPCHECKER__
#define __MAPCHECKER__
#include "stdafx.h"

class Monster;
class Node;
class NpcActor;
class House;

#define _gameManager GameManager::getInstance()

class GameManager{
public:
	static GameManager* getInstance();
private:
	static GameManager* _instance;

public:
	Node* checkCollision(Vec2 pos);
	Monster* checkTouchMonster(Vec2 pos);
	NpcActor* checkTouchNpc(Vec2 pos);
	House* checkInHouse(Vec2 pos);

	void trigger();
};
#endif