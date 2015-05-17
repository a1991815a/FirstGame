#ifndef __SCRIPTINTERPRETER__
#define __SCRIPTINTERPRETER__
#include "stdafx.h"

#define _scriptInterpreter ScriptInterpreter::getInstance()

class ScriptInterpreter{
public:
	static ScriptInterpreter* getInstance();
private:
	static ScriptInterpreter* _instance;

public:
	void formatScript(string& script);

	vector<string> splitScript(string& script, char split_char);;

	void excuteSingleScript(string& script);

	vector<string> splitScriptByDouble(string& script);

	int getEventId(string& script);

	vector<Event> explainScript(string& script);
};
#endif