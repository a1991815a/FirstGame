#ifndef __HEADER__
#define __HEADER__

//各类宏定义
class Node;

struct OnOff{
public:
	OnOff(){
		A=B=C=D=true;
	}
	bool A,B,C,D;
};

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

enum MoveObj{
	MoveUp,MoveDown,MoveLeft,MoveRight
};

//宏
#define USER_FILE_NAME				"user.inf"//用户注册文件

#define MAX_HEIGHT					25		//地图大小限制
#define MAX_WIDTH					80

#define CUT_HEIGHT					18		//裁剪宏
#define CUT_WIDTH					48

#define SUB_TEXT_POS_X				0		//底部文本显示初始位置
#define SUB_TEXT_POS_Y				19
#define SUB_TEXT_SIZE_WIDTH			MAX_WIDTH - SUB_TEXT_POS_X		//底部文本尺寸
#define SUB_TEXT_SIZE_HEIGHT		MAX_HEIGHT - SIDE_TEXT_POS_Y		

#define SIDE_TEXT_POS_X				53		//侧面文本起始位置
#define SIDE_TEXT_POS_Y				0
#define SIDE_TEXT_SIZE_WIDTH		MAX_WIDTH - SIDE_TEXT_POS_X		//侧面文本尺寸
#define SIDE_TEXT_SIZE_HEIGHT		MAX_HEIGHT - SIDE_TEXT_POS_Y

#define MIN_Z						-9		//Z坐标区间
#define MAX_Z						9

#define ENEMY_NUM					5		//每波怪物总数
#define MAX_SOLDIER					5		//最大随从

//宏操作
	//安全释放
#define SAFE_DELETE(A)  do {if(A != nullptr) delete A; A = nullptr;} while (0);

/***********************************************/
//Message 宏
#define MSG_NULL					0x0000		//空消息

/***********************************************/
//游戏状态
#define GAME_STATE_HINT				0x0001		//游戏暂停状态
#define GAME_STATE_NORMAL			0x0002		//游戏运行正常状态
#define GAME_STATE_FIGHT			0x0004		//战斗状态
#define GAME_STATE_CHAT				0x0008		//交谈或交易状态

#define GAME_STATE_FREEACT			0x0011		//自由活动中
#define GAME_STATE_DEFENCE			0x0012		//防御战中

/***********************************************/
#define MSG_SYSTEM					0x0510		//系统信息偏移
#define MSG_SYSTEM_EXIT				0x0511		//退出

/***********************************************/
#define MSG_OPERATE_KEY				0x1000		//按键操作

/***********************************************/
//精灵状态
#define PLAYER_STATE_NORMAL			0x1001		//精灵正常状态
#define NPC_STATE					0x1100		//NPC状态

/***********************************************/
#define MSG_MOVE					0x1200		//移动消息
#define MSG_TO_DIRECTION			0x1201		//转向消息
#define MSG_AUTO_MOVE				0x1202		//移动消息
#define MSG_AUTO_TO_DIRECTION		0x1203		//转向消息

/***********************************************/
#define MSG_ONOFF					0x1300		//开关消息
#define MSG_STATIC_ONOFF			0x1301		//开关消息

/***********************************************/
#define MSG_COLLISION				0x2000		//刚体碰撞消息

#define MSG_STATE_CONTROL			0x2100		//状态控制
#define MSG_STATE_EXCUTE			0x2101		//状态机消息

/***********************************************/
//自定义消息
#define MSG_CUSTOM					0x3000		//自定义消息类型起始位置

/***********************************************/
#define MSG_FIGHT_START				0x3001		//战斗开始
#define MSG_FIGHT_ATTACK			0x3002		//攻击
#define MSG_FIGHT_DEFENCE			0x3003		//防御
#define MSG_FIGHT_END				0x3004		//战斗结束

#define MSG_FREEACT_START			0x3005		//自由活动时间开始
#define MSG_DEFENCE_START			0x3006		//村庄防御战开始

/***********************************************/
#define MSG_NPC_TRANS_STATE			0x3100		//NPC状态更换标记
#define MSG_NPC_CHAT				0x3101		//交谈

/***********************************************/
#define MSG_TASK_ACCEPT				0x3201		//接受任务
#define MSG_TASK_COMPLETE			0x3202		//完成任务

/***********************************************/
#define MSG_EVENT_CHANGE_STATE		0x3301		//改变TASK状态

/***********************************************/
//节点Tag						
#define CUSTOM_TAG_START			0x4000		//自定义TAG偏移
#define PLAYER_ACTOR				0x4001		//主角TAG

/*
	Node类型
*/
#define Node_Enemy					0x0001
#define Node_Npc					0x0002
#define Node_NpcSoldier				0x0003
#define Node_Player					0x0004

#define Node_Item					0x0011
#define Node_Material				0x0012
#define Node_Weapon					0x0013
#define Node_Armor					0x0014

#endif