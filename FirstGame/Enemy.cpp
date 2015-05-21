#include "Enemy.h"

bool Enemy::init()
{
	_isBoss = false;

	return true;
}

void Enemy::setBoss()
{
	_isBoss = true;
}
