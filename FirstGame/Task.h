#ifndef __TASK__
#define __TASK__
#include "stdafx.h"
#include "Event.h"
#include "LimitedState.h"
#include "Node.h"
#include "header.h"

/*
	任务模型

*/

class Task:public Node, public LimitedState{
public:
	Task(){ current_state = 0; };
	~Task();
	CREATE_FUNC(Task);
	bool init();

	void visit(Vec2 vec)override {};

	void acceptTask();
	void completeTask();
	
	void pushEvent(Event event);
	void popEvent();

private:
	char** texture;
	int width, height;
	
	int current_state;
	vector<Event> _event_list;
};
#endif