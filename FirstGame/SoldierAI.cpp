#include "SoldierAI.h"
#include "Actor.h"
#include "DispathMessage.h"
#include "Message.h"

SoldierAI* SoldierAI::_instance = nullptr;

SoldierAI* SoldierAI::getInstance()
{
	if (_instance == nullptr){
		_instance = new SoldierAI();
	}
	return _instance;
}

void SoldierAI::setAi(Actor* actor)
{
	ai_actors.push_back(actor);
	actor->retain();
}

void SoldierAI::clear()
{
	for (int i = 0; i < ai_actors.size(); i++)
	{
		ai_actors.at(i)->release();
	}
	ai_actors.clear();
}

void SoldierAI::excuteAi()
{
	for (int i = 0; i < ai_actors.size(); i++)
	{
		_dispathMessage->sendMsg(Message(
			MSG_MOVE,
			ai_actors.at(i),
			Value((int)MoveObj::MoveDown)
			));
	}
}

