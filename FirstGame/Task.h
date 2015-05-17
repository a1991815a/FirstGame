#ifndef __TASK__
#define __TASK__
#include "stdafx.h"

class Task{
public:
	inline int getTag() const { return _tag; }
	inline void setTag(int val) { _tag = val; }
private:
	vector<int> accept_condition;
	vector<int> complete_condition;
	int _tag;
};
#endif