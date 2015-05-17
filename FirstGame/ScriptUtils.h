#ifndef __SCRIPTUTILS__
#define __SCRIPTUTILS__
#include "stdafx.h"
#include "Value.h"
#include "Script.h"

typedef std::function<bool(Value, Vec2)> scriptFunc;

struct ClassType
{
public:
	string type;
	vector<string> var_list;
};

class ScriptUtils{
public:
	static ScriptUtils* getInstance();
private:
	static ScriptUtils* _instance;
	ScriptUtils();
public:

	Script loadOneScript(string script);				//读取单条脚本
	void excuteOneFunc(string script_func);

	ScriptObject getLeftObject(string& script);			//左变量
	ScriptObject getRightObject(string& script);		//右变量

	ConditionSignal getCondition(string& script);		//条件
	
public:
	bool checkCondition(ScriptObject left, ScriptObject right);

	/*
		脚本列表维护
	*/
public:
	void insert(string key, ClassType type);
	void insert(string key, ConditionSignal signal);
	void insert(string key, ScriptFuncObject func_obj);
	void insert(string key, scriptFunc func);

	inline ClassType getClassType(string key){ return _class_map.at(key); };
	inline ConditionSignal getCondition(string key){ return _condition_map.at(key); };
	inline ScriptFuncObject getFuncObj(string key){ return _func_obj_map.at(key); };
	inline scriptFunc getFunc(string key){ return _func_map.at(key); };
private:
	map<string, ClassType> _class_map;
	map<string, ConditionSignal> _condition_map;
	map<string, ScriptFuncObject> _func_obj_map;
	map<string, scriptFunc> _func_map;
};
#endif