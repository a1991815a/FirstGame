#ifndef __WEAPON__
#define __WEAPON__
#include "Equipment.h"

class Weapon: public Equipment{
public:
	CREATE_FUNC(Weapon);
	bool init(){ return true; };

	Weapon():Equipment(Node_Weapon){ _attack = 0; };
	Weapon(string name, int tag, int attack);
	inline int getAttack() const { return _attack; }
	inline void setAttack(int val) { _attack = val; }
private:
	int _attack;
};
#endif