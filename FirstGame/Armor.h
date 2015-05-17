#ifndef __ARMOR__
#define __ARMOR__
#include "Item.h"

class Armor: public Item{
public:
	Armor(){};
	Armor(string name, int hp, int defence, int money)
		:Item(name, hp, money)
	{
		_defence = defence;
	}

	inline int getDefence() const { return _defence; }
	inline void setDefence(int val) { _defence = val; }

private:
	int _defence;
};
#endif