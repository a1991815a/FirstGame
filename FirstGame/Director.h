#ifndef __DIRECTOR__
#define __DIRECTOR__
#include "stdafx.h"
#include "Scene.h"
#include "TimerManager.h"

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

	Scene* getCurrentScene() const{ return CurrentScene; };

	Player* getPlayer() const;

	void renderAll();

	inline void addDt(){ _dt += _timerManager->getDelta(); };
	inline long getDt() const{ return _dt; };
	inline void resetDt(){ _dt = 0; };
	inline void refreshScreen(){ _dt = render_dt + 1; };

	inline void setFrames(int frame){ render_dt = 1000 / frame; };
private:
	Scene* CurrentScene;
	long _dt;
	long render_dt;
};
#endif