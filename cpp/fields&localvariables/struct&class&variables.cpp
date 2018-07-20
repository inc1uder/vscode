#include<iostream>
using namespace std;

//extern int gl;//声明一个全局变量，gl将会在本程序中使用。

class A
{
public:
	A();
	int i;//feilds declaration 定义存在于类的某个对象里
	void f();
};

A::A()
{
	i=0;
	cout<<i<<endl;
}

struct B
{
	int i;
};

void g(struct B* p)//p是一个指向结构B的指针
{
	p->i=30;
	cout<<p->i<<endl;
}

void A::f()
{
	cout<<i<<endl;
	i=20;
	cout<<i<<endl;
}

int main()
{
	A a;//声明对象object
	B b;
	A aa;
	a.i=10;
	cout<<a.i<<endl;//*************很特别***************//
	a.f();
	cout<<a.i<<endl;
	aa.i=100;
	cout<<aa.i<<endl;
	aa.f();
	g(&b);
}
