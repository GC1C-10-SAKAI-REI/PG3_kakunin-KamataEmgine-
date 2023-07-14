#include "FuncLib.h"

void FuncLib::DrawSquare(float posX, float posY, float size, unsigned int color)
{
	Novice::DrawBox(int(posX - size), int(posY - size), int(size * 2), int(size * 2), 0, color, kFillModeSolid);
}

void FuncLib::DrawCircle(float posX, float posY, float rad, unsigned int color)
{
	Novice::DrawEllipse(int(posX), int(posY), int(rad), int(rad), 0, color, kFillModeSolid);
}

void FuncLib::ScrPrintf(int x, int y, const char* comment)
{
	Novice::ScreenPrintf(x, y, "%s", comment);
}

void FuncLib::ScrDPrintf(int x, int y, const char* comment, int data)
{
	Novice::ScreenPrintf(x, y, "%s = %d", comment, data);
}

void FuncLib::ScrFPrintf(int x, int y, const char* comment, float data)
{
	Novice::ScreenPrintf(x, y, "%s = %f", comment, data);
}

void FuncLib::Move(char* keys, Vec2& center, Vec2& velocity, float spd)
{
	velocity.X = 0;
	velocity.Y = 0;

	if (keys[DIK_W])
	{
		velocity.Y = -1;
	}
	if (keys[DIK_S])
	{
		velocity.Y = 1;
	}
	if (keys[DIK_A])
	{
		velocity.X = -1;
	}
	if (keys[DIK_D])
	{
		velocity.X = 1;
	}

	//正規化
	if (velocity.X != 0.0f || velocity.Y != 0.0f)
	{
		//正規化用の変数
		float length;
		length = sqrtf(velocity.X * velocity.X + velocity.Y * velocity.Y);

		//正規化
		float normal_X = velocity.X / length;
		float normal_Y = velocity.Y / length;

		//したやつをspdにかける
		normal_X *= spd;
		normal_Y *= spd;

		//座標に足す
		center.X += normal_X;
		center.Y += normal_Y;
	}
}