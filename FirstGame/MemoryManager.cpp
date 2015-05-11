#include "MemoryManager.h"

MemoryManager* MemoryManager::_instance = nullptr;

MemoryManager* MemoryManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new MemoryManager();
	}
	return _instance;
}
