#ifndef __SPRITEMANAGER__
#define __SPRITEMANAGER__
#include "stdafx.h"

//¾«Áé¹ÜÀíÆ÷

#define _spriteManager MapManager::getInstance()

class SpriteManager{
public:
	static SpriteManager* getInstance();
private:
	static SpriteManager* _instance;
};
#endif