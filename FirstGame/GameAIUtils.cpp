#include "GameAIUtils.h"

GameAIUtils* GameAIUtils::_instance = nullptr;

GameAIUtils* GameAIUtils::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new GameAIUtils();
	}
	return _instance;
}

