#include "ItemManager.h"
#include "stdafx.h"

ItemManager* ItemManager::_instance = nullptr;

ItemManager* ItemManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new ItemManager();
	}
	return _instance;
}

Armor* ItemManager::getArmor(int tag)
{
	Armor* item = Armor::create();
	*item = _armors.at(tag);
	return item;
}

Weapon* ItemManager::getWeapon(int tag)
{
	Weapon* item = Weapon::create();
	*item = _weapons.at(tag);
	return item;

}

Material* ItemManager::getMaterial(int tag)
{
	Material* item = Material::create();
	*item = _materials.at(tag);
	return item;
}