#include "SimplePhysicsEngine.h"
#include "Node.h"
#include "DispathMessage.h"

SimplePhysicsEngine* SimplePhysicsEngine::_instance = nullptr;

SimplePhysicsEngine* SimplePhysicsEngine::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new SimplePhysicsEngine();
	}
	return _instance;
}

void SimplePhysicsEngine::check(Node* node)
{
	for (int i = 0; i < _rigidBodys.size(); i++)
	{
		Body& body = _rigidBodys.at(i);
		if (node == body.node)
			continue;
		if (node->getPos() == body.node->getPos())
		{
			if (body.type == RigidBody)
				node->resetPos();
			excuteFunc(node, body.node);
			break;
		}
	}
}

void SimplePhysicsEngine::excuteFunc(Node* node_1, Node* node_2)
{
	for (int i = 0; i < _func_list.size(); i++)
	{
		if (_func_list.at(i)(node_1, node_2))
		{
			return;
		}
	}
}

void SimplePhysicsEngine::setBody( Node* node, BodyType type )
{
	Body body(node, type);
	_rigidBodys.push_back(body);
}