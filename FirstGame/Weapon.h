#ifndef __WEAPON__
#define __WEAPON__
#include "Item.h"
class Actor;

class Weapon: public Item{
public:
	Weapon(){};
	Weapon(int attack, int hp, int money)
		:Item(hp, money){
		_attack = attack;
	};

	inline int getAttack() const { return _attack; }
	inline void setAttack(int val) { _attack = val; }

	void attackObj(Actor* node);
private:
	int _attack;
};
#endif