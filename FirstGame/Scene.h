#ifndef __SCENE__
#define __SCENE__
#include "stdafx.h"
#include "Node.h"

class Map;
class Player;

class Scene : public Node{
public:
	CREATE_FUNC(Scene);
	virtual bool init();

	Scene();
	virtual ~Scene();

	virtual void visit(Vec2 vec);

	void addChild(Map* map);

	void assembleFragment();

	inline Player* getActor() const { return _actor; }
	inline void setActor(Player* val) { _actor = val; }

	Map* getMap() const;
private:
	char** final_data;
	Map* _map;
	Player* _actor;
	
};
#endif