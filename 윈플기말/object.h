#pragma once
#include <windows.h>
#include "player.h"

class OBJECT {
	int x, y;
	int w, h;
	int type;				//1�� �ٴ� 2�� �÷��� 3~��ֹ�
	HBITMAP hbit;
public:
	int getX();
	int getY();
	int getW();
	int getH();
	//1�� �ٴ� 2�� �÷��� 3~��ֹ�
	int getType();
	//������Ʈ�� �������
	int getocount();

	void create(int, int, int, int, int);
	void setX(int);
	void setY(int);
	void setW(int);
	void setH(int);
	//1�� �ٴ� 2�� �÷��� 3~��ֹ�
	void setType(int);
	void setHbit(HINSTANCE);

	void DrawObj(HDC&, HDC&);
};

//bool collp2w(PLAYER, OBJECT);