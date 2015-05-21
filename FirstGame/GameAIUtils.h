#ifndef __GAMEAIUTILS__
#define __GAMEAIUTILS__
#include "stdafx.h"

class GameAIUtils{
public:
	static GameAIUtils* getInstance();
private:
	static GameAIUtils* _instance;

public:
	void autoSearchEnemy(Node* node);


private:
	vector<Node*> ai_node;
};
#endif