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
	inline void setPos(int x, int y) { pos.x = x; pos.y = y;}

	inline Vec2 getDstPos() const { return dst_pos; }
private:
	string _name;				//����
	int _tag;					//tag���
	Node* _parent;				//����
	vector<Node*> _subNode;		//����
	Vec2 pos;					//����
	Vec2 dst_pos;				//��һ��Ҫ�ƶ�������
protected:
	int _z;						//_z����Ҳ����Ⱦ˳��(�����ڸ�) ���Ϊ10
};
#endif