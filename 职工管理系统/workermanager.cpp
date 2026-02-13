#include"workermanager.h"
#include"manager.h"
#include"employee.h"
#include"boss.h"
#include<fstream>
#include<ostream>
#define FILENAME "empFile.txt"
using namespace std;

Workermanager::Workermanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if(ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = this->Get_EmpNum();
	cout << "职工人数为：" << num << endl;
	//更新职工人数
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的职工信息存放到数组中
	this->Get_File();
}

void Workermanager::Show_Menu()
{
	cout << "欢迎使用职工管理系统" << endl;
	cout << "0.退出系统" << endl;
	cout << "1.增加职工" << endl;
	cout << "2.显示职工" << endl;
	cout << "3.删除职工" << endl;
	cout << "4.修改职工" << endl;
	cout << "5.查找职工" << endl;
	cout << "6.排序职工" << endl;
	cout << "7.清空文件" << endl;
}

Workermanager::~Workermanager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[]this->m_EmpArray;
		m_EmpArray = NULL;
	}
}

void Workermanager::Exit_System()
{
	cout << "欢迎下次使用职工管理系统" << endl;
	system("pause");
	exit(0);
}

void Workermanager::Add_Worker()
{
	cout << "请输入要添加的职工数量" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//添加职工
		int newSize = this->m_EmpNum + addNum;//新职工总人数
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		//将原来空间下的职工数据存放到新空间下
		if (this->m_EmpArray!= nullptr)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int deptid;
			cout << "请输入第" << i + 1 << "个职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个职工的姓名" << endl;
			cin >> name;
			cout << "请选择第" << i + 1 << "个职工的职位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			Worker* worker = NULL;
			cin >> deptid;
			switch (deptid)
			{
			case 1:
				worker = new Employee(id, name, 1);
					break;
			case 2:
				worker = new Manager(id, name, 2);
					break;
			case 3:
				worker = new Boss(id, name, 3);
					break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;//创建职工职责，保存到数组
			delete[]this->m_EmpArray;//释放原来的数组
			this->m_EmpArray = newSpace;//更新数组的指向
			this->m_EmpNum = newSize;//更新新的职工人数
			this->FileIsEmpty = false;
			this->Save_File();
			cout << "添加成功" << endl;
		}

	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
void Workermanager::Save_File()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "  "
			<< this->m_EmpArray[i]->m_Name << "  "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	};
	ofs.close();
}

int Workermanager::Get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptid;
	int Num = 0;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		Num++;
	}
	return Num;
}
void Workermanager::Get_File()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptid;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		Worker* worker = NULL;
		if (deptid == 1)
		{
			worker = new Employee(id, name, deptid);
		}
		else if (deptid == 2)
		{
			worker = new Manager(id, name, deptid);
		}
		else
		{
			worker = new Boss(id, name, deptid);
		}
		this->m_EmpArray[index] = worker;//创建职工职责，保存到数组
		index++;
	}
	ifs.close();
}

void Workermanager::Show_Worker()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->Show_Info();//运用多态实现打印
		}
	}
	system("pause");
	system("cls");
}

int Workermanager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void Workermanager::Del_Worker()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)//前移法来删除职工
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新职工人数
			this->Save_File();//更新文件
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Workermanager::Clear_File()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;

	}
	else
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->FileIsEmpty = true;
			cout << "清空成功" << endl;
		}
		else
		{
			cout << "清空失败" << endl;
		}
	}
	system("pause");
	system("cls");
}
void Workermanager::Mod_Worker()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			delete this->m_EmpArray[index];//删除原来的职工信息
			int newId;
			string newName;
			int newDeptId;
			cout << "请输入新的职工编号" << endl;
			cin >> newId;
			cout << "请输入新的职工姓名" << endl;
			cin >> newName;
			cout << "请选择新的职工职位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			Worker* worker = NULL;
			cin >> newDeptId;
			switch (newDeptId)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = worker;//更新数组中的职工信息
			this->Save_File();//更新文件
			cout << "修改成功" << endl;

		}
		else
		{
			cout << "修改失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Workermanager::Find_Worker()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入要查找的职工编号" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			this->m_EmpArray[index]->Show_Info();
		}
		else
		{
			cout << "查找失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}
void Workermanager::Sort_Worker()
{
	int id;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
		{
			if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
			{
				Worker* temp = this->m_EmpArray[j];
				this->m_EmpArray[j] = this->m_EmpArray[j + 1];
				this->m_EmpArray[j + 1] = temp;
			}
		}
	}
	system("pause");
	system("cls");
}