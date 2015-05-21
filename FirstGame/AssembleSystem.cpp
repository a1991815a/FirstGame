#include "AssembleSystem.h"
#include "Item.h"
#include "ItemManager.h"

AssembleSystem* AssembleSystem::_instance = nullptr;

AssembleSystem* AssembleSystem::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new AssembleSystem();
	}
	return _instance;
}

bool AssembleSystem::assembleEquip(Bag& bag, Equipment* item)
{
	bool end = true;
	vector<int> needM = item->getNeedM();
	for (int i = 0; i < needM.size(); i++)
	{
		Material obj = _itemManager->getMaterialObj(needM.at(i));
		end = end && isExist(bag, obj);
	}
	return end;
}

bool AssembleSystem::isExist(Bag& bag, int tag, int type)
{
	Item item("", tag, type);
	return isExist(bag, item);
}

bool AssembleSystem::isExist(Bag& bag, Item item)
{
	vector<BagItem> item_list = bag.getAllItem();
	for (int i = 0; i < item_list.size(); i++)
	{
		if (item == *item_list.at(i).item){
			return true;
		}
	}
}

