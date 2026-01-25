#include<iostream>
#include"圆类.h"
#include"点类.h"
using namespace std;


/*class Point//自定义了一个点类的数据类型
{
public:
	void setX(int X)
	{
		x = X;
	}
	int getX()
	{
		return x;
	}
	void setY(int Y)
	{
		y = Y;
	}
	int getY()
	{
		return y;
	}

private:
	int x;
	int y;
};*/



/*class Circle//自定义了一个圆类的数据类型
{
public:
	void setR(int R)
	{
		r = R;
	}
	int getR()
	{
		return r;
	}
	void setC(Point C)
	{
		center = C;
	}
	Point getC()
	{
		return center;
	}
private:
	int r;
	Point center;//在一个类中可以包含另一个类，这样子，这一个属性可以代表着多个属性
};*/



void test(Circle& c, Point& b)//建立函数来进行判断
{
	int d =
		(c.getC().getX() - b.getX()) *
		(c.getC().getX() - b.getX()) +
		(c.getC().getY() - b.getY()) *
		(c.getC().getY() - b.getY());
	int r = c.getR() * c.getR();
	cout << d << endl;
	cout << r << endl;
	if (d == r)
	{
		cout << "点在圆上" << endl;
	}
	else if (d > r)
	{
		cout << "点在圆外" << endl;
	}
	else if (d < r)
	{
		cout << "点在圆内" << endl;
	}
}



int main()
{
	Circle c1;
	c1.setR(5);
	Point C1;
	C1.setX(0);
	C1.setY(0);
	c1.setC(C1);//创建一个圆  完毕

	Point p1;
	p1.setX(5);
	p1.setY(0);//创建一个点   完毕
	test(c1, p1);//把点和圆的数据传入函数
	system("pause");
	return 0;
}