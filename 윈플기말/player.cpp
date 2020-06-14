#pragma comment (lib, "Msimg32.lib")
#include "player.h"
#include "Load.h"
#include <iostream>
int ROWSPEED = 3; 	//���� �̵��ӵ�
int COLSPEED = 10;	//���� �̵��ӵ�
bool LEFTkey = 0;//����Ű �������� 1�̸� ���� 0�̸� �ȴ���
bool RIGHTkey = 0;//������Ű �������� 1�̸� ���� 0�̸� �ȴ���
bool UPkey = 0;	//����Ű �������� 1�̸� ���� 0�̸� �ȴ���
bool DOWNkey = 0;//�Ʒ���Ű �������� 1�̸� ���� 0�̸� �ȴ���
bool LRkey = 0;//���ʿ�����Ű ���ÿ� �������� 1�̸鴭�� 0�̸� �ȴ���
PLAYER::PLAYER()
{
	x = 80; //100
	y = 3800; //3800
	w = 62; //���ڸ� Ű������ �浹üũ�� ����� �ȵ� �����ּ�!
	h = 50;
	state = 7;
	dir = 2;
	COMMAND_move = false;

}
void PLAYER::setx(int i)
{
	x = i;
}

void PLAYER::sety(int i)
{
	y = i;
}

void PLAYER::setw(int i)
{
	w = i;
}

void PLAYER::seth(int i)
{
	h = i;
}

void PLAYER::setstate(int i)
{
	state = i;
}

void PLAYER::setdir(int i)
{
	dir = i;
}
void PLAYER::setCMD_move(int i)
{
	COMMAND_move = i;
}

void PLAYER::setBit(HINSTANCE g_hinst)
{
	hbitwalk = LoadWalk(g_hinst);
	hbitex = LoadEx(g_hinst);
}

void PLAYER::initBitPos()
{
	bx = 0;
	by = 0;
	bw = 0;
	bh = 0;
}

//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѼ���
int PLAYER::getx()
{
	return x;
}

int PLAYER::gety()
{
	return y;
}

int PLAYER::getw()
{
	return w;
}

int PLAYER::geth()
{
	return h;
}
int PLAYER::getstate()
{
	return state;
}
int PLAYER::getdir()
{
	return dir;
}
int PLAYER::getCMD_move()
{
	return COMMAND_move;
}


