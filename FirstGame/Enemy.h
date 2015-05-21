#ifndef __ENEMY__
#define __ENEMY__
#include "stdafx.h"
#include "Actor.h"
#include "Material.h"

class Enemy: public Actor{
public:
	CREATE_FUNC(Enemy);
	bool init();

	void setBoss();
	inline bool isBoss(){ return _isBoss; };
	virtual int getType() const override{ return Node_Enemy; };
private:
	vector<Material> _dropItems;
	bool _isBoss;
};
#endif