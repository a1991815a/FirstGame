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
		return false;
	}
	return _onoff_list.at(index);
}

void OnOffSystem::deleteOnOff( int index )
{
	_onoff_list.erase(index);
}


