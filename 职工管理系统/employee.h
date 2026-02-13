#pragma once
#include"worker.h"
#include<iostream>
class Employee :public Worker
{
public:
	Employee(int id, string name, int deptId);
	virtual void Show_Info();
	virtual string Get_Department_Name();
};