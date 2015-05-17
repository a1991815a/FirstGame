#include "Map.h"
#include "DataUtils.h"
#include "RenderEngine.h"
#include "CustomUtils.h"

Map::Map()
	:Node()
{

}

bool Map::init( short width, short height )
{
	this->width = width;
	this->height = height;

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
	Vec2 pos = _customUtils->getCameraPos(this, CUT_WIDTH, CUT_HEIGHT);

	for (int row = pos.y; row < pos.y + CUT_HEIGHT - 1; row++)
	{
		for (int col = pos.x; col < pos.x + CUT_WIDTH - 1; col++)
		{
			_renderEngine->addRenderData(map_data[row][col], Vec2(pos.x + col, pos.y + row));
		}
	}
}