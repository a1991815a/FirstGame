#ifndef  __PLAYER__
#define __PLAYER__
#include "stdafx.h"
#include "Sprite.h"

class Player: public Sprite{
public:
	CREATE_FUNC(Player);
	virtual bool init();
private:

};
#endif
