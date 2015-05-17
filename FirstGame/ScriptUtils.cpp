#include "ScriptUtils.h"
#include "DataUtils.h"

ScriptUtils* ScriptUtils::_instance = nullptr;

ScriptUtils* ScriptUtils::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new ScriptUtils();
	}
	return _instance;
}

ScriptUtils::ScriptUtils()
{
	
}

Script ScriptUtils::loadOneScript(string script)
{
	int index = 0;
	_dataUtils->deleteCharFromString(script, '\n', index);
	_dataUtils->deleteCharFromString(script, '\r', index);
	_dataUtils->deleteCharFromString(script, '\t', index);
	vector<string> script_list = _dataUtils->splitString(script, ';', index);
	
}

ScriptObject ScriptUtils::getLeftObject(string& script)
{
	ScriptObject obj;
	int index = 0;
	obj.type = _dataUtils->getFrontChar(script, ':', index);
	index++;
	obj.tag = _dataUtils->getFrontChar(script, '[', index, index);
	index++;
	obj.var = _dataUtils->getFrontChar(script, ']', index, index);
	return obj;
}

ScriptObject ScriptUtils::getRightObject(string& script)
{
	ScriptObject obj;
	int index = 0;
	_dataUtils->getFrontChar(script, ' ', index);
	index++;
	_dataUtils->getFrontChar(script, ' ', index);
	index++;

	obj.type = _dataUtils->getFrontChar(script, ':', index, index);
	index++;
	obj.tag = _dataUtils->getFrontChar(script, '[', index, index);
	index++;
	obj.var = _dataUtils->getFrontChar(script, ']', index, index);
	return obj;
}

ConditionSignal ScriptUtils::getCondition(string& script)
{
	string signal_string;
	ConditionSignal return_signal;
	int index = 0;
	_dataUtils->getFrontChar(script, ' ', index);
	index++;
	signal_string = _dataUtils->getFrontChar(script, ' ', index, index);
	return _condition_map.at(signal_string);
}

void ScriptUtils::insert(string key, ClassType type)
{
	_class_map.insert(map<string, ClassType>::value_type(key, type));
}

void ScriptUtils::insert(string key, ConditionSignal signal)
{
	_condition_map.insert(map<string, ConditionSignal>::value_type(key, signal));
}

void ScriptUtils::insert(string key, ScriptFuncObject func_obj)
{
	_func_obj_map.insert(map<string, ScriptFuncObject>::value_type(key, func_obj));
}

void ScriptUtils::insert(string key, scriptFunc func)
{
	_func_map.insert(map<string, scriptFunc>::value_type(key, func));
}

