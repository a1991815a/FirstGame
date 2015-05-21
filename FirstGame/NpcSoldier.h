#ifndef __NPCSOLDIER__
#define __NPCSOLDIER__
#include "Actor.h"

class NpcSoldier: public Actor{
public:
	CREATE_FUNC(NpcSoldier);
	bool init(){ setCamp(0) ; return true; };
	int getType()const override{ return Node_NpcSoldier; };
private:
	
};
#endif