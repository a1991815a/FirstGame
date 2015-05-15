#ifndef __TASK__
#define __TASK__
#include "stdafx.h"
#include "Event.h"
#include "LimitedState.h"

class Task: public Event,public LimitedState{
public:
	Task(){};
	CREATE_FUNC(Task);
	bool init();
	virtual void trigger() override;


private:
	vector<string> _text_list;
};
#endif