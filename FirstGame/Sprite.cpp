#include "Sprite.h"
#include "RenderEngine.h"

Sprite::Sprite()
	:Node()
{
	_texture[0] = ' ';
	_texture[1] = ' ';
}

Sprite::~Sprite(){}

bool Sprite::init()
{
	return true;
}

void Sprite::visit(Vec2 vec)
{
	_renderEngine->addRenderData(_texture[0], vec);
	vec.x += 1;
	_renderEngine->addRenderData(_texture[1], vec);
}
