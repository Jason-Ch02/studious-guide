#pragma once
#include<iostream>
using namespace std;
#include"点类.h"
class Circle//自定义了一个圆类的数据类型
{
public:
	void setR(int R);
	
	int getR();
	
	void setC(Point C);
	
	Point getC();

private:
	int r;
	Point center;//在一个类中可以包含另一个类，这样子，这一个属性可以代表着多个属性
};