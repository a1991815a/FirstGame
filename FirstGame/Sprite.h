#ifndef __SPRITE__
#define __SPRITE__
#include "stdafx.h"
#include "Node.h"

//精灵模型

class Sprite : public Node{
public:
	CREATE_FUNC(Sprite);

	virtual bool init();

	virtual void visit(Vec2 vec);

	inline const char* getTexture() const { return _texture; }
	inline void setTexture(const char* val) { _texture[0] = val[0]; _texture[1] = val[1]; }

private:
	char _texture[2];		//纹理

protected:
	Sprite();
	virtual ~Sprite();
};
#endif