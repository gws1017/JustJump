#include "player.h"
#include <iostream>
int ROWSPEED=3; 	//���� �̵��ӵ�
int COLSPEED=10;	//���� �̵��ӵ�
bool LEFTkey=0;//����Ű �������� 1�̸� ���� 0�̸� �ȴ���
bool RIGHTkey=0;//������Ű �������� 1�̸� ���� 0�̸� �ȴ���
bool UPkey=0;	//����Ű �������� 1�̸� ���� 0�̸� �ȴ���
bool DOWNkey=0;//�Ʒ���Ű �������� 1�̸� ���� 0�̸� �ȴ���
bool LRkey = 0;//���ʿ�����Ű ���ÿ� �������� 1�̸鴭�� 0�̸� �ȴ���
PLAYER::PLAYER()
{
	x = 80; //100
	y = 1600; //3800
	w = 50;  
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
{	w = i;
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
		LEFTkey = true;
		if (RIGHTkey == true)
		{
			LRkey = true;
			return;
		}
		COMMAND_move = 1;
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
		if (COMMAND_move == 1)
		{
			COMMAND_move = 0;
		}
		else {
			COMMAND_move = 2;
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
		else if(state==1){
			state = 3;	//���̴°Ŵ� ������ �������� �����ϴ�
		}
		return;
	}
	if (wParam == VK_SPACE)
	{
		if (state != 2&&state!=7)
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
		if(state==3)
			state = 1;
		return;
	}
	if (wParam == VK_LEFT )
	{
		LRkey = false;
		LEFTkey = false;
		if (RIGHTkey == true)
		{
			COMMAND_move = 2;
			return;
		}
		if (state == 4)		//�����̰������� ���� �����ٰ������� ��� �����ٴ»��� ���� ���� x
			state = 1;
		COMMAND_move = false;
		std::cout << "LEFT �E" << std::endl;

		return;
	}
	if (wParam == VK_RIGHT)
	{
		LRkey = false;
		RIGHTkey = false;
		if (LEFTkey == true)
		{
			COMMAND_move = 1;
			return;
		}
		if (state == 4)		//�����̰������� ���� �����ٰ������� ��� �����ٴ»��� ���� ���� x
			state = 1;
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
	if (state == 1)
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
			state = 7;			//�ٽ� ������ ����������
		
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




