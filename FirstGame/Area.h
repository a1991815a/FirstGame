#ifndef __AREA__
#define __AREA__
#include "stdafx.h"
#include "Node.h"
#include "Script.h"

class Area: public Node{
public:
/*	virtual void trigger();*/

	void pushPos(Vec2 pos);
	
private:
	vector<Vec2> pos_list;
};

#endif