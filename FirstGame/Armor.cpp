#include "Armor.h"

Armor::Armor(string name, int price, int durable, int defence)
	:Item(name, price, durable)
{
	_defence = defence;
}

Armor Armor::getArmor(int tag)
{
	Armor* armor = dynamic_cast<Armor*>(Item::item_list.at(tag));
	return *armor;
}
