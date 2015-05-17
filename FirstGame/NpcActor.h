#ifndef __NPCACTOR__
#define __NPCACTOR__
#include "Actor.h"
#include "LimitedState.h"
#include "Event.h"

class NpcActor: public Actor, public LimitedState{
public:
	CREATE_FUNC(NpcActor);

	virtual bool init();

	void pushEvent(Event event);
	void popEvent();

	void triggerEvent();

private:
	virtual bool callback_1(Message msg);

	int current_state;
	vector<Event> _event_list;
};
#endif