#include "Actor.h"

void Actor::init(int hp, int attack, int defence)
{
	_hp = hp;
	_attack = attack;
	_defence = defence;
}

int Actor::getAttack() const
{
	if (_weapon)
	{
	}
	return _attack;
}

int Actor::getDefence() const
{
	if (_armor)
	{
	}
	return _defence;
}
