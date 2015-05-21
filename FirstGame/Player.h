#ifndef __PLAYER__
#define __PLAYER__
#include "stdafx.h"
#include "Actor.h"

class NpcSoldier;

class Player: public Actor{
public:
	Player(){};
	CREATE_FUNC(Player);
	bool init();

	inline int getLevel() const { return _level; }
	inline void upLevel(int val) { _level += val; }

	int getType()const override{ return Node_Player; };

	void addSoldier(int num = 1);
	inline vector<NpcSoldier*> getAllSoldier() const { return soldier_list; }
	inline NpcSoldier* getSoldier(int index)const{ return soldier_list.at(index); };
private:
	int _level;

	vector<NpcSoldier*> soldier_list;
	
};
#endif