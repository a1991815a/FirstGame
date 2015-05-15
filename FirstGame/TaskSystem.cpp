#include "TaskSystem.h"
#include "DispathMessage.h"

TaskSystem* TaskSystem::_instance = nullptr;

TaskSystem* TaskSystem::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new TaskSystem();
		_dispathMessage->registerFunc(CCALLBACK_1(
			TaskSystem::acceptTask, _instance));
		_dispathMessage->registerFunc(CCALLBACK_1(
			TaskSystem::completeTask, _instance));
	}
	return _instance;
}

bool TaskSystem::acceptTask( Message msg )
{
	if(msg.getMsg() != MSG_TASK_ACCEPT)
		return false;
}

bool TaskSystem::completeTask( Message msg )
{
	if(msg.getMsg() != MSG_TASK_COMPLETE)
		return false;

}
