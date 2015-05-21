#ifndef __FILEIO__
#define __FILEIO__
#include "stdafx.h"
#include "UserManager.h"
class Map;

//文件IO工具

#define _fileIO FileIO::getInstance()

class FileIO{
public:
	static FileIO* getInstance();
private:
	static FileIO* _instance;

public:
	Map* loadMapFromFile(string filename);

	void getHeaderFromFile(FILE*& file, int* width, int* height);

	vector<User> loadUserFromFile(string filename);
private:
	long getFileSize(FILE*& file);
};
#endif