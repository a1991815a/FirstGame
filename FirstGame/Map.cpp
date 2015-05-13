#include "Map.h"
#include "DataUtils.h"
#include "RenderEngine.h"

Map::Map()
	:Node()
{

}

bool Map::init( short width, short height )
{
	this->width = width;
	this->height = height;
// 
// 	map_data = new char*[height];
// 
// 	for(int row=0; row<height; row++){
// 		map_data[row] = new char*[width+1];
// 	}

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

void Map::initData( char** in_data )
{
	this->map_data = in_data;
}

Map::~Map()
{
	for (int i=0; i<height; i++)
	{
		delete[] map_data[i];
	}
	delete[] map_data;
}

void Map::visit( Vec2 vec )
{
	for (int row=0; row<getHeight(); row++)
	{
		for (int col=0; col<getWidth(); col++)
		{
			_renderEngine->addRenderData(map_data[row][col], Vec2(col, row));
		}
	}
}
