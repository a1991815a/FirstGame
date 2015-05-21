#include "GuiManager.h"
#include "UserManager.h"
#include "Director.h"
#include "Bag.h"
#include "Player.h"
#include "NpcSoldier.h"

GuiManager* GuiManager::_instance = nullptr;

GuiManager* GuiManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new GuiManager();
	}

	return _instance;
}

void GuiManager::MenuUI(int* key)
{
	clear();
	cout << "1:登陆" << endl;
	cout << "2:注册" << endl;
	*key = getKey();
}

bool GuiManager::LoginUI(int* key)
{
	clear();
	bool end = _userManager->login();
	return end;
}

bool GuiManager::RegisterUI(int* key)
{
	clear();
	bool end = _userManager->registerUser();
	return end;
}

void GuiManager::GameStartUI(int* key)
{
	clear();
	cout << "　　　　　　　　　　　　　　　　工匠坊" << endl;
	cout << "游戏介绍:";
	cout << "你不是一个战士，你必须雇佣随从保护自己和村庄。"
		<< endl;
	cout << "自由活动时间可以外出狩猎获得素材，\
						然后打造出需要的武器。"
						<< endl;
	cout << "而怪物进攻时间便是检验你工匠造武能力的时刻，把你制作出的武器交给\
						随从，让他们为你保护村庄吧。" << endl;
	*key = getKey();
}

void GuiManager::GameInitUI(int* key){
	defence_scene = Scene::create();
	defence_scene->retain();
	defence_scene->setName("defenceScene");
	free_scene = Scene::create();
	free_scene->retain();
	free_scene->setName("freeScene");
	_director->initAll();
	*key = -1;
}

void GuiManager::GameFreeUI(int* key)
{
	*key = -1;
	_director->setScene(free_scene);
}

void GuiManager::GameDefenceUI(int* key)
{
	*key = -1;
	_director->setScene(defence_scene);
}

void GuiManager::BagUI(int* key, Bag* bag)
{
	clear();
	string bag_text = "";
	vector<BagItem> bi_list = bag->getAllItem();
	for (int i = 0; i < bi_list.size(); i++)
	{
		BagItem& bag_item = bi_list.at(i);
		bag_text += bag_item.item->getName();
		bag_text += ':';
		char int_text[12];
		sprintf_s(int_text, 12, "%d", bag_item.num);
		bag_text += int_text;
		bag_text += "个   ";
		if (i % 2 == 1)
		{
			bag_text += "\n";
		}
	}
	cout << bag_text.c_str() << endl;
	*key = getKey();
}

void GuiManager::SoldierUI(int* key, Player* player)
{
	clear();
	vector<NpcSoldier*> nc_list = player->getAllSoldier();
	string out_text = "";
	for (int i = 0; i < nc_list.size(); i++)
	{
		char int_text[3];
		sprintf_s(int_text, 3, "%d:", i);

		NpcSoldier* ns = nc_list.at(i);
		if (ns == nullptr)
			continue;

		out_text += int_text;
		out_text += ns->getName();
		out_text += ",";
		char int_text2[128];
		sprintf_s(int_text2, 32, "AP:%d,DF:%d,武器:%s,防具:%s",
			ns->getAttack(), ns->getDefence(), ns->getWeapom().getName().c_str(), ns->getArmor().getName().c_str());
		out_text += "\n";
	}
	cout << out_text.c_str() << endl;
	*key = getKey();
}

void GuiManager::SuccessUI()
{
	cout << "成功！" << endl;
	pause();
}

void GuiManager::FailureUI()
{
	cout << "失败！" << endl;
	pause();
}

void GuiManager::RepeatUI(int* key)
{
	cout << "1:重试" << endl;
	cout << "2:返回" << endl;
	*key = getKey();
}

