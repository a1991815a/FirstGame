#ifndef __MEMORYPOOL__
#define __MEMORYPOOL__
#include "stdafx.h"
class Ref;

//�ڴ��

class MemoryPool{
public:
	MemoryPool();		//����new!

	const void clear();

	void push(Ref* ref);

	~MemoryPool();
private:
	vector<Ref*> ref_list;
};
#endif