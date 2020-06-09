#pragma once
#include <windows.h>

class PLAYER {
	int x, y, w, h;
	int savex, savey;	//savey �� �����۶� �� ������ y��ǥ�� ����ϱ� �����̰� x�� Ȥ�ø��� �־��
	int state;			//1�⺻����,2��������,3���̱����,4�̵�����,5�ٿ� �Ŵ޸�����,6�ǰݻ���,7���߿��ִ»���
	int dir;			//1���� 2������ 3�� 4�Ʒ�
	int COMMAND_move;	//�̰� �����̰��ִ� ��Ȳ���� �ƴ��� ���� 1�̸�������ο�����  2�� ���������� ������0�̸� �ȿ�����
	HBITMAP hbitwalk;   //������ ��Ʈ��
	HBITMAP hbitex;		//����,���̱� ��Ÿ�� ��Ʈ��
public:
	PLAYER();
	void setx(int);
	void sety(int);
	void setw(int);			//����
	void seth(int);
	//1�⺻����,2��������,3���̱����,4�̵�����,5�ٿ� �Ŵ޸�����,6�ǰݻ���,7���߿��ִ»���
	void setstate(int);
	//1���� 2������ 3�� 4�Ʒ�
	void setdir(int);
	//�̰� �����̰��ִ� ��Ȳ���� �ƴ��� ���� 
	void setCMD_move(int);
	void setBit(HINSTANCE);

	int getx();
	int gety();
	int getw();			//����
	int geth();
	//1�⺻����,2��������,3���̱����,4�̵�����,5�ٿ� �Ŵ޸�����,6�ǰݻ���,7���߿��ִ»���
	int getstate();
	//1���� 2������ 3�� 4�Ʒ�
	int getdir();
	//�̰� �����̰��ִ� ��Ȳ���� �ƴ��� ���� 
	int getCMD_move();


	void PlayerSetting(WPARAM);
	void PlayerWaiting(WPARAM);
	void fall2save();
	void move();
};


extern int ROWSPEED; 	//���� �̵��ӵ�
extern int COLSPEED;	//���� �̵��ӵ�
extern bool LEFTkey;//����Ű �������� 1�̸� ���� 0�̸� �ȴ���
extern bool RIGHTkey;//������Ű �������� 1�̸� ���� 0�̸� �ȴ���
extern bool UPkey;	//����Ű �������� 1�̸� ���� 0�̸� �ȴ���
extern bool DOWNkey;//�Ʒ���Ű �������� 1�̸� ���� 0�̸� �ȴ���
		//���ʿ�����Ű ���ÿ� �����ִ���Ȯ��