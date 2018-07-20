#include<iostream>
#include<string>
using namespace std;

class Integer{
public:
	Integer(int n=0):i(n){}
	const Integer operator+(const Integer& n) const{
	//operator 类型const Integer 运算符+ Integer.this 类型const 
	return Integer(i+n.i);
	}
	const Integer operator-() const{
	return(-i);
	}
//private:
	int i;
};

int main(){
	Integer x(1),y(5),z1,z2,z3;
	//z1.i;
	z1=x+y;
	z2=x+3;
	z3=-x;	
	cout<<x.i<<y.i<<z1.i<<z2.i<<z3.i<<x.i<<endl;
	return 0;
}
