#include "Player.h"

Player::Player()
{
	objInfo =
	{
		{640.0f,500.0f},
		{0.0f,0.0f},
		32.0f,
		5.0f,
		WHITE
	};
	fLib_ = new FuncLib();
}

Player::~Player()
{
	delete fLib_;
}

void Player::Update(char *keys)
{
	fLib_->Move(keys, objInfo.Center, objInfo.Velocity, objInfo.Spd);

	fLib_->ScrFPrintf(0, 0, "obj.X = ", GetObjX());
	fLib_->ScrFPrintf(0, 20, "obj.Y = ", GetObjY());
}

void Player::Draw()
{
	fLib_->DrawCircle(objInfo.Center.X, objInfo.Center.Y, objInfo.Rad, objInfo.Color);
}