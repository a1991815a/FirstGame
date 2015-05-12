#ifndef __HEADER__
#define __HEADER__

//各类宏定义

struct vec2
{
public:
	vec2(){ x = y = 0; };
	vec2(int x, int y){
		this->x = x;
		this->y = y;
	};
	int x, y;
};
//宏操作
#define SAFE_DELETE(A)  do {if(A != nullptr) delete A; A = nullptr;} while (0);

//Message 宏
#define MSG_NULL 0x0000

//游戏状态


//精灵状态


#endif