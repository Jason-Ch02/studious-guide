#pragma once//防止头文件重复包含
#include<iostream>
using namespace std;

class Point//自定义了一个点类的数据类型
{
public:
	void setX(int X);
	
	int getX();
	
	void setY(int Y);
	
	int getY();

private:
	int x;
	int y;
};
