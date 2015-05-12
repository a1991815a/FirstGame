#ifndef __MAP__
#define __MAP__
#include "stdafx.h"
#include "Node.h"
#include "header.h"

//µØÍ¼Ä£ÐÍ

class Map : public Node{
public:
	Map();
	CREATE_FUNC(Map);
	static Map* create(short width, short height);
	virtual bool init();
	virtual bool init(short width, short height);

	void initData(char**& in_data);
	virtual ~Map();

	inline short getWidth() const{ return width;};
	inline short getHeight() const{return height;};

private:
	char** final_data;
	char** map_data;
	short width;
	short height;
};
#endif