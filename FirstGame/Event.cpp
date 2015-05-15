#include "Event.h"
#include "OnOffSystem.h"

void Event::setCondition( bool isStatic,int index )
{
	if(isStatic){
		_onOffSystem->setOnOff(index,false);
		onoff_index_list.push_back(index);
		static_onoff = true;
	}else{
		switch(index){
		case 0:
			_onoff.A = false;
			break;
		case 1:
			_onoff.B = false;
			break;
		case 2:
			_onoff.C = false;
			break;
		case 3:
			_onoff.D = false;
			break;
		default:
			break;
		}
	}
}

bool Event::getCondition() const
{
	bool end = true;
	if(static_onoff)
		for(int i = 0; i < onoff_index_list.size(); i++){
			end = end && _onOffSystem->getOnOff(onoff_index_list.at(i));
		}
	end = end && _onoff.A && _onoff.B && _onoff.C && _onoff.D;
	return end;
}

Event::Event()
{
	_onoff = OnOff();
	static_onoff = false;
	event_id = 0;
	this->autorelease();
}

void Event::addSystem()
{

}
