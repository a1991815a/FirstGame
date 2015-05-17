#include "EventSystem.h"
#include "Event.h"

EventSystem* EventSystem::_instance = nullptr;

EventSystem* EventSystem::getInstance()
{
	if (_instance == nullptr){
		_instance = new EventSystem();
	}
	return _instance;
}

void EventSystem::insertEvent(int id, Event* event)
{
	event_list.insert(map<int, Event*>::value_type(id, event));
	event->retain();
}

void EventSystem::deleteEvent(int index)
{
	if (event_list.find(index) != event_list.end())
		event_list.at(index)->release();					//ÒıÓÃ-1
	event_list.erase(index);
}

Event* EventSystem::getEvent(int id)
{
	return event_list.at(id);
}
