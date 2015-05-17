#ifndef __ACTOR__
#define __ACTOR__
#include "stdafx.h"
#include "Sprite.h"

class Weapon;
class Armor;

//hp, attack, defence, weapon, armor

class Actor: public Sprite{
public:
	void init(int hp, int attack, int defence);

	inline Weapon* getWeapom() const { return _weapon; }
	inline void setWeapom(Weapon* val) { _weapon = val; }
	inline Armor* getArmor() const { return _armor; }
	inline void setArmor(Armor* val) { _armor = val; }

	inline int getHp() const { return _hp; }
	inline void setHp(int val) { _hp = val; }

	int getAttack() const; //{ return _attack; }
	void setAttack(int val) { _attack = val; }

	int getDefence() const; //{ return _defence; }
	inline void setDefence(int val) { _defence = val; }
private:
	int _hp;
	int _attack;
	int _defence;
	Weapon* _weapon;
	Armor* _armor;
};

#endif