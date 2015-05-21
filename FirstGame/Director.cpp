#include "Director.h"
#include "MemoryManager.h"
#include "Control.h"
#include "DispathMessage.h"
#include "SimplePhysicsEngine.h"
#include "RenderEngine.h"
#include "GameLimitState.h"
#include "TimerManager.h"
#include "SoldierAI.h"
#include "GameManager.h"

extern void GameMain();

Director* Director::_instance = nullptr;

Director::Director()
{
	CurrentScene = nullptr;
	_dt = 0;
}

Director* Director::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Director();
	}
	return _instance;
}

void Director::mainloop()
{
	_gameManager->processControl();
	while(true){
		_timerManager->setTime();
		addDt();
		switch (_gameLimitState->getCurrentState())
		{
		case GAME_STATE_NORMAL:
		{
			_renderEngine->clear();
			_control->listenKeyboard();
			_dispathMessage->dispathMessage();
			renderAll();
		}
			break;

		case GAME_STATE_DEFENCE:
		{
			_renderEngine->clear();
//			_control->listenKeyboard();
			_soldierAI->excuteAi();
			_dispathMessage->dispathMessage();
			renderAll();
		}
			break;

		case GAME_STATE_HINT:
		{
			_dispathMessage->dispathMessage();
			renderAll();
			_control->getCh();								//◊Ë»˚
			_renderEngine->clearSideTextBuf();				//«Â≥˝Œƒ±æª∫≥Â«¯
			_renderEngine->clearSubTextBuf();
			_gameLimitState->transState(GAME_STATE_NORMAL);
		}
			break;
		default:
			break;
		}
		_memoryManager->getCurrentPool()->clear();
		_timerManager->resetTime();
	}
}

void Director::initAll()
{
	setFrames(60);
	_timerManager;
	GameMain();
}

void Director::setScene(Scene* scene)
{
	if(CurrentScene != nullptr)
		CurrentScene->release();
	CurrentScene = scene;
	CurrentScene->retain();
}

Player* Director::getPlayer() const
{
	if (CurrentScene == nullptr)
		return nullptr;
	return CurrentScene->getActor();
}

/*
	‰÷»æ
*/
void Director::renderAll()			
{
	if (getDt() >= render_dt)
	{
		_renderEngine->clear();				//«Â≥˛‰÷»æª∫¥Ê
		_renderEngine->readyBuf();			//◊º±∏‰÷»æª∫¥Ê
		_renderEngine->RenderAll();			//‰÷»æ
		resetDt();
	}
}
