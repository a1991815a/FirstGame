#ifndef __HEADER__
#define __HEADER__

//各类宏定义

class Node;

struct Vec2
{
public:
	Vec2(){ x = y = 0; };
	Vec2(int x, int y){
		this->x = x;
		this->y = y;
	};

	Vec2 operator+(Vec2 vec){
		return Vec2(x + vec.x, y + vec.y);
	}

	void operator+=(Vec2 vec){
		x += vec.x;
		y += vec.y;
	}

	Vec2 operator-(Vec2 vec){
		return Vec2(x - vec.x, y - vec.y);
	}

	void operator-=(Vec2 vec){
		x -= vec.x;
		y -= vec.y;
	}

	bool operator==(Vec2 vec){
		if (this->x == vec.x && this->y == vec.y)
		{
			return true;
		}
		return false;
	}
	int x, y;
};

struct RenderCommand{
public:
	RenderCommand(){node=nullptr;};
	RenderCommand(Node* _node, Vec2 pos){
		node = _node;
		renderPos = pos;
	}
	Node* node;
	Vec2 renderPos;
};

//宏
#define MAX_HEIGHT		50
#define MAX_WIDTH		60

#define CUT_HEIGHT		10
#define CUT_WIDTH		20

#define MIN_Z			-9
#define MAX_Z			9

//宏操作
#define SAFE_DELETE(A)  do {if(A != nullptr) delete A; A = nullptr;} while (0);

//Message 宏
#define MSG_NULL				0x0000

#define MSG_COLLISION			0x4000

#define MSG_OPERATE_KEY			0x1000

#define MSG_OPERATE_UP			0x1001
#define MSG_OPERATE_DOWN		0x1002
#define MSG_OPERATE_LEFT		0x1004
#define MSG_OPERATE_RIGHT		0x1008

#define MSG_CUSTOM				0x5000

//游戏状态
#define GAME_STATE_PAUSE			0x0001
#define GAME_STATE_ACTING			0x0003


//精灵状态
#define PLAYER_STATE_NORMAL			0x1001



#endif