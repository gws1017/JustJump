#include "ObjectManager.h"


//������Ʈ�� �÷��̾� �浹üũ 1�̸� �δ�ħ
bool collp2w(PLAYER player, OBJECT object)
//----------------------------------------
{
	int adjust = 10 ;
	if (object.getType() == 1)	//���ٴ��϶�
	{
		if (object.getX() <= player.getx() && player.getx() <= object.getX() + object.getW())
		{
			if (object.getY() <= player.gety() + player.geth())
			{
				return 1;
			}
		}
	}
	else if(object.getType()<=100) {	//�÷����϶�
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
	if (player.getx() -player.getw()< 0)
	{
		player.setx(player.getw());
		player.setCMD_move(0);
	}
	else if (player.getx() + player.getw() > 1023)
	{
		player.setx(1023 - player.getw());
		player.setCMD_move(0);
	}
	for (int i = 0; i < ocount; ++i)
	{
		if (player.getstate() == 2)		//�������϶� ��� �ٴ��̶��� �浹 �����Ѵ�
			break;
		if (player.getstate() == 3)		//������ 7�� �ƴϸ� �Ʒ��� �ȶ������ϱ�� ���� ���̱�,�������϶��� �浹ó�� ������
			break;
		if (collp2w(player, obj[i]))
		{
			player.sety(obj[i].getY() - player.geth());

			if (player.getstate() == 7) //�������� ���϶� �ε����� ?
			{
				if (obj[i].getType() <101)			//�ٵ� �װ� ���ٴ��̿���?
				{
					if(LEFTkey==0&&RIGHTkey==0)	//�ٵ� �׿��߿��� �ƹ�Ű�� �ȴ������־��� ? 
						player.setCMD_move(false);	//�׷� ����������� ���°� ���ߵ������ش�.
				}
			}
			player.setstate(1);
			if (ROWSPEED == 1)
				ROWSPEED = 3;
			return;			//�ϳ��� �ε����ٸ� �״�� Ż���Ѵ�
		}
	}
	
	if (player.getstate() == 4 || player.getstate() == 1)	//�ϳ��� ���ε������� ���߿��ִ°Ŵϱ� ���������Ѵ�
	{
		player.setstate(7);
		player.fall2save();		//�������� ������ x��ǥ�� ���
	}

}
//int(�� ��ȣ) �� ���� ��ֹ� ��ġ�� �־��ְ� ��� ������Ʈ�� ������ �˷��ִ� �Լ�
int initObject(OBJECT* obj, int mapnum, HINSTANCE g_hinst)
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
			obj[i].setHbit(g_hinst);

		}
	}
	return objcount;
}

//ī�޶� ������ũ
void adjustCamera(CAMERA& camera,PLAYER player)
{
	//�÷��̾��� �Ӹ��κ��� ī�޶��� ��������� �Ѿ�� �ٷ� ����ٰ��Ѵ�
	if (player.gety()-player.geth() < camera.gety())
	{
		if (camera.gety() <= 0)	//�ֻ����϶� �̵�����������
		{

		}
		else {
			camera.sety(player.gety() - player.geth());		//384�� �� ũ�� 768�� ����
		}
	}
	else if (player.gety()+player.geth() > camera.gety() + 768)	//ĳ������ �߹ٴ��� ī�޶���� �Ѿ��
	{
		if (camera.gety() >= 3232)	//�������϶� �̵�����������
		{

		}
		else {
			camera.sety(player.gety()+player.geth() - 768);	//�����ش�
		}
	}else if (camera.gety()+600 != player.gety())		//ī�޶� ������ ��ġ�� �����ʴٸ�
	{
		if (player.getstate() != 7)							//�׸��� ������������ ī�޶� �ٲ��ָ� �ʹ� ������ �̶��� ������
		{
			if (camera.gety() + 540 > player.gety())		//�󸶳� �ָ��ִ��Ŀ� ���� �ӵ��� �ٸ����ؼ� ī�޶� ��������Ѵ�
			{
				camera.sety(camera.gety() - 4);
			}
			else if (camera.gety() + 580 > player.gety())
			{
				camera.sety(camera.gety() - 2);
			}
			else if (camera.gety() + 600 > player.gety())
			{
				camera.sety(camera.gety() - 1);
			}
			else if (camera.gety() + 700 < player.gety())
			{
				camera.sety(camera.gety() + 10);
			}
			else if (camera.gety() + 680 < player.gety())
			{
				camera.sety(camera.gety() + 8);
			}
			else if (camera.gety() + 660 < player.gety())
			{
				camera.sety(camera.gety() + 6);
			}
			else if (camera.gety() + 640 < player.gety())
			{
				camera.sety(camera.gety() + 4);
			}
			else if (camera.gety() + 620 < player.gety())
			{
				camera.sety(camera.gety() + 2);
			}
			else if (camera.gety() + 600 < player.gety())
			{
				camera.sety(camera.gety() + 1);
			}
		}
	}


}