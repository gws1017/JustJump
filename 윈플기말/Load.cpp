#include "Load.h"
#include "resource.h"
#include <windows.h>
#include <tchar.h>

//HBITMAP LoadBlack(HBITMAP hbit1, HINSTANCE g_hinst)
//{
//	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/bk_black.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); //����η� ����
//	return hbit1;
//
//}

HBITMAP LoadBK(HBITMAP hbit1, HINSTANCE g_hinst)
{
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/bk.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); //����η� ����
	return hbit1;

}
//���� Uiǥ��
HBITMAP LoadUi(HBITMAP hbit, HINSTANCE g_hinst)
{
	hbit = (HBITMAP)LoadImage(g_hinst, TEXT("img/Ui.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); //����η� ����
	return hbit;

}
//HP Ui ǥ��
HBITMAP LoadHP(HBITMAP hbit, HINSTANCE g_hinst)
{
	hbit = (HBITMAP)LoadImage(g_hinst, TEXT("img/Ui_HP.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); //����η� ����
	return hbit;

}
//��� Ui
HBITMAP LoadDieNotice(HINSTANCE g_hinst)
{
	HBITMAP hbit;
	hbit = (HBITMAP)LoadImage(g_hinst, TEXT("img/notice3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); //����η� ����
	return hbit;
}
//��� Ui ���º�ȭ
HBITMAP LoadDieNoticeChange(HINSTANCE g_hinst,int i)
{
	HBITMAP hbit=NULL;
	if(i==0)
		hbit = (HBITMAP)LoadImage(g_hinst, TEXT("img/notice3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); //����η� ����
	else if (i == 1)
		hbit = (HBITMAP)LoadImage(g_hinst, TEXT("img/notice4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); //����η� ����
	else if (i == 2)
		hbit = (HBITMAP)LoadImage(g_hinst, TEXT("img/notice5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); //����η� ����
	return hbit;
}


HBITMAP LoadObj(HBITMAP hbit1, HINSTANCE g_hinst, int type) //������Ʈ�� �̹��������� �ҷ���
{
	if (type == 1) // �ٴ�
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/foothold1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	else if(type == 2) // ����
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/foothold2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); //����η� ����
	else if(type == 3)
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/foothold3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	else if (type == 4) //�����̾� ��Ʈ
		hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/belt.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	else if(type==101)
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/nasa.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	else if (type == 102)
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/breakpipe1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	else if(type == 103)
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/gas.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	else if (type == 106 || type == 107)
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/gear.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	else if (type == 201)
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/Portal_sprite.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	else if (type == 301)
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/breakpipe1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	return hbit1;
}

HBITMAP LoadWalk(HINSTANCE g_hinst) // ĳ���� �̹����� �ҷ��� �¿� �ȱ�
{
	HBITMAP hbit1;
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/char_sprite.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	return hbit1;
}
HBITMAP LoadEx(HINSTANCE g_hinst) // ĳ���� �̹����� �ҷ��� ���̱� ���� ��Ÿ��
{
	HBITMAP hbit1;
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/char_sprite2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	return hbit1;
}