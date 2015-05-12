#include "FileIO.h"
#include "Map.h"

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
	char header_width[6];
	char header_height[6];
	fread_s(header_width, 6, 1, 5, file);
	fread_s(header_height, 6, 1, 5, file);
	*width = atoi(header_width);
	*height = atoi(header_height);
}


