#include "Bullet.h"

Bullet::Bullet(float spd, bool isShot)
{
	this->_bullet.Center.X = -64;
	this->_bullet.Center.Y = -64;
	this->_bullet.Velocity.X = 0;
	this->_bullet.Velocity.Y = 0;
	this->_bullet.Rad = 16.0f;
	this->_bullet.Spd = spd;
	this->_bullet.Color = WHITE;
	this->_isShot = isShot;
}

Bullet::~Bullet()
{

}

void Bullet::Set(Vec2 center)
{
	//発射フラグオン
	_isShot = true;

	if (_isShot)
	{
		_bullet.Center.X = center.X;
		_bullet.Center.Y = center.Y;
	}
}

void Bullet::Move()
{
	if (_isShot)
	{
		_bullet.Velocity.Y = 1;
		_bullet.Center.Y += _bullet.Spd * _bullet.Velocity.Y;
	}
	if (_bullet.Center.Y <= -32.0f)
	{
		_bullet.Velocity.Y = 0;
		_isShot = false;
	}
}

void Bullet::Draw()
{
	_funcLib.DrawCircle(_bullet.Center.X, _bullet.Center.Y, _bullet.Rad, _bullet.Color);
}