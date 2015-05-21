#include "Actor.h"

void Actor::init(int hp, int attack, int defence)
{
	_hp = hp;
	_attack = attack;
	_defence = defence;
}

int Actor::getAttack() const
{
	return _attack + _weapon.getAttack();
}

int Actor::getDefence() const
{
	return _defence + _armor.getDefence();
}
