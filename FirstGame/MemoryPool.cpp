#include "MemoryPool.h"
#include "Ref.h"
#include "header.h"

const void MemoryPool::clear()
{
	for (int i = 0; i < ref_list.size(); i++)
	{
		Ref*& ref = ref_list.at(i);
		ref->release();
		if (ref->referenceCount <= 0)
		{
			SAFE_DELETE(ref);
			ref_list.erase(ref_list.begin() + i);
			i--;
		}
	}
}

MemoryPool::~MemoryPool()
{
	clear();
	ref_list.clear();
}

MemoryPool::MemoryPool()
{

}
