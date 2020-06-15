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
	// x y �� ĳ������ �߽���ǥ�̰� w,h �� xy���� �¿�� ��ƴ���� �� ��ǥ�̴�. 
	x = 80; //100 ĳ������ �߽�x��ǥ
	y = 3600; //3800 ĳ������ �߽�y��ǥ
	w = 31; //ĳ���� width�� ����
	h = 25;	//ĳ���� hegiht�� ����
	state = 7; //ĳ������ state
	dir = 2;
	adjustspd = 0;
	stealth = 0;
	spike_hurt = 0;
	COMMAND_move = false;
	COMMAND_hurt = false;

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

void PLAYER::setadjspd(int i)
{
	adjustspd = i;
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
void PLAYER::setCMD_hurt(bool i)
{
	COMMAND_hurt = i;
}
void PLAYER::setstealth(int i)
{
	stealth = i;
}
void PLAYER::setspike_hurt(int i)
{
	spike_hurt = i;
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

int PLAYER::getadjspd()
{
	return adjustspd;
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
bool PLAYER::getCMD_hurt()
{
	return COMMAND_hurt;
}
int PLAYER::getstealth()
{
	return stealth;
}
int PLAYER::getspike_hurt()
{
	return spike_hurt;
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
			if (state == 4)		//�����̰� �������� 1�� �ؼ� ���߰��ϴ°��� �ٸ��� 1�ιٲٸ� ������
				state = 1;
			return;
		}

		if (state == 7)
		{
			dir = 1;	//������ �ٲ������� ���������´� ���� (�Ʒ� move���� �����̻� ������ ���ݾ��� �ٲ������)
		}
		else if (state == 1 || state == 4)
		{

			if (state == 1)//�����ִٰ� �����϶� �ѹ� �ٷ� �����������
			{

				state = 4;
				dir = 1;
				BitMove();
			}
			else {
				state = 4;
				dir = 1;
			}
			COMMAND_move = 1;	//1�̵� 4�� ������ �ϴ��� ���������¸� �ٲ���
			std::cout << "LEFT����" << std::endl;
		}
		else if (state == 2)
		{
			if (COMMAND_hurt != 1)	//�ĸ°��������� �� ���� �����ؿ�~
				ROWSPEED = 1;	//���������� ������ �ٲٷ��ϸ� ���ƽ�ϰ� �ٽ� ���°��� ������ �׷��� ���ߴ��ͺ��� ���� ����
			dir = 1;	//������ �ٲ������� ���������´� ����
		}
		else if (state == 3)
		{
			h += 12;
			y -= 12;
			state = 4;
			dir = 1;
			COMMAND_move = 1;
		}
		return;
	}
	if (wParam == VK_RIGHT)
	{
		RIGHTkey = true;	//Ű ��������
		if (LEFTkey == true)
		{
			LRkey = true;
			if (state == 4)		//�����̰� �������� 1�� �ؼ� ���߰��ϴ°��� �ٸ��� 1�ιٲٸ� ������
				state = 1;
			return;
		}
		if (state == 7)
		{
			dir = 2;	//������ �ٲ������� ���������´� ���� (�Ʒ� move���� �����̻� ������ ���ݾ��� �ٲ������)
		}
		else if (state == 1 || state == 4)
		{
			if (state == 1)//�����ִٰ� �����϶� �ѹ� �ٷ� �����������
			{

				state = 4;
				dir = 2;
				BitMove();
			}
			else {
				state = 4;
				dir = 2;
			}
			COMMAND_move = 2;	//1�̵� 4�� ������ �ϴ��� ���������¸� �ٲ���
			std::cout << "RIGHT ����" << std::endl;
		}
		else if (state == 2)
		{
			if (COMMAND_hurt != 1)	//�ĸ°��������� �� ���� �����ؿ�~
				ROWSPEED = 1;	//���������� ������ �ٲٷ��ϸ� ���ƽ�ϰ� �ٽ� ���°��� ������ �׷��� ���ߴ��ͺ��� ���� ����
			dir = 2;	//������ �ٲ������� ���������´� ����
		}
		else if (state == 3)
		{
			h += 12;
			y -= 12;
			state = 4;
			dir = 2;
			COMMAND_move = 2;
		}

		return;
	}
	if (wParam == VK_UP)
	{
		UPkey = true;

		if (state == 5)
		{
			COMMAND_move = 3;
		}
		//�̺κп� ��ٸ����� �浹 üũ�� �ϰ� true�� �ٿ� �Ŵ޸��� ���·� �ٲ��ٿ���
		return;
	}
	if (wParam == VK_DOWN)
	{
		DOWNkey = true;

		if (state == 5)
		{
			COMMAND_move = 4;
		}
		else if (state == 1) {

			state = 3;	//���̴°Ŵ� ������ �������� �����ϴ�
			h -= 12;		//���̸� Ű�� �پ�����Ѵ�.
			y += 12;
		}
		return;
	}
	if (wParam == VK_SPACE)
	{
		if (DOWNkey == true)//���׸��������� ��������
		{
			return;	//�ƹ��͵��������ʴ´� ����������
		}
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
		{
			h += 12;
			y -= 12;	//�ٽ� Ű �÷���
			state = 1;
		}
		return;
	}
	if (wParam == VK_LEFT)
	{
		if (RIGHTkey == true)		//������Ű�� �������־��ٸ� ����Ű�� ������ ���������� ����Ʋ����Ѵ�
		{
			dir = 2;
			if (state == 1)			//�Ѵٴ��������� ������ state==1�϶����� �ߵ��� �ȴ�. 
				COMMAND_move = 2;
		}
		else if (RIGHTkey == false)	//������Ű�� ���������� �ʾҴٸ� �����̴»��¿����� ��������Ѵ�.
		{
			if (state == 4)
			{
				state = 1;
				COMMAND_move = 0;	//�����̴� ������ �״������ ���������� �ʴ´�.
			}
			else if (state == 1)	//�������׼� �÷��̷����ؼ� (����Ű�� ���ÿ� Ű�� ������ �ٴڿ� ������ ���ÿ� ����) �̰�찡�ִµ�, �̶��� �����ֵ����Ѵ�.
			{
				COMMAND_move = 0;
			}
			if (DOWNkey == true)//���� ���׸����־��ٸ�
			{
				state = 3;
				h -= 12;
				y += 12;//������� ����������
			}
		}


		LRkey = false;				//�Ѱ��� ������ false
		LEFTkey = false;			//LEFTkey ������ false

		//std::cout << "LEFT �E" << std::endl;

		return;
	}
	if (wParam == VK_RIGHT)
	{
		if (LEFTkey == true)		//����Ű�� �������־��ٸ� ������Ű�� ������ �������� ����Ʋ����Ѵ�
		{
			dir = 1;
			if (state == 1)			//�Ѵٴ��������� ������ state==1�϶����� �ߵ��� �ȴ�. 
				COMMAND_move = 1;
		}
		else if (LEFTkey == false)	//����Ű�� ���������� �ʾҴٸ� �����̴»��¿����� ��������Ѵ�.
		{
			if (state == 4)
			{
				state = 1;
				COMMAND_move = 0;	//�����̴� ������ �״������ ���������� �ʴ´�.
			}
			else if (state == 1)	//�������׼� �÷��̷����ؼ� (����Ű�� ���ÿ� Ű�� ������ �ٴڿ� ������ ���ÿ� ����) �̰�찡�ִµ�, �̶��� �����ֵ����Ѵ�.
			{
				COMMAND_move = 0;
			}
			if (DOWNkey == true)//���� ���׸����־��ٸ�
			{
				state = 3;
				h -= 12;
				y += 12;//������� ����������
			}
		}



		LRkey = false;				//�Ѱ��� ������ false
		RIGHTkey = false;			//RIGHTkey ������ false
		//std::cout << "RIGTH ��" << std::endl;

		return;
	}
	if (wParam == VK_UP)
	{
		UPkey = false;
		return;
	}
	return;
}


//�÷��̾� ������
void PLAYER::move()
{

	if (state == 1)
	{
		adjustspd = 0;		//�������� �� �Ĵ� 1���°� �ǹǷ� ���⼭ �ʱ�ȭ������
		if (LRkey == true)
		{

		}
		else if (RIGHTkey == true)
		{
			dir = 2;
			state = 4;
		}
		else if (LEFTkey == true)
		{
			dir = 1;
			state = 4;
		}

		//else {
		//	if (COMMAND_move == 1)
		//	{
		//		x -= ROWSPEED;
		//	}
		//	else if (COMMAND_move == 2)
		//	{
		//		x += ROWSPEED;
		//	}
		//}
		//�������������� �����ϼ� ���µ� �� �������� ����
	}
	else if (state == 2)	//���������϶��� ����������� �̵����ؾ��� 
	{
		if (COMMAND_hurt == true)	//�ǰݴ��Ѱ��
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
			if (abs(y - savey) > 40) {
				y -= 3;
			}
			else {
				y -= COLSPEED / 2;
			}
			if (abs((y - savey)) >= 40)	//40�ȼ���ŭ �ǰݴ��ؼ� ���� ��¦��
			{
				state = 7;			//�ٽ� ������ ����������
				savex = x;			//�̼����� x��ǥ�� �����(���ӵ��� �޴ٰ� �����ó�� ���ٿ���)
			}
		}
		else if (COMMAND_hurt == false)	//�Ϲݻ���
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
	else if (state == 6)
	{
		ROWSPEED *= 4;
		stealth = 100;		//�����ð� 2��
		savey = y;			//�ǰݰ� ���ÿ� y��ǥ����(������ �������� ����)
		COMMAND_hurt = true;	//�ǰ��Լ� on
		state = 2;				//�ǰ��ϸ� �������� �ѹ� �� ���
	}
	else if (state == 7)
	{
		y += COLSPEED;					//�Ʒ��� ������
		if (adjustspd < 1000)			//1000������ �������� ������
			adjustspd++;
		if (LEFTkey == true)			//�������� �� ���� �ڴ�����������
			if (adjustspd % 30 == 0)	//Ÿ�̸Ӱ� 30�� ���ư������� �ѹ��� �Ȱ���
				x -= ROWSPEED;
		if (RIGHTkey == true)
			if (adjustspd % 30 == 0)
				x += ROWSPEED;
		if (COMMAND_move == 1)		//�������� �����̰��ִٸ�
		{
			if (adjustspd <= 10)	//�������� �� ���ٰ�
			{
				x -= ROWSPEED;
			}
			if (adjustspd > 10)		//10�� ���� ������ 2���� �ѹ��� ����
			{
				if (adjustspd % 2 == 0)
					x -= ROWSPEED;
			}
			else if (adjustspd > 30)	//2���� 10�� �� ������ ���� 5���� 1���� ��� ���� �̰� �����ʵ� �Ȱ��� ����
			{
				if (adjustspd % 5 == 0)
					x -= ROWSPEED;
			}

			if (LEFTkey == 0)				//50ĭ������ ��ó�������� ���� , �����Ŀ� ����Ű�� ���������� ������ϰ� �ƴϸ� �������� �� ����
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
			TransparentBlt(mem1dc, x - w, y - h, w * 2, h * 2, pdc, 0, 0, 62, 50, RGB(255, 255, 255));
		}
		else if (dir == 2)//������
		{
			TransparentBlt(mem1dc, x - w, y - h, w * 2, h * 2, pdc, 0, 50, 62, 50, RGB(255, 255, 255));
		}

	}
	else if (state == 4) //�̵�����
	{
		if (dir == 1)//����
		{
			TransparentBlt(mem1dc, x - w, y - h, w * 2, h * 2, pdc, bx, by, bw, bh, RGB(255, 255, 255)); //68 0 130 50
		}
		else if (dir == 2)//������
		{
			TransparentBlt(mem1dc, x - w, y - h, w * 2, h * 2, pdc, bx, by + 50, bw, bh, RGB(255, 255, 255));
		}


	}
	else if (state == 2 || state == 7) //�����ϰų� ��������
	{
		if (dir == 1)//����
		{
			TransparentBlt(mem1dc, x - w, y - h, w * 2, h * 2, pdc, 0, 107, 62, 48, RGB(255, 255, 255)); //68 0 130 50
		}
		else if (dir == 2)//������
		{
			TransparentBlt(mem1dc, x - w, y - h, w * 2, h * 2, pdc, 77, 107, 62, 48, RGB(255, 255, 255));
		}
	}
	else if (state == 3) //���̱�
	{
		if (dir == 1)//����
		{
			TransparentBlt(mem1dc, x - w, y - h, w * 2, h * 2, pdc, 0, 161, 62, 26, RGB(255, 255, 255)); //68 0 130 50
		}
		else if (dir == 2)//������
		{
			TransparentBlt(mem1dc, x - w, y - h, w * 2, h * 2, pdc, 77, 161, 62, 26, RGB(255, 255, 255));
		}
	}
	DeleteObject(pdc);


}


void PLAYER::fall2save()
{
	savex = x;
}

void PLAYER::stealthtime()
{
	if (stealth > 0)
		stealth--;
}
void PLAYER::spike_hurttime()
{
	if (spike_hurt < 0)
	{
		spike_hurt++;
		x -= 4;			//�������ΰ�
	}
	else if (spike_hurt > 0)
	{
		spike_hurt--;
		x += 4;
	}
}