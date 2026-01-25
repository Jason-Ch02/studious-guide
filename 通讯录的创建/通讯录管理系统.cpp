#include<iostream>
using namespace std;
#define max 1000;
void showmenu()
{
	cout << "1.添加联系人" << endl;
	cout << "2.显示联系人" << endl;
	cout << "3.删除联系人" << endl;
	cout << "4.查找联系人" << endl;
	cout << "5.修改联系人" << endl;
	cout << "6.清空联系人" << endl;
	cout << "0.退出通讯录" << endl;
};

struct person        //联系人结构体
{
	string name;
	int age;
	int sex;
	int phone;
	string address;
};


struct addressbooks        //通讯录结构体
{
	struct person amout[1000];
	int size;
};

void addperson(addressbooks* abs)        //添加联系人的函数,由case1跳转过来
{
	if (abs->size == 1000)
	{
		cout << "通讯录已满，无法添加" << endl;
		system("pause");
	}
	else
	{
		string name;
		int age;
		int sex;
		int phone;
		string address;
		cout << "请输入姓名:    " << endl;;
		cin >> name;
		abs->amout[ abs->size].name = name;
		cout << "请输入年龄：    " << endl;
		cin >> age;
		abs->amout[abs->size].age = age;
		cout << "请输入性别：    " << endl;
		cout << " 男------1" <<endl;
		cout << " 女------2" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->amout[abs->size].sex = sex;
				break;
			}
		}
		cout << "请输入电话：    " << endl;
		cin >> phone;
		abs->amout[abs->size].phone = phone;
		cout << "请输入住址：    " << endl;
		cin >> address;
		abs->amout[abs->size].address = address;
		abs->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}

};

void show(addressbooks*abs)
{
	
	if (abs->size == 0)//先判断是否存在联系人
	{
		cout << "当前通讯录为空，请去添加联系人。   " << endl;
		
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名为：  " << abs->amout[i].name << "\t";
			cout << "年龄为：  " << abs->amout[i].age << "\t";
			cout << "性别为：  " << (abs->amout[i].sex == 1 ? "男" : "女") << "\t";//三目运算符
			cout << "电话为:   " << abs->amout[i].phone << "\t";
			cout << "住址为：  " << abs->amout[i].address << endl;
		}
	}
		system("pause");
		system("cls");
	};

int exist(addressbooks* abs,string name)
{
    for (int i = 0; i < abs->size; i++)
		{
			if (name == abs->amout[i].name)
			{
				return i;
			}
			return -1;
		}
	system("pause");
	system("cls");
}

void deleteperson(addressbooks* abs,string name)
{
	
	int ret = exist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->size; i++)
		{
			abs->amout[i] = abs->amout[i + 1];
		}
		abs->size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void findperson(addressbooks* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (name == abs->amout[i].name)
		{
			cout << "姓名为：  " << abs->amout[i].name << "\t";
			cout << "年龄为：  " << abs->amout[i].age << "\t";
			cout << "性别为：  " << (abs->amout[i].sex == 1 ? "男" : "女") << "\t";//三目运算符
			cout << "电话为:   " << abs->amout[i].phone << "\t";
			cout << "住址为：  " << abs->amout[i].address << endl;
		}
		else {
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

void modifyperson(addressbooks*abs,string name)
{
	int ret = exist(abs, name);
	if (ret != -1)
	{
		string name;
		int age;
		int sex;
		int phone;
		string address;
		cout << "找到联系人" << endl;
		cout << "请输入姓名:    " << endl;;
		cin >> name;
		abs->amout[ret].name = name;
		cout << "请输入年龄：    " << endl;
		cin >> age;
		abs->amout[ret].age = age;
		cout << "请输入性别：    " << endl;
		cout << " 男------1" << endl;
		cout << " 女------2" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->amout[ret].sex = sex;
				break;
			}
		}
		cout << "请输入电话：    " << endl;
		cin >> phone;
		abs->amout[ret].phone = phone;
		cout << "请输入住址：    " << endl;
		cin >> address;
		abs->amout[ret].address = address;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void cleanbook(addressbooks* abs)
{
	abs->size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

int main()
{
	addressbooks abs;
	person pp;
	abs.size = 0;
	
	while (true)
	{
		int select = 0;
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&abs);
			break;
		case 2:
			show(&abs);
			break;
		case 3:
		{
			cout << "输入你要删除的人的姓名" << endl;
			string name;
			cin >> name;
			exist(&abs, name);
			deleteperson(&abs, name);
		}
		break;
		case 4:
		{
			cout << "请输入你要查找的人的名字" << endl;
			string name;
			cin >> name;
			findperson(&abs, name);
		}
		break;
		case 5:
		{
			cout << "请输入你要修改的人的名字" << endl;
			string name;
			cin >> name;
			exist(&abs, name);
			modifyperson(&abs, name);
		}
			break;
		case 6:
		//{
			/*cout << "确定要清空联系人吗" << endl;
			int act = 0;
		    cout << "确定-----1" << endl;
			cout << "取消------2" << endl;
			cin >> act;
		    while (true)
			{
				if (act == 1)
				{
					cleanbook(&abs);
				}
				else {
					system("pause");
					system("cls");
				}
			}
		}*/
			cleanbook(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}