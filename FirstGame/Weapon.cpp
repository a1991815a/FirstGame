#include "Weapon.h"

Weapon::Weapon(string name, int tag, int attack)
	:Equipment(name, tag, Node_Weapon)
{
	_attack = attack;
}
