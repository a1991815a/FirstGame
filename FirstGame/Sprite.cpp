#include "Sprite.h"

Sprite::Sprite()
	:Node()
{
	_texture = '*';
}

Sprite::~Sprite(){}

bool Sprite::init()
{
	return true;
}
