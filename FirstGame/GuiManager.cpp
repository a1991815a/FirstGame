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
	cout << "1:��½" << endl;
	cout << "2:ע��" << endl;
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
	cout << "��������������������������������������" << endl;
	cout << "��Ϸ����:";
	cout << "�㲻��һ��սʿ��������Ӷ��ӱ����Լ��ʹ�ׯ��"
		<< endl;
	cout << "���ɻʱ�����������Ի���زģ�\
						Ȼ��������Ҫ��������"
						<< endl;
	cout << "���������ʱ����Ǽ����㹤������������ʱ�̣���������������������\
						��ӣ�������Ϊ�㱣����ׯ�ɡ�" << endl;
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
		bag_text += "��   ";
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
		sprintf_s(int_text2, 32, "AP:%d,DF:%d,����:%s,����:%s",
			ns->getAttack(), ns->getDefence(), ns->getWeapom().getName().c_str(), ns->getArmor().getName().c_str());
		out_text += "\n";
	}
	cout << out_text.c_str() << endl;
	*key = getKey();
}

void GuiManager::SuccessUI()
{
	cout << "�ɹ���" << endl;
	pause();
}

void GuiManager::FailureUI()
{
	cout << "ʧ�ܣ�" << endl;
	pause();
}

void GuiManager::RepeatUI(int* key)
{
	cout << "1:����" << endl;
	cout << "2:����" << endl;
	*key = getKey();
}

