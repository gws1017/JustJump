#pragma once
#include <fmod.h>
#include <windows.h>
class Sound {
	int index;
public:
	int getindex();

	FMOD_SYSTEM *System;
	FMOD_SOUND *bgmSound[3];	//3�� ����ݰ���
	FMOD_SOUND *effectSound[5];	//2�� ����Ʈ��ݰ���
	FMOD_CHANNEL *Channel[2];	//2�� ���+����Ʈ �ؼ� ä��

	void Sound_Setup();
	void setindex(int);
};
