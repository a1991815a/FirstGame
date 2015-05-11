#include "GameLimitState.h"

GameLimitState* GameLimitState::_instance = nullptr;

GameLimitState* GameLimitState::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new GameLimitState();
	}
	return _instance;
}
