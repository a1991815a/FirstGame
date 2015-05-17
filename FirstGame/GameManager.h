#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__
#include "stdafx.h"

class Player;

#define _gameManager GameManager::getInstance()

class GameManager{
public:
	static GameManager* getInstance();
private:
	static GameManager* _instance;

public:
	Player* getPlayer();
};
#endif