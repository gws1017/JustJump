#include "ObjectManager.h"


//���ٴڰ� �÷��̾� �浹üũ 1�̸� �δ�ħ
bool collp2w(PLAYER player, OBJECT object)
//----------------------------------------
{
	int adjust = 5 ;
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