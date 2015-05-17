#include "Player.h"

bool Player::init()
{
	setTag(PLAYER_ACTOR);
	setCanMove(true);
	return true;
}

void Player::initPlayer( int hp, int attack, int defence )
{
	setHp(hp);
	setAttack(attack);
	setDefence(defence);
}

void Player::levelUp(int uplevel)
{
	setAttack(getAttack() + uplevel * _level_factor * 2);
	setDefence(getDefence() + uplevel * _level_factor );
}
