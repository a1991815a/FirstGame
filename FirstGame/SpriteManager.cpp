#include "SpriteManager.h"

SpriteManager* SpriteManager::_instance = nullptr;



SpriteManager* SpriteManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new SpriteManager();
	}
	return _instance;
}
