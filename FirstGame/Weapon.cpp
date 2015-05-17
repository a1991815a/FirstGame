#include "Weapon.h"

Weapon::Weapon(string name, int price, int durable, int attack)
	:Item(name, price, durable)
{
	_attack = attack;
}

Weapon Weapon::getWeapon(int tag)
{
	Weapon* weapon = dynamic_cast<Weapon*>(Item::item_list.at(tag));
	return *weapon;
}
