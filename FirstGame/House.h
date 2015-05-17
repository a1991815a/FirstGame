#ifndef __HOUSE__
#define __HOUSE__
#include "Sprite.h"
#include "Weapon.h"
#include "Armor.h"

class House:public Sprite{
public:
	CREATE_FUNC(House);
	bool init();

	void buyWeapon(int index);
	void buyAromor(int index);

private:
	vector<Weapon> _weapons;
	vector<Armor> _armors;
};
#endif