#ifndef __STATICONOFF__
#define __STATICONOFF__
#include "stdafx.h"

class StaticOnOff{
public:
	static bool getStatic_onoff_map(int index) { return static_onoff_map.at(index); }
	static void setStatic_onoff_map(map<int, bool> val) { static_onoff_map = val; }
private:
	static map<int, bool> static_onoff_map;
};
#endif