#ifndef __DATAUTILS__
#define __DATAUTILS__
#include "stdafx.h"

//���ݴ�����

#define _dataUtils DataUtils::getInstance()

class DataUtils{
public:
	static DataUtils* getInstance();
private:
	static DataUtils* _instance;

public:
	void copyMatrix(char**& matrix_dst, char**& matrix_res, int width, int height);

};
#endif