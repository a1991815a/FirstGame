#include "Message.h"

Message::Message(int msg, Ref* param)
{
	this->msg = msg;
	this->mParam = param;
	this->_value = Value();
}

Message::Message(int msg, Ref* param, Value value)
{
	this->msg = msg;
	this->mParam = param;
	this->_value = value;
}
