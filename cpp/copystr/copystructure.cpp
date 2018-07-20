#include<iostream>
#include<string>
using namespace std;

static int objectCount=0;

class HowMany{
public:
	HowMany(){
	   objectCount++;
	   print("HowMany::HowMany()");
	}
	
	HowMany(const HowMany& o){objectCount++;print("HowMany::HowMany(HM)");}
	
	void print(const string& msg=""){
	if(msg.size()!=0)
	cout<<"print:"<<msg<<endl;
	cout<<"objectCount= "<<objectCount<<endl;
	}

	~HowMany(){
	    objectCount--;
	    print("HowMany::~HowMany"); 
	}
};

//拷贝构造
HowMany f(HowMany x){
	cout<<"begin of f() function"<<endl;
	x.print("x argument inside f()");
	cout<<"end of f() function"<<endl;
	return x;
}

int main()
{
	HowMany h;
	h.print("after construction of h");
	HowMany h2=f(h);
	h.print("after construction of h2");
	h2.print("after construction of h2 HM");
	return 0;
}
