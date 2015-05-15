#ifndef  __PLAYER__
#define __PLAYER__
#include "stdafx.h"
#include "Actor.h"

class Player: public Actor{
public:
	CREATE_FUNC(Player);
	virtual bool init();

	void initPlayer(int hp, int attack, int defence);

	void levelUp(int uplevel);
private:
	
	int _level_factor;
};
#endif
