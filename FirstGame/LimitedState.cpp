#include "LimitedState.h"

void LimitedState::RegisterFunc( int state, stateFunc func )
{
	_func_list[state] = func;
}

void LimitedState::transState( int state )
{
	CurrentState = state;
}

void LimitedState::excuteStateAct()
{
	stateFunc func = _func_list.at(CurrentState);
	if (func == nullptr)
	{
		return;
	}
	func();
}
