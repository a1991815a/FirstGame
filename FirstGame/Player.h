#ifndef __PLAYER__
#define __PLAYER__
#include "stdafx.h"
#include "Actor.h"
#include "header.h"


class Player: public Actor{
public:
	CREATE_FUNC(Player);
	bool init();

	inline Vec2 getBeforePos() const { return before_pos; }
	inline void resetPos() { setPos(before_pos.x, before_pos.y); };
	inline virtual void setPos(int x, int y) { before_pos = getPos(); Node::setPos(x, y); }
	inline virtual void setPosUp(){ before_pos = getPos(); Node::setPosUp(); }
	inline virtual void setPosDown(){ before_pos = getPos(); Node::setPosDown(); }
	inline virtual void setPosLeft(){ before_pos = getPos(); Node::setPosLeft(); }
	inline virtual void setPosRight(){ before_pos = getPos(); Node::setPosRight(); }

	inline int getMoney() const { return _money; }
	inline void addMoney(int val) { _money += val; }
	inline void subMoney(int val) { _money -= val; }

	inline int getLevel() const { return _level; }
	inline void upLevel(int val) { _level += val; }

private:
	Vec2 before_pos;			//上一次移动的坐标
	int _money;
	int _level;
};
#endif