#ifndef __DISPATHMESSAGE__
#define __DISPATHMESSAGE__
#include "stdafx.h"
#include "Message.h"
#include "CALLBACK_1.h"

//消息分发管理

#define _dispathMessage DispathMessage::getInstance()

class DispathMessage{
public:
	static DispathMessage* getInstance();
private:
	static DispathMessage* _instance;

public:
	void sendMsg(Message msg);

	void registerFunc(msgFunc func);

	void dispathMessage();
	
private:
	vector<Message> _messages;
	vector<msgFunc> _func;

	bool msgDelete(Message msg);
	void deleteMessage(int what);
};
#endif