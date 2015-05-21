#ifndef __TIMERMANAGER__
#define __TIMERMANAGER__
#include "stdafx.h"

#define _timerManager TimerManager::getInstance()

class TimerManager{
public:
	static TimerManager* getInstance();
private:
	static TimerManager* _instance;
public:
	long getDelta();

	long getDeltaFromStart();

	void setTime();

	void resetTime();
private:
	long before_time;
	long start_time;
	long cur_time;
};
#endif