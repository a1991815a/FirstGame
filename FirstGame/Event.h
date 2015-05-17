#ifndef __EVENT__
#define __EVENT__
#include "stdafx.h"
#include "Ref.h"

/*
	�¼�ģ��
	�̳���Ref,ͨ��ͳһ�ڴ����������,ͨ���̳и�����дexcuteEvent��ʵ�ֲ�ͬ����
*/
class Event : public Ref{
public:
	Event();										//event���캯��

	inline void trigger(){							//�����¼�
		if (canTrigger())
			excuteEvent();
	};												

	void excuteEvent();					//ִ���¼�

	void setCondition(bool isStatic, int index);	//��������
	bool canTrigger() const;						//�鿴�Ƿ���Դ����¼�

	int getEventId() const { return event_id; }		//�¼�id����
	void setEventId(int val) { event_id = val; }	//�¼�id����

	void addSystem();								//�����¼�ϵͳ

	void setOnOff(int index, bool onoff);			//���ö�������״̬

	inline int getCurrentState() const { return CurrentState; }	//�õ���ǰ״̬
	inline void setCurrentState(int val) { CurrentState = val; }//���õ�ǰ״̬

	inline std::string getScrpit() const { return scrpit; }		//�ű����
	inline void setScrpit(std::string val) { scrpit = val; }	//�ű�����
private:
	string scrpit;
	int event_id;									//�¼�id
	int CurrentState;								//��ǰ״̬
	OnOff _onoff;									//��������(�ṹ��)
	bool static_onoff;								//�Ƿ���ȫ�ֿ�������
	vector<int> onoff_index_list;					//ȫ�ֿ�������
	vector<Vec2> trigger_pos_list;					//����λ��
};
#endif