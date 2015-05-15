#ifndef __DATAUTILS__
#define __DATAUTILS__
#include "stdafx.h"

//数据处理工具

#define _dataUtils DataUtils::getInstance()

class DataUtils{
public:
	static DataUtils* getInstance();
private:
	static DataUtils* _instance;

public:
	void copyMatrix(char**& matrix_dst, char**& matrix_res, int width, int height);
	
	inline bool getTagFromInt(int tag, int num){
		tag >>= (num - 1);
		tag &= 0x0001;
		if(tag == 0x0001)
		return true;
		return false;
	};


};
#endif