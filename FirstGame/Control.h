#ifndef __CONTROL__
#define __CONTROL__
#include "stdafx.h"
#include "Message.h"
#include "CALLBACK_1.h"

#define _control Control::getInstance()

class Control: public CALLBACK_1{
public:
	static Control* getInstance();
private:
	static Control* _instance;

public:
	void getCh();

private:
	virtual bool callback_1(Message msg) override;

	bool controlMove(Message msg);
};
#endif