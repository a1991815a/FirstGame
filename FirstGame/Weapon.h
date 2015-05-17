#ifndef __WEAPON__
#define __WEAPON__
#include "Item.h"

class Weapon: public Item{
public:
	Weapon(string name, int price, int durable, int attack);
	inline int getAttack() const { return _attack; }
	inline void setAttack(int val) { _attack = val; }

	static Weapon getWeapon(int tag);
private:
	int _attack;
};
#endif