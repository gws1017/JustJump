#pragma once
#include <windows.h>
#include "player.h"



class OBJECT {
	int x, y;					//������Ʈ�� x y �� ���ʻ���� �����̴�.
	int w, h;
	int type;					//1~100 �÷��� 101~��ֹ�
	int index;					//�ִϸ��̼� ������ �迭�� �ε����� �ٲ��־� �̹����� �ٲ۴�
	HBITMAP hbit;				
public:
	//������Ʈ�� x y �� ���ʻ���� �����̴�.
	int getX();
	int getY();
	int getW();
	int getH();
	int getindex();

	//1~100 �÷��� 101~��ֹ�
	int getType();
	//������Ʈ�� �������
	int getocount();
	
	void create(int, int, int, int, int);
	//������Ʈ�� x y �� ���ʻ���� �����̴�.
	void setX(int);
	//������Ʈ�� x y �� ���ʻ���� �����̴�.
	void setY(int);
	void setW(int);
	void setH(int);
	//1~100 �÷��� 101~��ֹ�
	void setType(int);
	void setHbit(HINSTANCE);

	//������Ʈ �ִϸ��̼� ���� ����ϴ��Լ�
	void IndexChange();
	//������Ʈ�� �׷���
	void DrawObj(HDC&, HDC&);
};

//bool collp2w(PLAYER, OBJECT);