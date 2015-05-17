#include "GameManager.h"
#include "Director.h"
#include "Scene.h"
#include "Map.h"
#include "Monster.h"
#include "NpcActor.h"
#include "Player.h"
#include "DispathMessage.h"

GameManager* GameManager::_instance = nullptr;

GameManager* GameManager::getInstance()
{
	if (_instance == nullptr){
		_instance = new GameManager();
	}
	return _instance;
}

Node* GameManager::checkCollision(Vec2 pos)
{
	vector<Node*> rigid_list = _director->getCurrentScene()->getMap()->getRigids();

	for (int i = 0; i < rigid_list.size(); i++)
	{
		Node* node = rigid_list.at(i);
		if (node->getPos() == pos){
			return node;
		}
	}
	return nullptr;
}

Monster* GameManager::checkTouchMonster(Vec2 pos)
{
	vector<Monster*> monster_list = _director->getCurrentScene()->getMap()->getMonsters();

	for (int i = 0; i < monster_list.size(); i++)
	{
		Monster* monster = monster_list.at(i);
		if (monster->getPos() == pos)
		{
			return monster;
		}
	}
	return nullptr;
}

NpcActor* GameManager::checkTouchNpc(Vec2 pos)
{
	vector<NpcActor*> npc_list = _director->getCurrentScene()->getMap()->getNpcs();

	for (int i = 0; i < npc_list.size(); i++)
	{
		NpcActor* npc = npc_list.at(i);
		if (npc->getPos() == pos)
		{
			return npc;
		}
	}
	return nullptr;
}

House* GameManager::checkInHouse(Vec2 pos)
{
	vector<NpcActor*> npc_list = _director->getCurrentScene()->getMap()->getNpcs();

	for (int i = 0; i < npc_list.size(); i++)
	{
		NpcActor* npc = npc_list.at(i);
		if (npc->getPos() == pos)
		{
			return npc;
		}
	}
	return nullptr;
}

void GameManager::trigger()
{
	Vec2 pos = _director->getPlayer()->getPos();
	Node* node = checkCollision(pos);

	if (node){
		_director->getPlayer()->resetPos();
	}

	Monster* monster = checkTouchMonster(pos);
	if (monster){
		_dispathMessage->sendMsg(Message(
			MSG_FIGHT_START,
			monster
			));
	}

	NpcActor* npc = checkTouchNpc(pos);
	if (npc){
		_dispathMessage->sendMsg(Message(
			MSG_NPC_CHAT,
			npc
			));
	}
}

