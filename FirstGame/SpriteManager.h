#ifndef __SPRITEMANAGER__
#define __SPRITEMANAGER__
#include "stdafx.h"

#define _spriteManager MapManager::getInstance()

class SpriteManager{
public:
	static SpriteManager* getInstance();
private:
	static SpriteManager* _instance;
};
#endif