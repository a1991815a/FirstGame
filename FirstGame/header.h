#ifndef __HEADER__
#define __HEADER__

//����궨��

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
//�����
#define SAFE_DELETE(A)  do {if(A != nullptr) delete A; A = nullptr;} while (0);

//Message ��
#define MSG_NULL 0x0000

//��Ϸ״̬


//����״̬


#endif