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

	inline int getMoney() const { return _money; }
	inline void addMoney(int val) { _money += val; }
	inline void subMoney(int val) { _money -= val; }
	inline bool checkMoney(int price) { if (_money - price < 0) return false; return true; }
private:
	
	int _level_factor;
	int _money;
};
#endif
