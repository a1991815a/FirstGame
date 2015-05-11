#ifndef __FILEIO__
#define __FILEIO__
#include "stdafx.h"

#define _fileIO FileIO::getInstance()

class FileIO{
public:
	static FileIO* getInstance();
private:
	static FileIO* _instance;
};
#endif