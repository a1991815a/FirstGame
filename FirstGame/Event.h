#ifndef __EVENT__
#define __EVENT__
#include "stdafx.h"
#include "Ref.h"

/*
	事件模型
	继承于Ref,通过统一内存管理器管理,通过继承该类重写excuteEvent可实现不同任务
*/
class Event : public Ref{
public:
	Event();										//event构造函数

	inline void trigger(){							//触发事件
		if (canTrigger())
			excuteEvent();
	};												

	void excuteEvent();					//执行事件

	void setCondition(bool isStatic, int index);	//设置条件
	bool canTrigger() const;						//查看是否可以触发事件

	int getEventId() const { return event_id; }		//事件id操作
	void setEventId(int val) { event_id = val; }	//事件id操作

	void addSystem();								//加入事件系统

	void setOnOff(int index, bool onoff);			//设置独立开关状态

	inline int getCurrentState() const { return CurrentState; }	//得到当前状态
	inline void setCurrentState(int val) { CurrentState = val; }//设置当前状态

	inline std::string getScrpit() const { return scrpit; }		//脚本获得
	inline void setScrpit(std::string val) { scrpit = val; }	//脚本设置
private:
	string scrpit;
	int event_id;									//事件id
	int CurrentState;								//当前状态
	OnOff _onoff;									//独立开关(结构体)
	bool static_onoff;								//是否开启全局开关条件
	vector<int> onoff_index_list;					//全局开关索引
	vector<Vec2> trigger_pos_list;					//触发位置
};
#endif