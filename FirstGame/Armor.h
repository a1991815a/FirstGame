#ifndef __ARMOR__
#define __ARMOR__
#include "Equipment.h"


class Armor: public Equipment{
public:
	CREATE_FUNC(Armor);
	bool init(){ return true; };

	Armor() :Equipment(Node_Armor){ _defence = 0; };
	Armor(string name, int tag, int defence);
	inline int getDefence() const { return _defence; }
	inline void setDefence(int val) { _defence = val; }
private:
	int _defence;
};
#endif