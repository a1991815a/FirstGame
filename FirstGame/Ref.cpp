#include "Ref.h"

const void Ref::autorelease()
{
	referenceCount++;
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
