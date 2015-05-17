#include "Event.h"
#include "OnOffSystem.h"
#include "EventSystem.h"
#include "Director.h"
#include "Player.h"

void Event::setCondition(bool isStatic, int index)
{
	if (isStatic){
		_onOffSystem->setOnOff(index, false);
		onoff_index_list.push_back(index);
		static_onoff = true;
	}
	else{
		switch (index){
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

bool Event::canTrigger() const
{
	bool isInPos = false;
	for (int i = 0; i < trigger_pos_list.size(); i++)
	{
		if (_director->getPlayer()->getPos() == trigger_pos_list.at(i))
		{
			isInPos = true;
			break;
		}
	}
	if (isInPos == false)
		return false;

	bool condition = true;

	if (static_onoff)
		for (int i = 0; i < onoff_index_list.size(); i++){
			condition = condition && _onOffSystem->getOnOff(onoff_index_list.at(i));
		}
	condition = condition && _onoff.A && _onoff.B && _onoff.C && _onoff.D;
	return condition;
}

Event::Event()
{
	_onoff = OnOff();
	static_onoff = false;
	event_id = 0;
	CurrentState = 0;
	this->autorelease();
}

void Event::addSystem()
{
	_eventSystem->push_back(this);
}

void Event::setOnOff(int index, bool onoff)
{
	switch (index)
	{
	case 0:
		_onoff.A = onoff;
		break;
	case 1:
		_onoff.B = onoff;
		break;
	case 2:
		_onoff.C = onoff;
		break;
	case 3:
		_onoff.D = onoff;
		break;
	default:
		break;
	}

}

