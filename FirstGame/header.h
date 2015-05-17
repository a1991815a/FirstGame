#ifndef __HEADER__
#define __HEADER__

//����궨��
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

//��
#define MAX_HEIGHT					50		//��ͼ��С����
#define MAX_WIDTH					100

#define CUT_HEIGHT					18		//�ü���
#define CUT_WIDTH					48

#define SUB_TEXT_POS_X				0		//�ײ��ı���ʾ��ʼλ��
#define SUB_TEXT_POS_Y				19
#define SUB_TEXT_SIZE_WIDTH			58		//�ײ��ı��ߴ�
#define SUB_TEXT_SIZE_HEIGHT		5		

#define SIDE_TEXT_POS_X				53		//�����ı���ʼλ��
#define SIDE_TEXT_POS_Y				0
#define SIDE_TEXT_SIZE_WIDTH		30		//�����ı��ߴ�
#define SIDE_TEXT_SIZE_HEIGHT		5		
#define SIDE_TEXT_POS_END_X			SIDE_TEXT_POS_X+SIDE_TEXT_SIZE_WIDTH
#define SIDE_TEXT_POS_END_Y			SIDE_TEXT_POS_Y+SIDE_TEXT_SIZE_HEIGHT

#define MIN_Z						-9		//Z��������
#define MAX_Z						9

//�����
	//��ȫ�ͷ�
#define SAFE_DELETE(A)  do {if(A != nullptr) delete A; A = nullptr;} while (0);

/***********************************************/
//Message ��
#define MSG_NULL					0x0000		//����Ϣ

/***********************************************/
//��Ϸ״̬
#define GAME_STATE_PAUSE			0x0001		//��Ϸ��ͣ״̬
#define GAME_STATE_NORMAL			0x0002		//��Ϸ��������״̬
#define GAME_STATE_FIGHT			0x0004		//ս��״̬
#define GAME_STATE_CHAT				0x0008		//��̸����״̬

/***********************************************/
#define MSG_SYSTEM					0x0010		//ϵͳ��Ϣƫ��
#define MSG_SYSTEM_EXIT				0x0011		//�˳�

/***********************************************/
#define MSG_OPERATE_KEY				0x1000		//��������

/***********************************************/
//����״̬
#define PLAYER_STATE_NORMAL			0x1001		//��������״̬
#define NPC_STATE					0x1100		//NPC״̬

/***********************************************/
#define MSG_MOVE					0x1200		//�ƶ���Ϣ
#define MSG_TO_DIRECTION			0x1201		//ת����Ϣ
#define MSG_AUTO_MOVE				0x1202		//�ƶ���Ϣ
#define MSG_AUTO_TO_DIRECTION		0x1203		//ת����Ϣ

/***********************************************/
#define MSG_ONOFF					0x1300		//������Ϣ
#define MSG_STATIC_ONOFF			0x1301		//������Ϣ

/***********************************************/
#define MSG_COLLISION				0x2000		//������ײ��Ϣ

#define MSG_STATE_CONTROL			0x2100		//״̬����
#define MSG_STATE_EXCUTE			0x2101		//״̬����Ϣ

/***********************************************/
//�Զ�����Ϣ
#define MSG_CUSTOM					0x3000		//�Զ�����Ϣ������ʼλ��

/***********************************************/
#define MSG_FIGHT_START				0x3001		//ս����ʼ
#define MSG_FIGHT_ATTACK			0x3002		//����
#define MSG_FIGHT_DEFENCE			0x3003		//����
#define MSG_FIGHT_END				0x3004		//ս������

/***********************************************/
#define MSG_NPC_TRANS_STATE			0x3100		//NPC״̬�������
#define MSG_NPC_CHAT				0x3101		//��̸

/***********************************************/
#define MSG_TASK_ACCEPT				0x3201		//��������
#define MSG_TASK_COMPLETE			0x3202		//�������

/***********************************************/
#define MSG_EVENT_CHANGE_STATE		0x3301		//�ı�TASK״̬

/***********************************************/
//�ڵ�Tag						
#define CUSTOM_TAG_START			0x4000		//�Զ���TAGƫ��
#define PLAYER_ACTOR				0x4001		//����TAG

#endif