// #ifndef __SCRIPT__
// #define __SCRIPT__
// #include "stdafx.h"
// #include "Value.h"
// 
// enum ScriptFuncType
// {
// 	showSub, showSide, acceptTask, completeTask, gotoMap, buyItem, sellItemm, achiveItem
// };
// 
// struct ScriptObject
// {
// public:
// 	string type;
// 	string tag;
// 	string var;
// };
// 
// struct ScriptFuncObject
// {
// public:
// 	ScriptFuncType type;
// 	string param;
// };
// 
// enum ConditionSignal
// {
// 	isAcceptTask, isCompleteTask, isAlive, isDead, isOn, 
// 	Smaller, Bigger, Equal, notEqual, SE, BE
// };
// 
// class Script{
// public:
// 	inline ScriptObject getRight() const { return _right; }
// 	inline void setRight(ScriptObject val) { _right = val; }
// 	inline ScriptObject getLeft() const { return _left; }
// 	inline void setLeft(ScriptObject val) { _left = val; }
// 
// 	inline ConditionSignal getCondition() const { return _condition; }
// 	inline void setCondition(ConditionSignal val) { _condition = val; }
// 
// 	inline vector<ScriptFuncObject> getScript_func_list() const { return _script_func_list; }
// 	inline void setScript_func_list(vector<ScriptFuncObject> val) { _script_func_list = val; }
// 
// 	bool excute();
// 
// private:
// 	ScriptObject _left, _right;
// 	ConditionSignal _condition;
// 	vector<ScriptFuncObject> _script_func_list;
// };
// #endif