#pragma once
#include "Bullet.h"

class Player
{
public:
	/*---メンバ変数---*/
	Object _player;						//自機
	static const int _magazine = 10;	//弾数
	Bullet *_bullet[_magazine];			//弾
	FuncLib _funcLib;					//自作関数ライブラリ

	/*---メンバ関数---*/
	//コンストラクタ
	Player(float rad, float spd, unsigned int color);
	//デストラクタ
	~Player();
	//更新処理
	void Update(char* keys, char* preKeys);
	//描画
	void Draw();
};