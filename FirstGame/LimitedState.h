#ifndef __LIMITEDSTATE__
#define __LIMITEDSTATE__
#include "stdafx.h"

typedef void(*stateFunc)(void);

class LimitedState{
public:
	void RegisterFunc(int state, stateFunc func);
	
	void transState(int state);

	void excuteStateAct();

	inline int getCurrentState() const{return CurrentState;};

private:
	int CurrentState;
	map<int,stateFunc> _func_list;
};
#endif