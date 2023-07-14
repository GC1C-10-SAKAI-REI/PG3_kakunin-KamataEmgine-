#pragma once
#include "Novice.h"
#include "Struct.h"
#include <math.h>

class FuncLib
{
public:
	//正方形描画
	void DrawSquare(float posX, float posY, float size, unsigned int color);
	//円描画
	void DrawCircle(float posX, float posY, float rad, unsigned int color);
	//値無しのコメント
	void ScrPrintf(int x, int y, const char* comment);
	//値有りのコメント(int型)
	void ScrDPrintf(int x, int y, const char* comment, int data);
	//値有りのコメント(float型)
	void ScrFPrintf(int x, int y, const char* comment, float data);
	//移動関数
	void Move(char* keys, char* prekeys, Vec2& center, Vec2& velocity, float spd);
};