#include "Player.h"
#include "NpcSoldier.h"
#include "TextOutUtils.h"

bool Player::init()
{
	_level = 0;
	Actor::init(100, 10, 5);
	setCamp(0);
	return true;
}

void Player::addSoldier(int num /*= 1*/)
{
	if (soldier_list.size() + num > MAX_SOLDIER)
	{
		showSubText("士兵达到上限");
	}
	for (int i = 0; i < num; i++)
	{
		NpcSoldier* npc = NpcSoldier::create();
		npc->setName("士兵");
		npc->setCanMove(true);
		npc->setAttack(10);
		npc->setDefence(5);
		npc->setHp(100);
		addChild(npc);
		soldier_list.push_back(npc);
	}
}
