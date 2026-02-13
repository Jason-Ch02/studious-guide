#pragma once
#include<string>
using namespace std;
class Worker
{
public:
	virtual void Show_Info() = 0;//显示职工信息
	virtual string Get_Department_Name() = 0;//获取职工部门名称
	int m_Id;
	string m_Name;
	int m_DeptId;
};