#ifndef __SIMPLEPHYSICSENGINE__
#define __SIMPLEPHYSICSENGINE__
#include "stdafx.h"
#include "Ref.h"
#include "CALLBACK_1.h"

class Node;

#define _simplePhysicsEngine SimplePhysicsEngine::getInstance()
#define addBindFunc(func,instance) addFunc(std::bind(&func,instance,std::placeholders::_2));

enum BodyType{
	RigidBody, DownBody, upBody,unknowType
};
struct Body
{
	Body(){ type = unknowType; };
	Body(Node* _node, BodyType _type){ node = _node; type = _type; };
public:
	Node* node;
	BodyType type;
};

typedef std::function<bool(Node*, Node*)> PhysicsFunc;

class SimplePhysicsEngine{
public:
	static SimplePhysicsEngine* getInstance();
private:
	static SimplePhysicsEngine* _instance;

public:
	void check(Node* node);

	void excuteFunc(Node* node_1, Node* node_2);

	void setBody(Node* node, BodyType type);

	inline void addFunc(PhysicsFunc func){ _func_list.push_back(func); };

private:
	vector<Body> _rigidBodys;
	vector<PhysicsFunc> _func_list;
};

#endif