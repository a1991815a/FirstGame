#include "LimitedState.h"


LimitedState::LimitedState()
{
	CurrentState = 0;
}

void LimitedState::transState( int state )
{
	CurrentState = state;
}
