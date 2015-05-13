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

void DispathMessage::sendMsg( Message msg )
{
	_messages.push_back(msg);
}

void DispathMessage::registerFunc( msgFunc func )
{
	_func.push_back(func);
}

void DispathMessage::dispathMessage()
{
	for (int i=0; i < _messages.size(); i++)
	{
		const Message& msg = _messages.at(i);
		for (int j=0; j<_func.size(); j++)
		{
			const msgFunc& func = _func.at(j);
			if (func(msg))
			{
				_messages.erase(_messages.begin()+i);
				i--;
				break;
			}
		}
	}
	_messages.clear();
}

