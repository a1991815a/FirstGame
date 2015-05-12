#include "MemoryManager.h"
#include "header.h"
#include "MemoryPool.h"

MemoryManager* MemoryManager::_instance = nullptr;

void MemoryManager::push(MemoryPool& pool)
{
	pool_list.push_back(&pool);
	CurrentPool = pool_list.back();
}

MemoryPool& MemoryManager::pop()
{
	MemoryPool*& pool = pool_list.back();
	pool_list.pop_back();
	return *pool;
}

MemoryManager::MemoryManager()
{
	pool_list.push_back(&defaultPool);
	CurrentPool = pool_list.back();
}

MemoryManager::~MemoryManager()
{
	for (int i = 0; i < pool_list.size(); i++)
	{
		MemoryPool*& pool = pool_list.at(i);
		SAFE_DELETE(pool);
	}
	pool_list.clear();
}

MemoryManager* MemoryManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new MemoryManager();
	}
	return _instance;
}

void MemoryManager::destroyInstance()
{
	SAFE_DELETE(_instance);
}
