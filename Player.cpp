#include "Player.h"

Player::Player(float rad, float spd, unsigned int color)
{
	this->_player.Center.X = 640;
	this->_player.Center.Y = 360;
	this->_player.Velocity.X = 0;
	this->_player.Velocity.Y = 0;
	this->_player.Rad = rad;
	this->_player.Spd = spd;
	this->_player.Color = color;

	for (int i = 0; i < _magazine; i++)
	{
		_bullet[i] = { new Bullet(-10.0f,false) };
	}
}

Player::~Player()
{
	for (int i = 0; i < _magazine; i++)
	{
		delete _bullet[i];
	}	
}

void Player::Update(char* keys, char* preKeys)
{
	//自機の移動
	_funcLib.Move(keys, _player.Center, _player.Velocity, _player.Spd);

	//弾の生成
	for (int i = 0; i < _magazine; i++)
	{
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
		{
			if (!_bullet[i]->IsShot())
			{
				_bullet[i]->Set(_player.Center);
				break;
			}
		}
	}
	//弾の移動
	for (int i = 0; i < _magazine; i++)
	{
		_bullet[i]->Move();
	}
}

void Player::Draw()
{
	//自機
	_funcLib.DrawSquare(_player.Center.X, _player.Center.Y, _player.Rad, _player.Color);
	//弾
	for (int i = 0; i < _magazine; i++)
	{
		_bullet[i]->Draw();
	}
}