#include "Scene.h"
#include "Map.h"

Scene::Scene()
	:Node()
{
	_map = nullptr;
}

Scene::~Scene()
{
	if (final_data != nullptr)
	{
		for (int row = 0; row < _map->getHeight(); row++)
		{
			delete[] final_data[row];
		}
	}
}

void Scene::addChild(Map* map)
{
	_map = map;
	_map->retain();
}

bool Scene::init()
{
	return true;
}

void Scene::assembleFragment()
{
	if (_map == nullptr)
	{
		throw "ÇëÖ¸¶¨µØÍ¼£¡";
	}
	sendRenderCommand();
}

Map* Scene::getMap() const
{
	return _map;
}

void Scene::visit( Vec2 vec )
{
	_map->visit(Vec2());
}
