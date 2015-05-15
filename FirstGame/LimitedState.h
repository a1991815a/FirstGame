#ifndef __LIMITEDSTATE__
#define __LIMITEDSTATE__
#include "stdafx.h"
#include "CALLBACK_1.h"

typedef std::function<void(void)> stateFunc;

class LimitedState{
public:
	LimitedState();
	
	void transState(int state);

	inline int getCurrentState() const{return CurrentState;};

private:
	int CurrentState;
};
#endif