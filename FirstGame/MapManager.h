#ifndef __MAPMANAGER__
#define __MAPMANAGER__
#include "stdafx.h"

//��ͼ��������

#define _mapManager MapManager::getInstance()

class MapManager{
public:
	static MapManager* getInstance();
private:
	static MapManager* _instance;
};
#endif