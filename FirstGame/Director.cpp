#include "Director.h"
#include "MemoryManager.h"
#include "Control.h"
#include "DispathMessage.h"
#include "SimplePhysicsEngine.h"
#include "RenderEngine.h"

extern void GameMain();

Director* Director::_instance = nullptr;

Director::Director()
{
	CurrentScene = nullptr;
}

Director* Director::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Director();
	}
	return _instance;
}

void Director::mainloop()
{
	while(true){
		_control->getCh();
		_simplePhysicsEngine->CollisionCheck();
		_dispathMessage->dispathMessage();
		_renderEngine->clear();



		
		_renderEngine->readyBuf();
		_renderEngine->RenderAll();
		_memoryManager->getCurrentPool()->clear();
	}
}

void Director::initAll()
{
	GameMain();
}

void Director::setScene(Scene* scene)
{
	if(CurrentScene != nullptr)
		CurrentScene->release();
	CurrentScene = scene;
	CurrentScene->retain();
}

Scene* Director::getCurrentScene() const
{
	return CurrentScene;
}
