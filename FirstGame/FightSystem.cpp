#include "FightSystem.h"
#include "Actor.h"
#include "DispathMessage.h"
#include "TimerManager.h"
#include "stdafx.h"
#include "SimplePhysicsEngine.h"
#include "TextOutUtils.h"
#include "SoldierAI.h"
#include "GameLimitState.h"

extern void GameDefence();
extern void GameNormal();
extern void GameHint();

FightSystem* FightSystem::_instance = nullptr;

FightSystem* FightSystem::getInstance()
{
	if (_instance == nullptr){
		_instance = new FightSystem();
		_simplePhysicsEngine->addFunc(
			CCALLBACK_2(FightSystem::checkAttack, _instance)
			);
	}
	return _instance;
}

FightSystem::FightSystem()
{
	freeAct_time = 5 * 60 * 1000;
	cur_state = 0;
	cur_NO = 1;
}

void FightSystem::attack(Actor* attacker, Actor* defencer)
{
	if (attacker->getCamp() != defencer->getCamp())
	{
		int sub_hp = attacker->getAttack() - defencer->getDefence();
		if (sub_hp < 0)
			sub_hp = 0;
		defencer->setHp(defencer->getHp() - sub_hp);
		showSubText("%s¹¥»÷%s,%sËðÊ§ÁË%dµÄhp!", attacker->getName().c_str(), defencer->getName().c_str(), defencer->getName().c_str(), sub_hp);
	}
}

void FightSystem::freeActStart()
{
	cur_state = GAME_STATE_FREEACT;
	_dispathMessage->sendMsg(Message(
		MSG_FREEACT_START,
		nullptr
		));
	clearEnemy();
	_gameLimitState->transState(GAME_STATE_NORMAL);
	GameNormal();
}

void FightSystem::defenceStart()
{
	cur_state = GAME_STATE_DEFENCE;
// 	_dispathMessage->sendMsg(Message(
// 		MSG_DEFENCE_START,
// 		nullptr
// 		));
	_gameLimitState->transState(GAME_STATE_DEFENCE);
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		Enemy* enemy = Enemy::create();
		*enemy = atk_enemys.at(cur_NO - 1);
		_soldierAI->setAi(enemy);
	}

}

void FightSystem::setFreeActDT(int minutes)
{
	freeAct_time = minutes * 60 * 1000;
}

void FightSystem::timingDt()
{
	cur_dt += _timerManager->getDelta();
}

void FightSystem::addEnemy(int NO, Enemy enemy)
{
	atk_enemys.insert(atk_enemys.begin() + NO - 1,enemy);
}

void FightSystem::createEnemys()
{
	Enemy enemy = atk_enemys.at(cur_NO);
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		Enemy* e_obj = Enemy::create();
		*e_obj = enemy;
		e_obj->retain();
		pushEnemy(e_obj);
	}


}

void FightSystem::clearEnemy()
{
	for (int i = 0; i < cur_enemys.size(); i++)
	{
		Enemy*& enemy = cur_enemys.at(i);
		enemy->release();
	}
	cur_enemys.clear();
	_soldierAI->clear();
}

bool FightSystem::checkAttack(Node* n1, Node* n2)
{
	Actor* attacker = dynamic_cast<Actor*>(n1);
	Actor* defencer = dynamic_cast<Actor*>(n2);
	if (!attacker || !defencer)
		return false;
	attack(attacker, defencer);
	return true;
}
