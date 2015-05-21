#ifndef __NPC__
#define __NPC__
#include "stdafx.h"
#include "Script.h"
#include "Actor.h"

class Npc: public Actor{
public:
	CREATE_FUNC(Npc);
	bool init();
	int getType()const override{ return Node_Npc; };

//	void trigger();

// private:
// 	vector<Script> _script_list;
};
#endif