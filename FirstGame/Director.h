#ifndef __DIRECTOR__
#define __DIRECTOR__
#include "stdafx.h"
#include "Scene.h"

//�����࣬���ڹ���������Ϸ

#define _director Director::getInstance()

class Director{
public:
	static Director* getInstance();
private:
	static Director* _instance;

	Director();

public:
	void mainloop();	//��ѭ��

	void initAll();

	void setScene(Scene* scene);

	Scene* getCurrentScene() const;

	Player* getActor() const;
private:
	Scene* CurrentScene;

};
#endif