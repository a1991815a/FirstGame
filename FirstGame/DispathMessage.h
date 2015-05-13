#ifndef __DISPATHMESSAGE__
#define __DISPATHMESSAGE__
#include "stdafx.h"
#include "Message.h"

//消息分发管理
typedef bool (*msgFunc)(Message msg);

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
};
#endif