#ifndef __CALLBACK_1__
#define __CALLBACK_1__
#include "stdafx.h"
#include "Message.h"

typedef std::function<bool(Message)> msgFunc;

#define CCALLBACK_0(FUNC,INSTANCE) std::bind(&FUNC,INSTANCE)
#define CCALLBACK_1(FUNC,INSTANCE) std::bind(&FUNC,INSTANCE, std::placeholders::_1)
#define CCALLBACK_2(FUNC,INSTANCE) std::bind(&FUNC,INSTANCE, std::placeholders::_1, std::placeholders::_2)
#define CCALLBACK_3(FUNC,INSTANCE) std::bind(&FUNC,INSTANCE, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)
#define CCALLBACK_4(FUNC,INSTANCE) std::bind(&FUNC,INSTANCE, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)
#define CCALLBACK_5(FUNC,INSTANCE) std::bind(&FUNC,INSTANCE, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5)

class CALLBACK_1{
public:
	msgFunc getCallBack_1();
	
protected:
	CALLBACK_1(){};
	virtual bool callback_1(Message msg) = 0;
};
#endif