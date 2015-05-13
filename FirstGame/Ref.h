#ifndef __REF__
#define __REF__
#include "stdafx.h"

//基础类，用于内存管理

class Ref{
public:
	Ref();
	const void autorelease();
	const void release();
	const void retain();

	virtual int getRefCount(){return referenceCount;};

	virtual ~Ref(){};
private:
	short referenceCount;

	friend class MemoryPool;
};
#endif