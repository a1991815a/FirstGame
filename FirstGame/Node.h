#ifndef __NODE__
#define __NODE__
#include "Ref.h"
#include "stdafx.h"
#include "header.h"

//�ڵ�ģ��

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

	virtual void visit(Vec2 vec){};

	void sendRenderCommand();

	void addChild(Node* node, int z = 0);

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
	inline virtual void setPos(int x, int y) {pos.x = x; pos.y = y;}

	bool getCanMove() const { return canMove; }
	void setCanMove(bool val) { canMove = val; }

	virtual int getType() const{ return 0; };
private:
	string _name;				//����
	int _tag;					//tag���
	Node* _parent;				//����
	vector<Node*> _subNode;		//����
	Vec2 pos;					//����
	bool canMove;				//�Ƿ�Ϊ���ƶ�״̬
protected:
	int _z;						//_z����Ҳ����Ⱦ˳��(�����ڸ�) ���Ϊ10

public:
	inline Vec2 getBeforePos() const { return before_pos; }
	inline void resetPos() { if (canMove) pos = before_pos; };
	inline void setBeforePos(int x, int y) { before_pos = getPos(); setPos(x, y); }
	inline void setPosUp(){ before_pos = getPos(); pos.y++; }
	inline void setPosDown(){ before_pos = getPos(); pos.y--; }
	inline void setPosLeft(){ before_pos = getPos(); pos.x--; }
	inline void setPosRight(){ before_pos = getPos(); pos.x++; }
private:
	Vec2 before_pos;	//��һ���ƶ�������
};
#endif