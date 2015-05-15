#ifndef __EVENTCOMMAND__
#define __EVENTCOMMAND__
#include "stdafx.h"
#include "Ref.h"
#include "Value.h"
#include "Node.h"

class Event;

class EventCommand: public Ref{
public:
	virtual void excute(Event* event, Value value) = 0;
private:

};

class ShowSubTextCommand: public EventCommand{
public:
	CREATE_FUNC(ShowSubTextCommand);
	inline bool init(){return true;};
	virtual void excute(Event* event, Value value) override;
};

class ShowSideTextCommand: public EventCommand{
public:
	CREATE_FUNC(ShowSideTextCommand);
	inline bool init(){return true;};
	virtual void excute(Event* event, Value value) override;
};

class MoveDirectionCommand: public EventCommand{
public:
	CREATE_FUNC(MoveDirectionCommand);
	inline bool init(){return true;};
	virtual void excute(Event* event, Value value) override;
};

class ToDirectionCommand: public EventCommand{
public:
	CREATE_FUNC(ToDirectionCommand);
	inline bool init(){return true;};
	virtual void excute(Event* event, Value value) override;
};

class AcceptTaskCommand: public EventCommand{
public:
	CREATE_FUNC(ToDirectionCommand);
	inline bool init(){return true;};
	virtual void excute(Event* event, Value value) override;
};

class CompleteTaskCommand: public EventCommand{
public:
	CREATE_FUNC(ToDirectionCommand);
	inline bool init(){return true;};
	virtual void excute(Event* event, Value value) override;
};

class FightStartCommand: public EventCommand{
public:
	CREATE_FUNC(ToDirectionCommand);
	inline bool init(){return true;};
	virtual void excute(Event* event, Value value) override;
};

class FightEndCommand: public EventCommand{
public:
	CREATE_FUNC(ToDirectionCommand);
	inline bool init(){return true;};
	virtual void excute(Event* event, Value value) override;
};

#endif