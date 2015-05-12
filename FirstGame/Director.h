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

	void setScene(Scene* scene);


private:
	Scene* CurrentScene;

};
#endif