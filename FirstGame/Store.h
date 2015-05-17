#ifndef __STORE__
#define __STORE__
#include "Area.h"

class Store: public Area{
public:
	void pushItem(int tag);
	void buyItem(int tag);
	void sellItem(int tag);

private:
	vector<int> items;
};
#endif