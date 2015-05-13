#ifndef __SIMPLEPHYSICSENGINE__
#define __SIMPLEPHYSICSENGINE__
#include "stdafx.h"
#include "Ref.h"

class Node;

#define _simplePhysicsEngine SimplePhysicsEngine::getInstance()

class SimplePhysicsEngine{
public:
	static SimplePhysicsEngine* getInstance();
private:
	static SimplePhysicsEngine* _instance;

public:
	void CollisionCheck();

	void setBody(Node* node);

	class collsitionModel: public Ref{
	public:
		collsitionModel(Node* n1, Node* n2);
		Node* node_1;
		Node* node_2;
	};
private:
	vector<Node*> _rigidBodys;
};
#endif