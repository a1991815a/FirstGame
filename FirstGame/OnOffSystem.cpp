#include "OnOffSystem.h"

OnOffSystem* OnOffSystem::_instance = nullptr;

OnOffSystem* OnOffSystem::getInstance()
{
	if(_instance == nullptr){
		_instance = new OnOffSystem();
	}
	return _instance;
}

void OnOffSystem::setOnOff( int index, bool onoff )
{
	_onoff_list[index] = onoff;
}

bool OnOffSystem::getOnOff( int index )
{
	if (_onoff_list.find(index) == _onoff_list.end())
	{
		DEBUG_STRING(true, "警告:没有设置此开关:%d\0", index);
		return false;
	}
	return _onoff_list.at(index);
}

void OnOffSystem::deleteOnOff( int index )
{
	_onoff_list.erase(index);
}


