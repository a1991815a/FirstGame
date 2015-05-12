#include "SimplePhysicsEngine.h"

SimplePhysicsEngine* SimplePhysicsEngine::_instance = nullptr;

SimplePhysicsEngine* SimplePhysicsEngine::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new SimplePhysicsEngine();
	}
	return _instance;
}
