#include "Armor.h"

Armor::Armor(string name, int tag, int defence)
	: Equipment(name,tag, Node_Armor)
{
	_defence = defence;
}
