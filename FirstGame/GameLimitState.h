#ifndef __GAMELIMITSTATE__
#define __GAMELIMITSTATE__
#include "stdafx.h"
#include "LimitedState.h"

#define _gameLimitState GameLimitState::getInstance()

class GameLimitState: public LimitedState{
public:
	static GameLimitState* getInstance();
private:
	static GameLimitState* _instance;
};
#endif