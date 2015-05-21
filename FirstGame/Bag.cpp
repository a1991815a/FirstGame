#include "Bag.h"
#include "header.h"

void Bag::putItem(Item* item, int num /*= 1*/)
{
	for (int i = 0; i < item_list.size(); i++)
	{
		if (item_list.at(i).item == item)
		{
			item_list.at(i).num += num;
			return;
		}
	}
	BagItem bi(item);
	bi.num += num - 1;
	item_list.push_back(bi);
}

Item* Bag::takeItem(int index)
{
	Item* item = item_list.at(index).item;
	if (--item_list.at(index).num <= 0)
	{
		item_list.erase(item_list.begin() + index);
	}

	return item;
}

void Bag::deleteItem(int index)
{
	Item* item = item_list.at(index).item;
	if (--item_list.at(index).num <= 0)
	{
		item_list.erase(item_list.begin() + index);
	}
}

Bag::~Bag()
{
	for (int i = 0; i < item_list.size(); i++)
	{
		BagItem& bagitem = item_list.at(i);
		SAFE_DELETE(bagitem.item);
	}
	item_list.clear();
}
