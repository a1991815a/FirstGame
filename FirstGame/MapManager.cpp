#include "MapManager.h"

MapManager* MapManager::_instance = nullptr;


MapManager* MapManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new MapManager();
	}
	return _instance;
}
