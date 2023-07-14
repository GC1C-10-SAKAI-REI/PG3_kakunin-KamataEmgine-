#pragma once
#include "Struct.h"

class Object
{
protected:
	//継承先で共有するもの
	ObjectInfo objInfo;

public:
	//ゲッター
	ObjectInfo GetObjInfo() { return objInfo; }
};