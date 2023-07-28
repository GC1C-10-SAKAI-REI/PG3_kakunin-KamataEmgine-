#pragma once
#include "Struct.h"

class Object
{
protected:
	//継承先で共有するもの
	ObjectInfo objInfo;

public:
	//ゲッター
	float GetObjX() { return objInfo.Center.X; }
	float GetObjY() { return objInfo.Center.Y; }
};