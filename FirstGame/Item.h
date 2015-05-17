#ifndef __ITEM__
#define __ITEM__
#include "stdafx.h"

class Item{
public:
	Item(string name, int price, int durable);
	inline std::string getName() const { return _name; }
	inline void setName(std::string val) { _name = val; }
	inline int getPrice() const { return _price; }
	inline void setPrice(int val) { _price = val; }
	inline int getDurable() const { return _durable; }
	inline void setDurable(int val) { _durable = val; }
	inline void subDurable(int val) { _durable -= val; }

	virtual ~Item(){};
protected:
	static map<int, Item*> item_list;
private:
	string _name;
	int _price;
	int _durable;
};
#endif