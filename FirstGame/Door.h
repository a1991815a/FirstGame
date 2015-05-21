#ifndef __DOOR__
#define __DOOR__
#include "Area.h"

class Door: public Area{
public:
	Door(int tag, Vec2 pos);
	
//	virtual void trigger() override;

	inline int getNext_map_tag() const { return next_map_tag; }
	inline void setNext_map_tag(int val) { next_map_tag = val; }
	inline Vec2 getNext_pos() const { return next_pos; }
	inline void setNext_pos(Vec2 val) { next_pos = val; }
private:
	int next_map_tag;
	Vec2 next_pos;
};
#endif