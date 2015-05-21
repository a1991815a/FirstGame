#include "GameManager.h"
#include "Director.h"
#include "GuiManager.h"

#define  KEY(A) (int)A

GameManager* GameManager::_instance = nullptr;

GameManager* GameManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new GameManager();
	}
	return _instance;
}

Player* GameManager::getPlayer()
{
	return _director->getPlayer();
}

void GameManager::processControl()
{
	int key = -1;
	_guiManager->MenuUI(&key);
	switch (key)
	{
	case KEY('1'):
		while (true)
		{
			if (_guiManager->LoginUI(&key)){
				_guiManager->SuccessUI();
				break;
			}
			else
			{
				_guiManager->FailureUI();
				_guiManager->RepeatUI(&key);
				if (key == KEY('2'))
				{
					processControl();
				}
			}
		}
		break;
	case KEY('2'):
		while (true)
		{
			if (_guiManager->RegisterUI(&key)){
				_guiManager->SuccessUI();
				break;
			}
			else
			{
				_guiManager->FailureUI();
				_guiManager->RepeatUI(&key);
				if (key == KEY('2'))
				{
					processControl();
				}
			}
		}
		
		break;
	default:
		processControl();
		break;
	}
	_guiManager->GameInitUI(&key);
	_guiManager->GameStartUI(&key);
	_guiManager->GameFreeUI(&key);
}

