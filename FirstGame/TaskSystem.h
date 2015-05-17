#ifndef __TASKSYSTEM__
#define __TASKSYSTEM__
#include "Message.h"
#include "Task.h"

#define _taskSystem TaskSystem::getInstance()

class TaskSystem{
public:
	static TaskSystem* getInstance();
private:
	static TaskSystem* _instance;

public:
	bool acceptTask(int task_id);

	bool completeTask(int task_id);

	void pushTask(Task task);
	void deleteTask(string name);
	Task& getTask(string name);

private:
	bool acceptTaskCallback(Message msg);
	bool completeTaskCallback(Message msg);

	map<string, Task> task_list;
};
#endif