#include "Sprite.h"
#include "RenderEngine.h"

Sprite::Sprite()
	:Node()
{
	_texture = ' ';
}

Sprite::~Sprite(){}

bool Sprite::init()
{
	return true;
}

void Sprite::visit(Vec2 vec)
{
	_renderEngine->addRenderData(_texture, vec);
}
