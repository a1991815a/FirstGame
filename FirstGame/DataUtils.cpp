#include "DataUtils.h"


DataUtils* DataUtils::_instance = nullptr;

DataUtils* DataUtils::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new DataUtils();
	}
	return _instance;
}
