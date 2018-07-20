#include <iostream>
using namespace std;

class A{
public:
	A():i(0){}
	int i;
};

class B:public A{
	int j;
public:
	B():j(30){}
	void f(){cout <<"B.j= "<<j<<endl;}
};
int main()
{
	A a;
	B b;
	cout<<a.i<<" "<<b.i<<endl;
	
	cout<<sizeof(a)<<" "<<sizeof(b)<<endl;

	int *p=(int*)&a;
	cout<<p<<" "<<*p<<endl;
	
	*p=20;
	cout<<*p<<endl;

	p=(int*)&b;
	cout<<p<<" "<<*p<<endl;

	p++;
	*p=50;
	b.f();
	
	return 0;
}
