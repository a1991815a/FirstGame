#ifndef __ITEMMANAGER__
#define __ITEMMANAGER__
#include "stdafx.h"
#include "Armor.h"
#include "Weapon.h"

class ItemManager{
public:
	static ItemManager* getInstance();
private:
	static ItemManager* _instance;

public:

private:
	map<int, Armor> _armors;
	map<int, Weapon> _weapons;

};
#endif