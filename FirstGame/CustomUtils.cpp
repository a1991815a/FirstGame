#include "CustomUtils.h"
#include <time.h>
#include <sys/timeb.h>
#include "Map.h"
#include "Director.h"

CustomUtils* CustomUtils::_instance = nullptr;

CustomUtils* CustomUtils::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new CustomUtils();
		timeb t;
		ftime(&t);
		_instance->_time = t.time*1000 + t.millitm;
		_instance->before_time = 0;
	}
	return _instance;
}

long CustomUtils::getTime() const
{
	timeb t;
	ftime(&t);
	return (t.time * 1000 + t.millitm) - _time;
}

Vec2 CustomUtils::transMapVec2( Map* map, Vec2 pos ) const
{
	int x = 0, y = 0;

	y = map->getHeight() - pos.y;
	x = pos.x * 2;
	return Vec2(x,y);
}

float CustomUtils::getDeleta()
{
	int time = getTime();
	int dt = time - before_time;
	before_time = time;
	return dt/1000;
}

Vec2 CustomUtils::transNodeVec2( Node* node, Vec2 pos ) const
{
	Vec2 node_pos = pos;
	Vec2 parent_pos = Vec2(0,0);
	if (node->getParent() != nullptr)
	{
		parent_pos = transGlobalVec2(node->getParent(), node->getParent()->getPos());
	}
	node_pos -= parent_pos;
	return node_pos;
}

Vec2 CustomUtils::transGlobalVec2( Node* node, Vec2 pos ) const
{
	Vec2 global_pos = pos;
	Vec2 parent_pos = Vec2(0,0);
	if (node->getParent() != nullptr)
	{
		parent_pos = transGlobalVec2(node->getParent(), node->getParent()->getPos());
	}
	global_pos += parent_pos;
	return global_pos;
}

Vec2 CustomUtils::transRenderVec2( Node* node, Vec2 pos ) const
{
	pos = transGlobalVec2(node, pos);
	pos = transMapVec2(_director->getCurrentScene()->getMap(), pos);
	return pos; 
}
