#pragma once
#include <windows.h>
#include "Camera.h"
#include "player.h"
#define MAPWIDTH 1024
#define MAPHEIGHT 4098
class MAP {
	HBITMAP hbitbk;
	HBITMAP hbitui;
	HBITMAP hbithp;
public:
	
	void DrawBK(HDC&, HDC&, RECT&);
	//����â
	void DrawUi(HDC&, HDC&, CAMERA);
	//HP��
	void DrawHP(HDC&, HDC&, CAMERA,PLAYER);
	void CreateMap(HINSTANCE);
	void CreateUi(HINSTANCE);
	void CreateHP(HINSTANCE);
};
