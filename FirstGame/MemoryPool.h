#ifndef __MEMORYPOOL__
#define __MEMORYPOOL__
#include "stdafx.h"
class Ref;

//ÄÚ´æ³Ø

class MemoryPool{
public:
	MemoryPool();		//²»ÄÜnew!

	const void clear();

	void push(Ref* ref);

	~MemoryPool();
private:
	vector<Ref*> ref_list;
};
#endif