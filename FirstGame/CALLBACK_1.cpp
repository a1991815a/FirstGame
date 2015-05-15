#include "CALLBACK_1.h"

msgFunc CALLBACK_1::getCallBack_1()
{
	return CCALLBACK_1(CALLBACK_1::callback_1, this);
}
