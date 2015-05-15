#ifndef __EVENT__
#define __EVENT__
#include "stdafx.h"
#include "Ref.h"

class Event: public Ref{
public:
	Event();

	virtual void trigger() = 0;

	void setCondition(bool isStatic,int index);
	bool getCondition() const;

	int getEventId() const { return event_id; }
	void setEventId(int val) { event_id = val; }

	void addSystem();
private:
	int event_id;

	OnOff _onoff;
	bool static_onoff;
	vector<int> onoff_index_list;
};
#endif