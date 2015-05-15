#include "FightSystem.h"
#include "DispathMessage.h"
#include "Actor.h"
#include "TextOut.h"

FightSystem* FightSystem::_instance = nullptr;

FightSystem* FightSystem::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new FightSystem();
		
		_dispathMessage->registerFunc(CCALLBACK_1(FightSystem::fightStart,
			_instance
			));
		_dispathMessage->registerFunc(CCALLBACK_1(FightSystem::fightAttack,
			_instance
			));
		_dispathMessage->registerFunc(CCALLBACK_1(FightSystem::fightEnd,
			_instance
			));
	}
	return _instance;
}

bool FightSystem::fightStart( Message msg )
{
	if(msg.getMsg() != MSG_FIGHT_START)
		return false;


	
}

bool FightSystem::fightAttack( Message msg )
{
	if(msg.getMsg() != MSG_FIGHT_ATTACK)
		return false;
	Actor* actor = dynamic_cast<Actor*>(msg.getParam());
	int attack = msg.getValue().asInt();
	if(actor == nullptr)
		return true;
	int sub_hp = attack - actor->getDefence();
	if(sub_hp < 0)
		sub_hp = 0;
	actor->setHp(actor->getHp() - sub_hp);
	showSubText("%s ÊÜµ½¹¥»÷£¡£¬Ê§È¥hp: %d \n", actor->getName(), sub_hp);
	return true;
}

bool FightSystem::fightEnd( Message msg )
{
	if(msg.getMsg() != MSG_FIGHT_END)
		return false;


}
