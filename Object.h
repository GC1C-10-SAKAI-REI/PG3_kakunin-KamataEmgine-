#pragma once
#include "Struct.h"

class Object
{
protected:
	//�p����ŋ��L�������
	ObjectInfo objInfo;

public:
	//�Q�b�^�[
	ObjectInfo GetObjInfo() { return objInfo; }
};