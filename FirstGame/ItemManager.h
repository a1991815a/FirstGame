#ifndef __ITEMMANAGER__
#define __ITEMMANAGER__
#include "stdafx.h"
#include "Armor.h"
#include "Weapon.h"
#include "Material.h"

#define _itemManager ItemManager::getInstance()

class ItemManager{
public:
	static ItemManager* getInstance();
private:
	static ItemManager* _instance;

public:
	Armor* getArmor(int tag);
	Weapon* getWeapon(int tag);
	Material* getMaterial(int tag);

	inline Material getMaterialObj(int tag){ return _materials.at(tag); };
	
private:
	map<int, Armor> _armors;
	map<int, Weapon> _weapons;
	map<int, Material> _materials;
};
#endif