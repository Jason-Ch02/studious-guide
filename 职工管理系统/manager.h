#pragma once
#include"worker.h"
#include<iostream>
class Manager :public Worker
{
public:
	Manager(int id, string name, int deptId);
	virtual void Show_Info();
	virtual string Get_Department_Name();
}; 
