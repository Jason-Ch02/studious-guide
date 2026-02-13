#include<iostream>
#include<fstream>
#include"workermanager.h"
using namespace std;
int main()
{
	Workermanager WM;
	int i=0;
	while (true)
	{
		WM.Show_Menu();
		cout << "请输入你的选择" << endl;
		cin >> i;
		switch (i)
		{
		case 0://退出系统
			WM.Exit_System();
			break;
		case 1://添加职工
			WM.Add_Worker();
			break;
		case 2://
			WM.Show_Worker();
			break;
		case 3://
			WM.Del_Worker();
			break;
		case 4://
			WM. Mod_Worker();
			break;
		case 5://
			WM. Find_Worker();
			break;
		case 6://
			WM. Sort_Worker();
			break;
		case 7://
			WM. Clear_File();
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}