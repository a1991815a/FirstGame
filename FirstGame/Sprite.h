#ifndef __SPRITE__
#define __SPRITE__
#include "stdafx.h"
#include "Node.h"

//����ģ��

class Sprite : public Node{
public:
	CREATE_FUNC(Sprite);

	virtual bool init();

	virtual void visit(Vec2 vec);

	inline char getTexture() const { return _texture; }
	inline void setTexture(char val) { _texture = val; }

private:
	char _texture;		//����

protected:
	Sprite();
	virtual ~Sprite();
};
#endif