#include "TimerManager.h"

TimerManager* TimerManager::_instance = nullptr;

TimerManager* TimerManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new TimerManager();
		_instance->start_time = _instance->before_time = GetTickCount();
	}
	return _instance;
}

long TimerManager::getDelta()
{
	long dt = cur_time - before_time;
	return dt;
}

long TimerManager::getDeltaFromStart()
{
	return GetTickCount() - start_time;
}

void TimerManager::setTime()
{
	cur_time = GetTickCount();
}

void TimerManager::resetTime()
{
	before_time = cur_time;
}

