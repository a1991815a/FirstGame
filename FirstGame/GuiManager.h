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
	inline void clear(){ system("cls"); };						//清屏

	int getKey(){ char key = _getch(); return (int)key; };		//获得按键

	inline void pause(){ _getch(); };							//暂停,按任意键继续

	void MenuUI(int* key);						//菜单UI

	bool LoginUI(int* key);						//登陆UI

	bool RegisterUI(int* key);					//注册UI

	void GameStartUI(int* key);					//游戏介绍UI

	void GameInitUI(int* key);					//游戏初始化UI

	void GameFreeUI(int* key);					//自由活动时UI

	void GameDefenceUI(int* key);				//村庄防御战时UI

	void BagUI(int* key, Bag* bag);				//背包查看UI

	void SoldierUI(int* key, Player* player);	//随从详细信息查看UI
	
	void SuccessUI();							//成功提示
	
	void FailureUI();							//失败提示

	void RepeatUI(int* key);							//重试提示

	inline Scene* getDefence_scene() const { return defence_scene; }
	inline Scene* getFree_scene() const { return free_scene; }
	inline Map* getDefence_ui() const { return defence_ui; }
	inline void setDefence_ui(Map* val) { defence_ui = val; }
	inline Map* getFree_ui() const { return free_ui; }
	inline void setFree_ui(Map* val) { free_ui = val;}
private:
	Scene* defence_scene;				//村庄防御战场景
	Scene* free_scene;					//自由活动场景
	Map* defence_ui;					//防御战地图
	Map* free_ui;						//自由活动地图
	
};
#endif