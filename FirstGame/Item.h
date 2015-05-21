#ifndef __ITEM__
#define __ITEM__
#include "stdafx.h"
#include "Node.h"

class Item: public Ref{
public:
	Item(){};
	Item(int type){ _name = "Item"; _tag = 0; _type = type; };
	Item(string name, int tag, int type);
	inline std::string getName() const { return _name; }
	inline void setName(std::string val) { _name = val; }
	inline int getTag() const { return _tag; }
	inline void setTag(int val) { _tag = val; }

	inline int getType() const{ return _type; };

	virtual ~Item(){};
private:
	string _name;
	int _tag;

	
public:
	bool operator==(Item item);

private:
	int _type;
};
#endif