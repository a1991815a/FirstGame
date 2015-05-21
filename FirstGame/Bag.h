#ifndef __BAG__
#define __BAG__
#include "Item.h"

struct BagItem{
public:
	BagItem(Item* item){ this->item = item; num = 1; };
	Item* item;
	int num;
};

class Bag{
public:
	Bag();

	inline vector<BagItem> getAllItem() const { return item_list; }
	void putItem(Item* item, int num = 1);
	inline BagItem getItem(int index)const { return item_list.at(index); };
	Item* takeItem(int index);
	void deleteItem(int index);

	~Bag();
private:
	vector<BagItem> item_list;
};
#endif