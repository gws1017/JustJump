#pragma once
#include <fmod.h>
#include <windows.h>
class Sound {
public:
	FMOD_SYSTEM *System;
	FMOD_SOUND *bgmSound[2];	//2�� ����ݰ���
	FMOD_SOUND *effectSound[2];	//2�� ����Ʈ��ݰ���
	FMOD_CHANNEL *Channel[2];	//2�� ���+����Ʈ �ؼ� ä��

	void Sound_Setup();
};
