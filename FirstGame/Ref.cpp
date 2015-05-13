#include "Ref.h"
#include "MemoryManager.h"

const void Ref::autorelease()
{
	_memoryManager->getCurrentPool()->push(this);
}

const void Ref::release()
{
	referenceCount--;
}

const void Ref::retain()
{
	referenceCount++;
}

Ref::Ref()
{
	referenceCount = 0;
}
