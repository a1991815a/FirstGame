#include "Director.h"

Director* Director::_instance = nullptr;

Director* Director::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Director();
	}
	return _instance;
}
