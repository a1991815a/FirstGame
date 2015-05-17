#ifndef __ARMOR__
#define __ARMOR__
#include "Item.h"

class Armor: public Item{
public:
	Armor(string name, int price, int durable, int defence);
	inline int getDefence() const { return _defence; }
	inline void setDefence(int val) { _defence = val; }
	static Armor getArmor(int tag);
private:
	int _defence;
};
#endif