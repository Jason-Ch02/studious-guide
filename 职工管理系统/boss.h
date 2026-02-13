#pragma once
#include"worker.h"
#include<iostream>
class Boss :public Worker
{
public:
	Boss(int id, string name, int deptid);
	virtual void Show_Info();
	virtual string Get_Department_Name();
};
