#pragma once
#include <windows.h>
#include "player.h"

class OBJECT {
	int x, y;					//������Ʈ�� x y �� ���ʻ���� �����̴�.
	int w, h;
	int type;					//1~100 �÷��� 101~��ֹ�
	HBITMAP hbit;
public:
	//������Ʈ�� x y �� ���ʻ���� �����̴�.
	int getX();
	//������Ʈ�� x y �� ���ʻ���� �����̴�.
	int getY();
	int getW();
	int getH();
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

	void DrawObj(HDC&, HDC&);
};

//bool collp2w(PLAYER, OBJECT);