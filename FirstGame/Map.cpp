#include "Map.h"
#include "DataUtils.h"

Map::Map()
	:Node()
{

}

bool Map::init( short width, short height )
{
	this->width = width;
	this->height = height;

	final_data = new char*[height];
	for (int i=0; i<height; i++)
	{
		final_data[i] = new char[width + 1];
		final_data[width] = '\0';
	}

	return true;
}

bool Map::init()
{
	return true;
}

Map* Map::create( short width, short height )
{
	Map* map = Map::create();
	if (map && map->init(width, height))
	{
		return map;
	}
	SAFE_DELETE(map);
	return nullptr;
}

void Map::initData( char**& in_data )
{
	this->map_data = in_data;
	_dataUtils->copyMatrix(final_data, map_data, width, height);
}

Map::~Map()
{
	for (int i=0; i<height; i++)
	{
		delete[] map_data[i];
	}
	delete[] map_data;
}
