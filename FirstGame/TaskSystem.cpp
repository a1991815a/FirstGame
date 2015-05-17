#include "TaskSystem.h"
#include "DispathMessage.h"

TaskSystem* TaskSystem::_instance = nullptr;

TaskSystem* TaskSystem::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new TaskSystem();
		_dispathMessage->registerFunc(CCALLBACK_1(
			TaskSystem::acceptTaskCallback, _instance));
		_dispathMessage->registerFunc(CCALLBACK_1(
			TaskSystem::completeTaskCallback, _instance));
	}
	return _instance;
}

bool TaskSystem::acceptTaskCallback( Message msg )
{
	if(msg.getMsg() != MSG_TASK_ACCEPT)
		return false;
}

bool TaskSystem::acceptTask(int task_id){
	return false;
}

bool TaskSystem::completeTaskCallback(Message msg)
{
	if(msg.getMsg() != MSG_TASK_COMPLETE)
		return false;

}

bool TaskSystem::completeTask(int task_id){

	return false;
}

void TaskSystem::pushTask(Task task)
{
	task_list.insert(map<string, Task>::value_type(task.getName(), task));
}

void TaskSystem::deleteTask(string name)
{
	if (task_list.find(name) == task_list.end())
	{
		return;
	}
	task_list.erase(name);
}

Task& TaskSystem::getTask(string name)
{
	return task_list.at(name);
}
