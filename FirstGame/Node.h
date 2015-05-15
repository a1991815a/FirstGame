#ifndef __NODE__
#define __NODE__
#include "Ref.h"
#include "stdafx.h"
#include "header.h"

//节点模型

#define CREATE_FUNC(T)			\
static T* create(){				\
	T* ret = new T();			\
	if (ret && ret->init())		\
	{							\
		ret->autorelease();		\
		return ret;				\
	}							\
	SAFE_DELETE(ret);			\
	return nullptr;				\
}


class Node: public Ref{
public:
	Node();
	virtual ~Node();

	virtual void visit(Vec2 vec) = 0;

	void sendRenderCommand();

	void addChild(Node* node);

	void addChild(Node* node, int z);

	void releaseChild(Node* node);

	void releaseChild(string name);

	void releaseChild(int tag);

	Node* searchChild(string name);
	Node* searchChild(int tag);

	inline std::string getName() const { return _name; }
	inline void setName(std::string val) { _name = val; }

	inline int getTag() const { return _tag; }
	inline void setTag(int val) { _tag = val; }

	inline Node* getParent() const { return _parent; }

	inline Vec2 getPos() const { return pos; }
	inline void setPos(int x, int y) { before_pos = pos; pos.x = x; pos.y = y;}

	inline void setPosUp(){ before_pos = pos; pos.y++; }
	inline void setPosDown(){ before_pos = pos; pos.y--; }
	inline void setPosLeft(){ before_pos = pos; pos.x--; }
	inline void setPosRight(){ before_pos = pos; pos.x++; }

	inline Vec2 getBeforePos() const { return before_pos; }
	inline void resetPos() {pos = before_pos;};

	bool getCanMove() const { return canMove; }
	void setCanMove(bool val) { canMove = val; }
private:
	string _name;				//名字
	int _tag;					//tag标记
	Node* _parent;				//父亲
	vector<Node*> _subNode;		//子列
	Vec2 pos;					//坐标
	Vec2 before_pos;			//下一次要移动的坐标
	bool canMove;				//是否为可移动状态
protected:
	int _z;						//_z坐标也是渲染顺序(用于遮盖) 最大为10
};
#endif