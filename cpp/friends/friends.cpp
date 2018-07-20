#include <iostream>
using namespace std;

class X;//前置声明

class Y
{
public:
	void f(X*);//必须是指针
};

class X
{
private:
	int i;
public:
	void initialize();
	friend void g(X*,int);//g是X的朋友，即g可以使用X类的private
	friend void Y::f(X*);//Y类的f函数是X的朋友
	friend class Z;//Z类是X类的好朋友
};

void X::initialize()
{
	i=0;
}

void g(X* x,int i)
{
	x->i=i;
}

void Y::f(X* x)
{
	x->i=47;
}

class Z
{
private:
	int j;
};

int main ()
{
	return 0;
}

