#ifndef __NPCACTOR__
#define __NPCACTOR__
#include "Actor.h"
#include "LimitedState.h"

class NpcActor: public Actor, public LimitedState{
public:
	CREATE_FUNC(NpcActor);

	virtual bool init();

private:
	virtual bool callback_1(Message msg);
};
#endif