#ifndef __DATAUTILS__
#define __DATAUTILS__
#include "stdafx.h"

#define _dataUtils DataUtils::getInstance()

class DataUtils{
public:
	static DataUtils* getInstance();
private:
	static DataUtils* _instance;

public:


};
#endif