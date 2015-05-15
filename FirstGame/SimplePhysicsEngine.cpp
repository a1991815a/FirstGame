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

void SimplePhysicsEngine::CollisionCheck()
{
	for (int i = 0; i < _rigidBodys.size(); i++)
	{
		Node*& body_1 = _rigidBodys.at(i);
		for (int j = 0; j < _rigidBodys.size(); j++)
		{
			if (i == j)
				continue;
			Node*& body_2 = _rigidBodys.at(i);

			if (body_1->getPos() == body_2->getPos())
			{
				if(body_1->getTag() == PLAYER_ACTOR)
					body_1->resetPos();
				if(body_2->getTag() == PLAYER_ACTOR)
					body_2->resetPos();
				_dispathMessage->sendMsg(
					Message(MSG_COLLISION,
					new collsitionModel(body_1, body_2)));
			}
		}
	}
}

void SimplePhysicsEngine::setBody( Node* node, BodyType type )
{
	switch(type){
	case RigidBody:
		_rigidBodys.push_back(node);
		break;
	case DownBody:
		_downBodys.push_back(node);
		break;
	default:
		break;
	}
	
	
}

SimplePhysicsEngine::collsitionModel::collsitionModel(Node* n1, Node* n2)
{
	this->autorelease();
	node_1 = n1;
	node_2 = n2;
}
