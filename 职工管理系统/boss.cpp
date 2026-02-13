#include"boss.h"
Boss::Boss(int id, string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}
void Boss::Show_Info()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t职工岗位：" << this->Get_Department_Name()
		<< "\t岗位职责：管理公司所有事务" << endl;
}
string Boss::Get_Department_Name()
{
	return string("老板");
}