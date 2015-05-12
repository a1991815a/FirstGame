#ifndef __MESSAGE__
#define __MESSAGE__
#include "stdafx.h"
#include "Ref.h"
#include "header.h"

//消息模型

class Message{
public:
	Message(){};

	Message(int msg, Ref* param);

	inline int getMsg() const { return msg; }
	inline void setMsg(int val) { msg = val; }

	inline Ref* getParam() const { return mParam; }
	inline void setParam(Ref* val) { mParam = val; }

	inline vec2 getPos() const { return pos; }
	inline void setPos(int x, int y) { pos.x = x; pos.y = y; }
private:
	int msg;
	vec2 pos;
	Ref* mParam;
};
#endif