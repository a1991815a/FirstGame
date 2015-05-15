#include "Weapon.h"
#include "Actor.h"
#include "DispathMessage.h"

void Weapon::attackObj( Actor* node )
{
	_dispathMessage->sendMsg(Message(MSG_FIGHT_ATTACK, node, Value(_attack)));
}
