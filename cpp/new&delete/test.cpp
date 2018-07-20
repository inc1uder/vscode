#include<iostream>
using namespace std;

int main()
{
	int *p=0;

	cout<<p<<endl;

	delete p;

	int i=10;
	int *q;
	q=&i;
	cout<<"i address:"<<q<<" i value:"<<i<<endl;
	
	return 0;
}

