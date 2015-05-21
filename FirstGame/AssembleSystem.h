#ifndef __ASSEMBLESYSTEM__
#define __ASSEMBLESYSTEM__
#include "stdafx.h"
#include "Bag.h"
#include "Equipment.h"
#include "Item.h"

class AssembleSystem{
public:
	static AssembleSystem* getInstance();
private:
	static AssembleSystem* _instance;
public:
	bool assembleEquip(Bag& bag, Equipment* item);

	bool isExist(Bag& bag, int tag, int type);

	bool isExist(Bag& bag, Item item);
};
#endif