#ifndef __SIMPLEPHYSICSENGINE__
#define __SIMPLEPHYSICSENGINE__
#include "stdafx.h"

class SimplePhysicsEngine{
public:
	static SimplePhysicsEngine* getInstance();
private:
	static SimplePhysicsEngine* _instance;

	void CollisionCheck();
};
#endif