#include "FuncLib.h"

void FuncLib::DrawSquare(float posX, float posY, float size, unsigned int color)
{
	Novice::DrawBox(posX - size, posY - size, size * 2, size * 2, 0, color, kFillModeSolid);
}

void FuncLib::DrawCircle(float posX, float posY, float rad, unsigned int color)
{
	Novice::DrawEllipse(posX, posY, rad, rad, 0, color, kFillModeSolid);
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

void FuncLib::Move(char* keys, char* prekeys, Vec2& center, Vec2& velocity, float spd)
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

	//ê≥ãKâª
	if (velocity.X != 0.0f || velocity.Y != 0.0f)
	{
		//ê≥ãKâªópÇÃïœêî
		float length;
		length = sqrtf(velocity.X * velocity.X + velocity.Y * velocity.Y);

		//ê≥ãKâª
		float normal_X = velocity.X / length;
		float normal_Y = velocity.Y / length;

		//ÇµÇΩÇ‚Ç¬ÇspdÇ…Ç©ÇØÇÈ
		normal_X *= spd;
		normal_Y *= spd;

		//ç¿ïWÇ…ë´Ç∑
		center.X += normal_X;
		center.Y += normal_Y;
	}
}