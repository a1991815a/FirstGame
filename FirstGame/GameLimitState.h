#ifndef __GAMELIMITSTATE__
#define __GAMELIMITSTATE__
#include "stdafx.h"
#include "LimitedState.h"

//游戏有限状态机引擎

#define _gameLimitState GameLimitState::getInstance()

class GameLimitState: public LimitedState{
public:
	static GameLimitState* getInstance();
private:
	static GameLimitState* _instance;

public:
	void excuteStateAct();

	void stateControl(int state, int what);
};
#endif