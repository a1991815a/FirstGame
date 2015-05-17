#include "Player.h"

bool Player::init()
{
	_level = 0;
	_money = 100;
	Actor::init(100, 10, 5);

	return true;
}
