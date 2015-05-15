#ifndef __DIRECTOR__
#define __DIRECTOR__
#include "stdafx.h"
#include "Scene.h"

//导演类，用于管理整个游戏

#define _director Director::getInstance()

class Director{
public:
	static Director* getInstance();
private:
	static Director* _instance;

	Director();

public:
	void mainloop();	//主循环

	void initAll();

	void setScene(Scene* scene);

	Scene* getCurrentScene() const;

	Player* getActor() const;
private:
	Scene* CurrentScene;

};
#endif