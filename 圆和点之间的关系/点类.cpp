#include"点类.h"

	void Point::setX(int X)//Point::意味着是在Point这个函数的作用域内的函数，可以调用Point内的数据
	{
		x = X;
	}
	int Point::getX()
	{
		return x;
	}
	void Point::setY(int Y)
	{
		y = Y;
	}
	int Point::getY()
	{
		return y;
	}
