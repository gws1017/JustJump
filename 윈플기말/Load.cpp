#include "Load.h"
#include "resource.h"
#include <windows.h>
#include <tchar.h>

HBITMAP LoadBK(HBITMAP hbit1, HINSTANCE g_hinst)
{
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/bk.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); //����η� ����
	return hbit1;

}
HBITMAP LoadObj(HBITMAP hbit1, HINSTANCE g_hinst, int type) //������Ʈ�� �̹��������� �ҷ���
{
	if (type == 1); // �ٴ�

	else if(type == 2) // ����
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/foothold2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); //����η� ����
	else if(type == 3)
	hbit1 = (HBITMAP)LoadImage(g_hinst, TEXT("img/foothold3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	return hbit1;
}