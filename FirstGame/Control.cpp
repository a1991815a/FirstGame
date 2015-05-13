#include "Control.h"
#include <conio.h>
#include "DispathMessage.h"
#include "Message.h"
#include "header.h"
#include "Value.h"

Control* Control::_instance = nullptr;

Control* Control::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Control();
	}
	return _instance;
}

void Control::getCh()
{
	char _char = _getch();
	_dispathMessage->sendMsg(Message(MSG_OPERATE_KEY, nullptr, Value(_char)));
}





