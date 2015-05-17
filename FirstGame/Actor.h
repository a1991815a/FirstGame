#ifndef __ACTOR__
#define __ACTOR__
#include "Weapon.h"
#include "Sprite.h"
#include "Armor.h"

class Actor: public Sprite{
public:
	Actor(){
		_hp = 0;
		_attack = 0;
		_defence = 0;
		_level = 0;
	};

	inline int getHp() const { return _hp; }
	inline void setHp(int val) { _hp = val; }
	inline int getAttack() const { return _attack + weapon.getAttack(); }
	inline void setAttack(int val) { _attack = val; }
	inline int getDefence() const { return _defence + armor.getDefence(); }
	inline void setDefence(int val) { _defence = val; }
	inline int getLevel() const { return _level; }
	inline void setLevel(int val) { _level = val; }

	inline Weapon getWeapon() const { return weapon; }
	inline void setWeapon(Weapon val) { weapon = val; }

	inline Armor getArmor() const { return armor; }
	inline void setArmor(Armor val) { armor = val;}

private:
	int _hp;
	int _attack;
	int _defence;
	int _level;

	Weapon weapon;
	Armor armor;
};
#endif