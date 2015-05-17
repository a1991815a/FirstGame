#ifndef __AREA__
#define __AREA__
#include "stdafx.h"
#include "Node.h"
#include "Script.h"

class Area: public Node{
public:
	virtual void trigger();

	void pushPos(Vec2 pos);

	void pushScript(Script script);
	
private:
	vector<Vec2> pos_list;
	vector<Script> script_list;
};

#endif