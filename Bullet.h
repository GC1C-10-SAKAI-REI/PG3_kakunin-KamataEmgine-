#pragma once
#include "FuncLib.h"

class Bullet
{
public:
	/*---メンバ変数---*/
	Object _bullet;			//弾
	FuncLib _funcLib;		//自作関数ライブラリ
	bool _isShot;			//発射フラグ

	/*---メンバ関数---*/
	Bullet(float spd, bool isShot);
	~Bullet();
	void Set(Vec2 center);
	void Move();
	void Draw();
	bool IsShot() { return _isShot; }
};