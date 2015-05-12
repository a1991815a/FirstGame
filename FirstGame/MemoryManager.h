#ifndef __MEMORYMANAGER__
#define __MEMORYMANAGER__
#include "stdafx.h"
#include "MemoryPool.h"

//�ڴ������

#define _memoryManager MemoryManager::getInstance()

class MemoryManager{
public:
	static MemoryManager* getInstance();
	static void destroyInstance();
private:
	static MemoryManager* _instance;

public:
	inline MemoryPool* getCurrentPool() const{return CurrentPool;};
	void push(MemoryPool& pool);
	MemoryPool& pop();
private:
	MemoryManager();
	~MemoryManager();

private:
	vector<MemoryPool*> pool_list;
	MemoryPool* CurrentPool;
	MemoryPool defaultPool;
};
#endif