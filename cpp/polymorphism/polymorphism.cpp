#include <iostream>
using namespace std;

class A{
public:
	A():i(10){}
	virtual void f(){cout<<"A():f()"<<i<<endl;}
	void g(){cout<<"A():G()"<<endl;}
	int i;
};

class B:public A{
public:	
	B():j(20){}
	virtual void f(){cout<<"B():F()"<<j<<endl;}
	int j;
};
int main ()
{
	A a,b;
	B c;

	a.f();
	b.f();
	c.f();

	cout<<sizeof(a)<<endl;
	cout<<sizeof(b)<<endl;
	cout<<sizeof(c)<<endl;

	int *p=(int*)&a;
	int *q=(int*)&b;
	int *r=(int*)&c;

	cout<<*p<<endl<<*q<<endl<<*r<<endl;

	p++;
	q++;
	r++;

	cout<<*p<<endl<<*q<<endl<<*r<<endl;

	r++;
	cout<<*r<<endl;

	int *x=(int*)*p;//vtable
	int *y=(int*)*q;
	int *z=(int*)*r;

	cout<<x<<endl<<y<<endl<<z<<endl;
	
	return 0;
}
