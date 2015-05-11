#include "DispathMessage.h"

DispathMessage* DispathMessage::_instance = nullptr;

DispathMessage* DispathMessage::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new DispathMessage();
	}
	return _instance;
}
