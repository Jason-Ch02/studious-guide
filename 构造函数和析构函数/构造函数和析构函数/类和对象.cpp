#include<iostream>
using namespace std;
class Phone
{
public:
	Phone(string)
	{
		cout << "Phone的构造函数的调用" << endl;
	}
	string name;
	~Phone()
	{
		cout << "Phone的析构函数的调用" << endl;
	}
};

class Person
{
public:
	Person(string name, string Pname) :p_name(name), p_phone(Pname)
	{
		cout << "Person的构造函数的调用" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数的调用" << endl;
	}
	string p_name;
	Phone p_phone;
};

void test()
{
	Person c1("mike", "ipone");
	cout << c1.p_name << "   have   " << c1.p_phone << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}