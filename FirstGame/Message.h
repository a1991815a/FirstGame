#ifndef __MESSAGE__
#define __MESSAGE__
#include "stdafx.h"
#include "Ref.h"
#include "header.h"
#include "Value.h"

//消息模型

class Message{
public:
	Message(){};

	Message(int msg, Ref* param);

	Message(int msg, Ref* param, Value value);


	inline int getMsg() const { return msg; }
	inline void setMsg(int val) { msg = val; }

	inline Ref* getParam() const { return mParam; }
	inline void setParam(Ref* val) { mParam = val; }

	inline Value getValue() const { return _value; }
	inline void setValue(Value val) { _value = val; }
private:
	int msg;
	Ref* mParam;
	Value _value;
};
#endif