#define WINDOW_WIDTH 1280 //ウィンドウの幅
#define WINDOW_HEIGHT 720 //ウィンドウの高さ

#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "GC2C_07_サカイレイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, WINDOW_WIDTH, WINDOW_HEIGHT);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player *player = new Player();
	Enemy *enemy = new Enemy();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0)
	{
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		/// ↓更新処理ここから
		
		player->Update(keys);
		enemy->Update();
		
		/// ↑更新処理ここまで
		

		
		/// ↓描画処理ここから
		
		player->Draw();
		enemy->Draw();
		
		/// ↑描画処理ここまで		

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0)
		{
			player->~Player();
			enemy->~Enemy();
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
