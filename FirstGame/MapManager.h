#ifndef __MAPMANAGER__
#define __MAPMANAGER__
#include "stdafx.h"

//地图管理引擎

#define _mapManager MapManager::getInstance()

class MapManager{
public:
	static MapManager* getInstance();
private:
	static MapManager* _instance;
};
#endif