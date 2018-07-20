#include<iostream>
using namespace std;

class A{
public:
	A(){i=0;cout<<"A::A()"<<endl;}
	~A(){cout<<"~A::A(),i= "<<i<<endl;}
	void set(int i){this->i=i;}//this->i是指的类结构里的i；另外一个是set的参数
private:int i;
};

int main()
{
	A* p=new A[10];   //new函数，创建是个指向A的指针
	for(int i=0;i<10;i++)
	{
		p[i].set(i);
	}
	delete[] p;//delete函数*[]的作用？*
	return 0;
}
