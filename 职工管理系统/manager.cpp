#include"manager.h"

Manager::Manager(int id, string name, int deptId) 
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}
string Manager::Get_Department_Name()
{
	return string("经理");
}
void Manager:: Show_Info() 
{
		cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t职工岗位：" << this->Get_Department_Name()
		<< "\t岗位职责：完成老板交给的任务且下发任务给普通员工" << endl;
}
