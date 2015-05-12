#ifndef __SPRITE__
#define __SPRITE__
#include "stdafx.h"
#include "Node.h"

//精灵模型

class Sprite : public Node{
public:
	CREATE_FUNC(Sprite);

	virtual bool init();

	inline char getTexture() const { return _texture; }
	inline void setTexture(char val) { _texture = val; }

private:
	char _texture;		//纹理

private:
	Sprite();
	virtual ~Sprite();
};
#endif