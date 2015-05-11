#include "FileIO.h"

FileIO* FileIO::_instance = nullptr;

FileIO* FileIO::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new FileIO();
	}
	return _instance;
}


