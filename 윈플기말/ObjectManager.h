#pragma once
#include "player.h"
#include "object.h"

//���ٴڰ� �÷��̾� �浹üũ 1�̸� �δ�ħ
bool collp2w(PLAYER, OBJECT);
//�÷��̾�� ������Ʈ�� ��ȣ�ۿ� �Ǵ��ϰ� �׿��°� �ٲ���
void adjustPlayer(PLAYER&, OBJECT*,int);