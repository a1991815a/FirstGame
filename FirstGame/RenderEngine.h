#ifndef __RENDERENGINE__	
#define __RENDERENGINE__
#include "stdafx.h"
#include <iostream>
#include <process.h>
class Map;

#define _renderEngine RenderEngine::getInstance()

//‰÷»æ“˝«Ê
class RenderEngine{
public:
	static RenderEngine* getInstance();
private:
	static RenderEngine* _instance;

	RenderEngine();
public:
	void RenderAll();

	void readyBuf();

	void assembleFragment();

	void assembleSubText();
	void assembleSideText();

	void sendCommand(Node* node, Vec2 pos);

	inline void addRenderData(char texture, Vec2 render_pos){
		if (render_pos.x < 0 || render_pos.x > MAX_WIDTH ||
			render_pos.y < 0 || render_pos.y > MAX_HEIGHT)
			return;
		display_data[render_pos.y][render_pos.x] = texture;
	};

	void cutBuf();

	void clear();

	void setSubText(string format, ...);
	void setSideText(int row, string format, ...);

	void clearSubTextBuf();
	void clearSideTextBuf();

	string* getOutText(){ return &out_text; };
private:
	char** display_data;

	string sub_text;
	string side_text[MAX_HEIGHT];

	string out_text;

	vector<RenderCommand> _command_list;
};
#endif