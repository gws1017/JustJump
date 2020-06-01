#include "ObjectManager.h"


//���ٴڰ� �÷��̾� �浹üũ 1�̸� �δ�ħ
bool collp2w(PLAYER player, OBJECT object)
//----------------------------------------
{
	int adjust = 10 ;
	if (object.getType() == 1)
	{
		if (object.getX() <= player.getx() && player.getx() <= object.getX() + object.getW())
		{
			if (object.getY() <= player.gety() + player.geth())
			{
				return 1;
			}
		}
	}
	else {
		if (object.getX() <= player.getx() && player.getx() <= object.getX() + object.getW())
		{
			if (object.getY() <= player.gety() + player.geth() && player.gety() + player.geth() <= object.getY() + adjust)
			{
				return 1;
				//����
			}
		}
	}
	
	return 0;
}


//�÷��̾�� ������Ʈ�� ��ȣ�ۿ� �Ǵ��ϰ� �׿��°� �ٲ���
void adjustPlayer(PLAYER& player, OBJECT* obj,int ocount)
{
	for (int i = 0; i < ocount; ++i)
	{
		if (player.getstate() == 2)		//�������϶� ��� �ٴ��̶��� �浹 �����Ѵ�
			break;
		if (player.getstate() == 3)		//������ 7�� �ƴϸ� �Ʒ��� �ȶ������ϱ�� ���� ���̱�,�������϶��� �浹ó�� ������
			break;
		if (collp2w(player, obj[i]))
		{
			player.sety(obj[i].getY() - player.geth());
			player.setstate(1);
			if (ROWSPEED == 1)
				ROWSPEED = 5;
			break;
		}
		else {
			if (player.getstate() == 4 || player.getstate() == 1)
				player.setstate(7);
		}
	}
}
//int(�� ��ȣ) �� ���� ��ֹ� ��ġ�� �־��ְ� ��� ������Ʈ�� ������ �˷��ִ� �Լ�
int initObject(OBJECT* obj, int mapnum)
{
	int x, y, w, h, type;
	int objcount = 0;
	
	ifstream in;
	if (mapnum == 10)
	{
		in.open("map/map_1.txt", ios::in);
	}
	else if (mapnum == 11)
	{
		in.open("map/map_2.txt", ios::in);
	}
	else {
		return 0;		//�� ���� �߸��ԷµǾ����� �״�� Ż��
	}




	if (in.is_open())
	{
		for (int i = 0; i < 100; ++i)
		{
			if (in.eof())
			{
				objcount = i;
				break;
			}
			in >> x >> y >> w >> h >> type;
			obj[i].setX(x);
			obj[i].setY(y);
			obj[i].setW(w);
			obj[i].setH(h);
			obj[i].setType(type);

		}
	}
	return objcount;
}

//ī�޶� ������ũ
void adjustCamera(CAMERA& camera,PLAYER player)
{
	//�÷��̾ ī�޶��� �߰������� �Ѿ�� ī�޶� �÷��ش�
	if (player.gety() < camera.gety() + 384)
	{
		if (camera.gety() <= 0)	//�ֻ����϶� �̵�����������
		{

		}
		else {
			camera.sety(player.gety() - 384);
		}
	}
	else if (player.gety() > camera.gety() + 384)
	{
		if (camera.gety() >= 3232)	//�������϶� �̵�����������
		{

		}
		else {
			camera.sety(player.gety() - 384);
		}
	}



}