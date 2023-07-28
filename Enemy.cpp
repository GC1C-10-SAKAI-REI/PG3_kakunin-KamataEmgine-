#include "Enemy.h"

Enemy::Enemy()
{
	objInfo =
	{
		{360.0f,32.0f},
		{1.0f,0.0f},
		32.0f,
		4.0f,
		RED
	};
	fLib_ = new FuncLib();
}

Enemy::~Enemy()
{
	delete fLib_;
}

void Enemy::Update()
{
	if (objInfo.Center.X - objInfo.Rad > -5 && objInfo.Center.X + objInfo.Rad < 1285)
	{
		if (objInfo.Center.X - objInfo.Rad <= 0)
		{
			objInfo.Velocity.X = 1;
		}
		if (objInfo.Center.X + objInfo.Rad >= 1280)
		{
			objInfo.Velocity.X = -1;
		}
		objInfo.Center.X += objInfo.Velocity.X * objInfo.Spd;
	}	
}

void Enemy::Draw()
{
	fLib_->DrawCircle(objInfo.Center.X, objInfo.Center.Y, objInfo.Rad, objInfo.Color);
}