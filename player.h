#pragma once




class PLAYER {
	int x, y, w, h;
	int state;			//1�⺻����,2��������,3���̱����,4�̵�����
public:
	PLAYER() {};
	void setx(int);
	void sety(int);
	void setw(int);			//����
	void seth(int);
	//1�⺻����,2��������,3���̱����,4�̵�����
	void setstate(int);

	int getx();
	int gety();
	int getw();			//����
	int geth();
	//1�⺻����,2��������,3���̱����,4�̵�����
	int getstate();


};
