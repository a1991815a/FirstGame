#ifndef __CONSOLEBUFFERUTILS__
#define __CONSOLEBUFFERUTILS__
#include "stdafx.h"

#define _consoleBufferUtils ConsoleBufferUtils::getInstance()

class ConsoleBufferUtils{
public:
	static ConsoleBufferUtils* getInstance();
private:
	static ConsoleBufferUtils* _instance;
	ConsoleBufferUtils():max_size(MAX_WIDTH*MAX_HEIGHT){};

public:
	void renderAll();

private:
	void init();

	void swap();

	void cls(HANDLE handle);

	void printf(char** in_data,int width, int height);

	void printf(const char* format, ...);

	inline DWORD getOut_len() const { return _out_len; }
private:
	HANDLE _display;
	HANDLE _surface;
	string* _out;
	DWORD _out_len;
	CONSOLE_SCREEN_BUFFER_INFO _info;
	const DWORD max_size;
};
#endif