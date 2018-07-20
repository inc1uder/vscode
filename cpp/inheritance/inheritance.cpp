#include <iostream>
using namespace std;

class A{
public:
	A(int j):i(j) {cout<<"A::A()"<<endl;}
	~A(){cout<<"A::~A()"<<endl;}
	void print() {cout<<"A::print() */ :"<<i<<endl;}
	void print(int i) {cout<<"A::print(i)"<<i;print();}
	void set(int ii){i=ii;}
private:
	int i;
};

class B : public A{
public:
	B():A(15){cout<<"B::B()"<<endl;}
	~B(){cout<<"B::~B()"<<endl;}
	void print(){cout<<"B::print()"<<endl;}
	void f(){
		set(20);
		//i=30;父类的私有变量不能够直接使用。
		print();}
};

int main ()
{
	B b;
	b.set(10);
	b.print();
	b.f();
	b.A::print(10);//子类调用父类相同名的函数
	return 0;
}
