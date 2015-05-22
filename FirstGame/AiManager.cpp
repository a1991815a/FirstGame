#include "AiManager.h"
#include "Actor.h"
#include "CustomUtils.h"
#include "FightSystem.h"

AiManager* AiManager::_instance = nullptr;

AiManager* AiManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new AiManager();
	}
	return _instance;
}

void AiManager::deleteAi( Actor* actor )
{
	for(int i=0;  i < ai_actors.size(); i++){
		if (actor == ai_actors.at(i).actor)
		{
			ai_actors.erase(ai_actors.begin() + i);
			i--;
		}
	}
}

void AiManager::setAi( Actor* actor )
{
	for(int i=0;  i < ai_actors.size(); i++){
		if (actor == ai_actors.at(i).actor)
		{
			return;
		}
	}
	ai_actors.push_back(AiActor(actor));
}

void AiManager::clearDeath()
{
	for(int i=0;  i < ai_actors.size(); i++){
		if (nullptr == ai_actors.at(i).actor)
		{
			ai_actors.erase(ai_actors.begin() + i);
		}
	}
}

void AiManager::searchEnemy( int index)
{
	Actor* actor = getAi(index);
	if(actor == nullptr)
		return;
	Vec2 pos = _customUtils->transGlobalVec2(actor->getParent(), actor->getPos());
	vector<int> camps = _fightSystem->getCamps();
	for (int i = 0; i < camps.size(); i++)
	{
		int& camp = camps.at(i);
		if(camp == actor->getCamp())
			continue;
		vector<Actor*> enemys = _fightSystem->getActorByCamp(camp);
		for (int j = 0; j < enemys.size(); j++)
		{

		}
	}



}
