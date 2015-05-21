#include "FileIO.h"
#include "Map.h"
#include <iostream>
#include "DataUtils.h"

FileIO* FileIO::_instance = nullptr;

FileIO* FileIO::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new FileIO();
	}
	return _instance;
}

Map* FileIO::loadMapFromFile( string filename )
{
	FILE* file = fopen(filename.c_str(),"rb+");
	if(file == nullptr)
		throw "打开文件失败！";
	int width = 0,height = 0;
	getHeaderFromFile(file,&width,&height);

	char** map_data = new char*[height];
	for (int i=0; i<height ;i++)
	{
		map_data[i] = new char[width + 1];
		fread_s(map_data[i],width,1,width,file);
		map_data[i][width] = '\0';
		fseek(file,2,SEEK_CUR);
	}
	fclose(file);
	Map* map = Map::create(width, height);
	map->initData(map_data);
	return map;
}

long FileIO::getFileSize( FILE*& file )
{
	if(file == nullptr)
		return 0;
	fseek(file,0,SEEK_END);
	long size = ftell(file);
	rewind(file);
	return size - 10;
}

void FileIO::getHeaderFromFile( FILE*& file, int* width, int* height )
{
	if(file == nullptr)
		return;
	char header_width[4];
	char header_height[4];
	fread_s(header_width, 4, 1, 3, file);
	fread_s(header_height, 4, 1, 3, file);
	*width = atoi(header_width);
	*height = atoi(header_height);
	
	if (*width > MAX_WIDTH || *height > MAX_HEIGHT)
	{
		fclose(file);
		throw "地图尺寸太大！无法加载！";
	}

	fseek(file,2,SEEK_CUR);
}

vector<User> FileIO::loadUserFromFile(string filename)
{
	vector<User> vu;
	FILE* file = nullptr;
	fopen_s(&file, filename.c_str(), "rb+");
	long file_size = getFileSize(file);
	char* user_text = new char[file_size];
	fread_s(user_text, file_size, sizeof(char), file_size, file);
	fclose(file);
	int index = 0;
	string split_data = user_text;
	_dataUtils->deleteCharFromString(split_data, '\r', index);
	vector<string> string_list = _dataUtils->splitString(split_data, '\n', index);
	for (int i = 0; i < string_list.size(); i++)
	{
		string& obj = string_list.at(i);
		vector<string> user_t = _dataUtils->splitString(obj, ',', index);
		if (user_t.size() == 2)
		{
			User u;
			u.name = user_t.at(0);
			u.password = user_t.at(1);
			vu.push_back(u);
		}
	}

	return vu;
}


