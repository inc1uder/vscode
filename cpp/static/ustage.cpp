static local variables -> persistent storage
static member variables -> shared by all instances//所有对象共享
static member function -> shared by all instances,can only access static member variables


//全局变量

声明：
	extern int g_global;
定义：
	int g_global;

//静态变量

声明：
	static int s_local;
定义：
	s_local++;//只能在本文件使用

//静态对象

声明：
	static X my_x(10,20);//只做一次初始化，vptr

//全局对象

声明：
	#include
	X my_x(10,20);

//静态成员变量
//跟类有关，跟对象无关，同加同减，必须要有A.cpp放int A::i;类先构造函数后初始化静态成员初始化。
声明：
class A{
private:
	static int xx;
};
定义：
	调用i时需要加上int A::i

//静态成员函数
声明：
class A{
public:
	static void say(int ii){cout<<ii<<i<<endl;}
};
定义：

调用静态变量、函数，但是调用静态函数时不能有非静态变量也不能有this
A::xx;
A::say(0);

