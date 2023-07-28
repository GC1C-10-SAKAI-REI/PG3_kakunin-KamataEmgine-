#pragma once
#include "Object.h"
#include "FuncLib.h"

class Player : public Object
{
private:
	FuncLib* fLib_;
public:
	Player();
	~Player();
	void Update(char *keys);
	void Draw();

};