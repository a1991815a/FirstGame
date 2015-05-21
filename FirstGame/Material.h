#ifndef __MATERIAL__
#define __MATERIAL__
#include "Item.h"

class Material: public Item{
public:
	CREATE_FUNC(Material);
	bool init(){ return true; };

	Material():Item(Node_Material){}
	
private:
	
};
#endif