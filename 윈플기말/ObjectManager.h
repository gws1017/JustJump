#pragma once
#include <fstream>
#include <iostream>

#include "player.h"
#include "object.h"
#include "Camera.h"

using namespace std;
//���ٴڰ� �÷��̾� �浹üũ 1�̸� �δ�ħ
bool collp2w(PLAYER, OBJECT);
//�÷��̾�� ������Ʈ�� ��ȣ�ۿ� �Ǵ��ϰ� �׿��°� �ٲ���
void adjustPlayer(PLAYER&, OBJECT*,int);
//int(�� ��ȣ) �� ���� ��ֹ� ��ġ�� �־��ְ� ��� ������Ʈ�� ������ �˷��ִ� �Լ�
int initObject(OBJECT*, int);
//ī�޶� ������ũ
void adjustCamera(CAMERA&,PLAYER);