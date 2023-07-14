#pragma once
#include "Object.h"
#include "FuncLib.h"

class Enemy : public Object
{
private:
	FuncLib *fLib_;
public:
	Enemy();
	~Enemy();
	void Update();
	void Draw();
};