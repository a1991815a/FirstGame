#include "Item.h"

Item::Item(string name, int tag, int type)
{
	_name = name;
	_tag = tag;
	_type = type;
}

bool Item::operator==(Item item)
{
	if (getType() == item.getType() && _tag == item._tag)
	{
		return true;
	}
	return false;
}
