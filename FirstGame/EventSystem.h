#ifndef __EVENTSYSTEM__
#define __EVENTSYSTEM__
#include "stdafx.h"

class Event;

#define _eventSystem EventSystem::getInstance()

class EventSystem{
public:
	static EventSystem* getInstance();
private:
	static EventSystem* _instance;
public:
	void insertEvent(int id, Event* event);
	void deleteEvent(int id);
	Event* getEvent(int id);

private:
	map<int, Event*> event_list;

};
#endif