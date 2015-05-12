#ifndef __SCENE__
#define __SCENE__
#include "stdafx.h"
#include "Node.h"

class Scene : public Node{
public:
	CREATE_FUNC(Scene);
	virtual bool init();

	Scene();
	virtual ~Scene();
private:
	
};
#endif