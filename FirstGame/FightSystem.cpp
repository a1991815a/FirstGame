#include "FightSystem.h"
#include "DispathMessage.h"
#include "Actor.h"
#include "TextOutUtils.h"
#include "Monster.h"

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
	Monster* monster = dynamic_cast<Monster*>(msg.getParam());
	DEBUG_STRING(!monster, "FightSystem, monster空指针异常！");
	
	
}

void FightSystem::fight(Monster* monster)
{

}

void FightSystem::attack(Actor* attacker, Actor* defencer)
{
	int attacker_ap = attacker->getAttack();
	int defencer_df = defencer->getDefence();

	int sub_hp = attacker_ap - defencer_df;
	if (sub_hp < 0)
		sub_hp = 0;

	defencer->setHp(defencer->getHp() - sub_hp);

	showSubText("%s受到攻击，损失hp%d", defencer->getName().c_str(), sub_hp);

}

bool FightSystem::fightAttack(Message msg)
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
	showSubText("%s 受到攻击！，失去hp: %d \n", actor->getName(), sub_hp);
	return true;
}

bool FightSystem::fightEnd( Message msg )
{
	if(msg.getMsg() != MSG_FIGHT_END)
		return false;


}