//�÷��̾� ���� ����
void PLAYER::PlayerSetting(WPARAM wParam)
{
	if (wParam == VK_LEFT)
	{
		LEFTkey = true;				//Ű ��������
		if (RIGHTkey == true)		//�¿츦 ���ÿ� �������ִٸ� ������������
		{
			LRkey = true;
			return;
		}
		if (state == 7)
		{
			dir = 1;
		}
		else {
			COMMAND_move = 1;			//����Ű���������ִٸ� ��������(������ �������� ���¿��� ����������)
		}
		if (state == 1 || state == 4)
		{
			state = 4;
			dir = 1;
			std::cout << "LEFT����" << std::endl;
		}
		else if (state == 2)
		{
			ROWSPEED = 1;
			dir = 1;
		}
		return;
	}
	if (wParam == VK_RIGHT)
	{
		RIGHTkey = true;
		if (LEFTkey == true)
		{
			LRkey = true;
			return;
		}
		if (state == 7)
		{
			dir = 1;
		}
		else {
			COMMAND_move = 2;			//����Ű���������ִٸ� ��������(������ �������� ���¿��� ����������)
		}
		if (state == 1 || state == 4)
		{
			state = 4;
			dir = 2;
			std::cout << "RIGHT ����" << std::endl;
		}
		else if (state == 2)
		{
			ROWSPEED = 1;
		}

		return;
	}
	if (wParam == VK_UP)
	{
		UPkey = true;
		if (state == 5)
		{
			dir = 3;
		}
		//�̺κп� ��ٸ����� �浹 üũ�� �ϰ� true�� �ٿ� �Ŵ޸��� ���·� �ٲ��ٿ���
		return;
	}
	if (wParam == VK_DOWN)
	{
		DOWNkey = true;
		if (state == 5)
		{
			dir = 4;
		}
		else if (state == 1) {
			state = 3;	//���̴°Ŵ� ������ �������� �����ϴ�
		}
		return;
	}
	if (wParam == VK_SPACE)
	{
		if (state != 2 && state != 7)
		{
			state = 2;
			savey = y;
		}
		return;
	}
}
//�÷��̾� ������
void PLAYER::PlayerWaiting(WPARAM wParam)
{
	if (wParam == VK_DOWN)
	{
		DOWNkey = false;
		if (state == 3)
			state = 1;
		return;
	}
	if (wParam == VK_LEFT)
	{
		LRkey = false;
		LEFTkey = false;
		if (state != 7)				//�������� �������� �̵������� �۵��ϸ� �ȵȴ� ��������
		{
			if (RIGHTkey == true)	//Ű�� ���ÿ� �������־��ٸ� ���� �Ű���
			{
				COMMAND_move = 2;
				return;
			}
		}
		if (state == 4)		//�����̰������� ���� �����ٰ������� ��� �����ٴ»��� ���� ���� x
			state = 1;
		if (state != 7)	//�������� ������������� ��� ���������Ѵ�
			COMMAND_move = false;
		std::cout << "LEFT �E" << std::endl;

		return;
	}
	if (wParam == VK_RIGHT)
	{
		LRkey = false;
		RIGHTkey = false;
		if (state != 7)				//�������� �������� �̵������� �۵��ϸ� �ȵȴ� ��������
		{
			if (LEFTkey == true)
			{
				COMMAND_move = 1;
				return;
			}
		}
		if (state == 4)		//�����̰������� ���� �����ٰ������� ��� �����ٴ»��� ���� ���� x
			state = 1;
		if (state != 7)	//�������� ����������� ��� ������
			COMMAND_move = false;
		std::cout << "RIGTH ��" << std::endl;

		return;
	}
	if (wParam == VK_UP)
	{
		UPkey = false;
		return;
	}

}


//�÷��̾� ������
void PLAYER::move()
{
	static int adjustspd = 0;	//�������� x���� õõ�� �̵������ֱ� ����

	if (state == 1)
	{
		adjustspd = 0;		//�������� �� �Ĵ� 1���°� �ǹǷ� ���⼭ �ʱ�ȭ������
		if (LRkey == true)
		{

		}
		else {
			if (COMMAND_move == 1)
			{
				x -= ROWSPEED;
			}
			else if (COMMAND_move == 2)
			{
				x += ROWSPEED;
			}
		}
		//�������������� �����ϼ��֤���
	}
	else if (state == 2)	//���������϶��� ����������� �̵����ؾ��� 
	{
		if (COMMAND_move == 1)
		{

			x -= ROWSPEED;
		}
		else if (COMMAND_move == 2)
		{
			x += ROWSPEED;
		}
		//y -= 1;
		if (abs(y - savey) > 80) {
			y -= 3;
		}
		else {
			y -= COLSPEED;
		}
		if (abs((y - savey)) >= 100)	//30�ȼ���ŭ �����ߴٸ�
		{
			state = 7;			//�ٽ� ������ ����������
			savex = x;			//�̼����� x��ǥ�� �����(���ӵ��� �޴ٰ� �����ó�� ���ٿ���)
		}

	}
	else if (state == 3)
	{

	}
	else if (state == 4)
	{

		if (LRkey == true)
		{

		}
		else {
			if (COMMAND_move == 1)
			{
				x -= ROWSPEED;
			}
			else if (COMMAND_move == 2)
			{
				x += ROWSPEED;
			}
		}
	}
	else if (state == 5)
	{
		if (dir == 3)
		{
			y -= 1;
		}
		else if (dir == 4)
		{
			y += 1;
		}
	}
	else if (state == 7)
	{
		y += COLSPEED;
		if (adjustspd < 1000)
			adjustspd++;
		if (LEFTkey == true)
			if (adjustspd % 30 == 0)
				x -= ROWSPEED;
		if (RIGHTkey == true)
			if (adjustspd % 30 == 0)
				x += ROWSPEED;
		if (COMMAND_move == 1)
		{
			if (adjustspd <= 10)
			{
				x -= ROWSPEED;
			}
			if (adjustspd > 10)
			{
				if (adjustspd % 2 == 0)
					x -= ROWSPEED;
			}
			else if (adjustspd > 30)
			{
				if (adjustspd % 5 == 0)
					x -= ROWSPEED;
			}

			if (LEFTkey == 0)
				if (abs(x - savex) > 50)
					COMMAND_move = 0;

		}
		else if (COMMAND_move == 2)
		{
			if (adjustspd <= 10)
			{
				x += ROWSPEED;
			}
			if (adjustspd > 10)
			{
				if (adjustspd % 2 == 0)
					x += ROWSPEED;
			}
			else if (adjustspd > 30)
			{
				if (adjustspd % 5 == 0)
					x += ROWSPEED;
			}
			if (RIGHTkey == 0)
				if (abs(x - savex) > 50)
					COMMAND_move = 0;
		}
	}
}

