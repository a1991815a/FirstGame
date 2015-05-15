#ifndef __TASKSYSTEM__
#define __TASKSYSTEM__
#include "Message.h"

#define _taskSystem TaskSystem::getInstance()

class TaskSystem{
public:
	static TaskSystem* getInstance();
private:
	static TaskSystem* _instance;

private:
	bool acceptTask(Message msg);
	bool completeTask(Message msg);
};
#endif