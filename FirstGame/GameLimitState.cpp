#include "GameLimitState.h"
#include "DataUtils.h"
#include "DispathMessage.h"

GameLimitState* GameLimitState::_instance = nullptr;

GameLimitState* GameLimitState::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new GameLimitState();
		_instance->transState(GAME_STATE_NORMAL);

	}
	return _instance;
}

void GameLimitState::excuteStateAct()
{
	stateControl(GAME_STATE_PAUSE | GAME_STATE_CHAT, MSG_MOVE);
}

void GameLimitState::stateControl( int state, int what)
{
	if(state & getCurrentState() > 0){
		_dispathMessage->sendMsg(Message(
			MSG_STATE_CONTROL,
			nullptr,
			Value(what)
			));
	}
}
