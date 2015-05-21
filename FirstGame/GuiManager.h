#ifndef __GUIMANAGER__
#define __GUIMANAGER__
#include "stdafx.h"

class Scene;
class Map;
class Bag;
class Player;

#define _guiManager GuiManager::getInstance()

class GuiManager{
public:
	static GuiManager* getInstance();
private:
	static GuiManager* _instance;

	
public:
	inline void clear(){ system("cls"); };						//����

	int getKey(){ char key = _getch(); return (int)key; };		//��ð���

	inline void pause(){ _getch(); };							//��ͣ,�����������

	void MenuUI(int* key);						//�˵�UI

	bool LoginUI(int* key);						//��½UI

	bool RegisterUI(int* key);					//ע��UI

	void GameStartUI(int* key);					//��Ϸ����UI

	void GameInitUI(int* key);					//��Ϸ��ʼ��UI

	void GameFreeUI(int* key);					//���ɻʱUI

	void GameDefenceUI(int* key);				//��ׯ����սʱUI

	void BagUI(int* key, Bag* bag);				//�����鿴UI

	void SoldierUI(int* key, Player* player);	//�����ϸ��Ϣ�鿴UI
	
	void SuccessUI();							//�ɹ���ʾ
	
	void FailureUI();							//ʧ����ʾ

	void RepeatUI(int* key);							//������ʾ

	inline Scene* getDefence_scene() const { return defence_scene; }
	inline Scene* getFree_scene() const { return free_scene; }
	inline Map* getDefence_ui() const { return defence_ui; }
	inline void setDefence_ui(Map* val) { defence_ui = val; }
	inline Map* getFree_ui() const { return free_ui; }
	inline void setFree_ui(Map* val) { free_ui = val;}
private:
	Scene* defence_scene;				//��ׯ����ս����
	Scene* free_scene;					//���ɻ����
	Map* defence_ui;					//����ս��ͼ
	Map* free_ui;						//���ɻ��ͼ
	
};
#endif