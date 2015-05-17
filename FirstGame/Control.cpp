#include "Control.h"
#include <conio.h>
#include "DispathMessage.h"
#include "Message.h"
#include "header.h"
#include "Value.h"
#include "Director.h"
#include "stdafx.h"
#include "CALLBACK_1.h"

Control* Control::_instance = nullptr;

Control* Control::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Control();
		_dispathMessage->registerFunc(_instance->getCallBack_1());
		_dispathMessage->registerFunc(CCALLBACK_1(
			Control::controlMove,
			_instance
			));
	}
	return _instance;
}

void Control::getCh()
{
	char _char = _getch();
	_dispathMessage->sendMsg(Message(MSG_OPERATE_KEY, nullptr, Value(_char)));
}

bool Control::callback_1(Message msg)
{
	if(msg.getMsg() != MSG_OPERATE_KEY)
		return false;

	Vec2 pos = _director->getPlayer()->getPos();

	switch (msg.getValue().asChar())
	{
	case (int)'w':
		_dispathMessage->sendMsg(Message(
			MSG_MOVE,
			_director->getPlayer(),
			Value((int)MoveObj::MoveUp)));
		break;
	case (int)'s':
		_dispathMessage->sendMsg(Message(
			MSG_MOVE,
			_director->getPlayer(),
			Value((int)MoveObj::MoveDown)));
		break;
	case (int)'a':
		_dispathMessage->sendMsg(Message(
			MSG_MOVE,
			_director->getPlayer(),
			Value((int)MoveObj::MoveLeft)));
		break;
	case (int)'d':
		_dispathMessage->sendMsg(Message(
			MSG_MOVE,
			_director->getPlayer(),
			Value((int)MoveObj::MoveRight)));
		break;
	default:
		break;
	}

	return true;
}

bool Control::controlMove( Message msg )
{
	if(msg.getMsg() != MSG_MOVE)
		return false;

	Node* node = dynamic_cast<Node*>(msg.getParam());

	if(node == nullptr)
	{
		DEBUG_STRING(true, "¿ÕÖ¸ÕëÒì³££¡");
		return false;
	}
	if(!node->getCanMove())
		return true;

	switch(msg.getValue().asInt()){
	case MoveObj::MoveUp:
		node->setPosUp();
		break;
	case MoveObj::MoveDown:
		node->setPosDown();
		break;
	case MoveObj::MoveLeft:
		node->setPosLeft();
		break;
	case MoveObj::MoveRight:
		node->setPosRight();
		break;
	default:
		break;
	}

	return true;
}






