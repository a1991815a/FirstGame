#ifndef __MAP__
#define __MAP__
#include "stdafx.h"
#include "Node.h"
#include "header.h"
#include "Scene.h"

class Monster;
class NpcActor;

//µØÍ¼Ä£ÐÍ

class Map : public Node{
public:
	Map();
	CREATE_FUNC(Map);
	static Map* create(short width, short height);
	virtual bool init();
	virtual bool init(short width, short height);

	void initData(char** in_data);
	virtual ~Map();

	inline short getWidth() const{ return width;};
	inline short getHeight() const{return height;};

	virtual void visit(Vec2 vec) override;
	
private:
	char** map_data;
	short width;
	short height;

	friend void Scene::assembleFragment();
	friend int _tmain(int argc, _TCHAR* argv[]);
};
#endif