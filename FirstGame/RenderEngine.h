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

	void sendCommand(Node* node, Vec2 pos);

	inline void addRenderData(char texture, Vec2 render_pos){
		if(render_pos.x < 0 || render_pos.x > MAX_HEIGHT ||
			render_pos.y < 0 || render_pos.y > MAX_WIDTH)
			return;
		display_data[render_pos.y][render_pos.x] = texture;
	};

	void cutBuf();

	void clear();

	void setSubText(string format, ...);
	void setSideText(string format, ...);

	void renderSubText();
	void renderSideText(int row);
private:
	char** display_data;

	string sub_text;
	string side_text;

	vector<RenderCommand> _command_list;
};
#endif