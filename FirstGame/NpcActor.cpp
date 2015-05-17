#include "NpcActor.h"
#include "ScriptInterpreter.h"

bool NpcActor::init()
{
	current_state = 0;
	return true;
}

bool NpcActor::callback_1(Message msg)
{


	return false;
}

void NpcActor::pushEvent(Event event)
{
	_event_list.push_back(event);
}

void NpcActor::popEvent()
{
	_event_list.pop_back();
}

void NpcActor::triggerEvent()
{
	_scriptInterpreter->excuteSingleScript(_event_list.at(current_state).getScrpit());
	current_state++;
}
