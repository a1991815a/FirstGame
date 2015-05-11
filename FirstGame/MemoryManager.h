#ifndef __MEMORYMANAGER__
#define __MEMORYMANAGER__

class MemoryManager{
public:
	static MemoryManager* getInstance();
private:
	static MemoryManager* _instance;
};
#endif