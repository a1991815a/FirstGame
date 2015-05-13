#ifndef __CUSTOMUTILS__
#define __CUSTOMUTILS__
#include "stdafx.h"
#include "header.h"
class Map;

/*�Զ��幤�߼�
����ʱ�乤��
*/

#define _customUtils CustomUtils::getInstance()

class CustomUtils{
public:
	static CustomUtils* getInstance();
private:
	static CustomUtils* _instance;

public:
	long getTime() const;

	float getDeleta();

	Vec2 transMapVec2(Map* map, Vec2 pos) const;

	Vec2 transNodeVec2(Node* node, Vec2 pos) const;

	Vec2 transGlobalVec2(Node* node, Vec2 pos) const;

	Vec2 transRenderVec2(Node* node, Vec2 pos) const;
private:
	long _time;
	long before_time;
};
#endif