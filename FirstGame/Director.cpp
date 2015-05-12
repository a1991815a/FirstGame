#include "Director.h"
#include "MemoryManager.h"

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

	_memoryManager->getCurrentPool()->clear();
}

void Director::setScene(Scene* scene)
{
	CurrentScene = scene;
}
