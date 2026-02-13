#pragma once	//防止头文件重复包含
#include<iostream>
#include"worker.h"
class Workermanager
{
public:
	int m_EmpNum;//职工人数
	Worker ** m_EmpArray;//职工数组指针
	bool FileIsEmpty;//文件是否为空
	Workermanager();
	~Workermanager();
	void Show_Menu();
	void Exit_System();
	void Add_Worker();
	void Save_File();
	void Get_File();
	int Get_EmpNum();
	void Show_Worker();
	void Del_Worker();
	int IsExist(int id);
	void Mod_Worker();
	void Find_Worker();
	void Sort_Worker();
	void Clear_File();
};