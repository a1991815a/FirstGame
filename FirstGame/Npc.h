#ifndef __NPC__
#define __NPC__
#include "stdafx.h"
#include "Sprite.h"
#include "Script.h"

class Npc: public Sprite{
public:
	CREATE_FUNC(Npc);
	bool init();
	void trigger();

private:
	vector<Script> _script_list;
};
#endif