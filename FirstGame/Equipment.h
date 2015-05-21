#ifndef __EQUIPMENT__
#define __EQUIPMENT__
#include "Item.h"

class Equipment : public Item{
public:
	Equipment(int type):Item(type){};
	Equipment(string name, int tag, int type)
		:Item(name, tag, type){};

	inline vector<int> getNeedM() const { return _need_material; }
	inline void addNeedM(int val) { _need_material.push_back(val); }

private:
	vector<int> _need_material;
};
#endif