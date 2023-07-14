#pragma once
#include "Novice.h"
#include "Struct.h"
#include <math.h>

class FuncLib
{
public:
	//�����`�`��
	void DrawSquare(float posX, float posY, float size, unsigned int color);
	//�~�`��
	void DrawCircle(float posX, float posY, float rad, unsigned int color);
	//�l�����̃R�����g
	void ScrPrintf(int x, int y, const char* comment);
	//�l�L��̃R�����g(int�^)
	void ScrDPrintf(int x, int y, const char* comment, int data);
	//�l�L��̃R�����g(float�^)
	void ScrFPrintf(int x, int y, const char* comment, float data);
	//�ړ��֐�
	void Move(char* keys, char* prekeys, Vec2& center, Vec2& velocity, float spd);
};