//���¿����� ��Ʈ���� �����ϴ� �Լ�
void PLAYER::selectBit()
{
	if (state == 1 || state == 4)
	{
		hbitcur = hbitwalk;
		bw = 62;
		bh = 50;
	}

	else
		hbitcur = hbitex;
}

//��Ʈ���� �ٲ��ִ��Լ� (�ִϸ��̼�)
void PLAYER::BitMove()
{
	if (state == 4)
	{
		bx += 68;
		if (bx > 271) bx = 0;
	}

}

//�÷��̾ �׷���
void PLAYER::draw(HDC& mem1dc, HDC& pdc)
{
	pdc = CreateCompatibleDC(mem1dc);
	//�⺻ ������
	SelectObject(pdc, hbitcur);

	if (state == 1) // �������� 
	{

		if (dir == 1)//����
		{
			TransparentBlt(mem1dc, x, y, w, h, pdc, 0, 0, 62, 50, RGB(255, 255, 255));
		}
		else if (dir == 2)//������
		{
			TransparentBlt(mem1dc, x, y, w, h, pdc, 0, 50, 62, 50, RGB(255, 255, 255));
		}

	}
	else if (state == 4) //�̵�����
	{
		if (dir == 1)//����
		{
			TransparentBlt(mem1dc, x, y, w, h, pdc, bx, by, bw, bh, RGB(255, 255, 255)); //68 0 130 50
		}
		else if (dir == 2)//������
		{
			TransparentBlt(mem1dc, x, y, w, h, pdc, bx, by + 50, bw, bh, RGB(255, 255, 255));
		}


	}
	else if (state == 2 || state == 7) //�����ϰų� ��������
	{
		if (dir == 1)//����
		{
			TransparentBlt(mem1dc, x, y, w, h, pdc, 0, 107, 62, 48, RGB(255, 255, 255)); //68 0 130 50
		}
		else if (dir == 2)//������
		{
			TransparentBlt(mem1dc, x, y, w, h, pdc, 77, 107, 62, 48, RGB(255, 255, 255));
		}
	}
	else if (state == 3)
	{
		if (dir == 1)//����
		{
			TransparentBlt(mem1dc, x, y+26, w,26, pdc, 0, 161, 62, 26, RGB(255, 255, 255)); //68 0 130 50
		}
		else if (dir == 2)//������
		{
			TransparentBlt(mem1dc, x, y+26, w,26, pdc, 77, 161, 62, 26, RGB(255, 255, 255));
		}
	}
	DeleteObject(pdc);


}


void PLAYER::fall2save()
{
	savex = x;
}