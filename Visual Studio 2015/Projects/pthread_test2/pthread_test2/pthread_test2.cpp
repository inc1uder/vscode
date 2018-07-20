// pthread_test2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <pthread.h>
#include <iostream>
#include <Windows.h>

using namespace std;

#pragma comment(lib,"pthreadVC2.lib")//必不可少，这是告诉编译器在编译形成的.obj文件和.exe文件中加一条信息，使得链接器在链接库的时候要去找pthreadVC2.lib这个库，不要先去找别的库。（.exe文件找DLL 也是这种写法，例如 pthreadVC2.dll）
//#define HAVE_STRUCT_TIMESPEC//这将告诉pthreads的，Win32头，你已经有一个适当的timespec，并会让你的代码编译正常。


#define NUM_THREAD 10 //线程数

pthread_t tid[NUM_THREAD];	  //线程ID
pthread_mutex_t mut;   //互斥对象

void *say_hello(void *threadid)
{
	int i;
	i = (int)threadid;
	//cout << "hello...." << endl;
	cout << "hello world! It's me,thread #" << i << endl;
	pthread_exit(NULL);
	return 0;
}

class Hello
{
public:
	static void *say_hello(void *threadid)
	{
		int i;
		i = (int)threadid;
		//cout << "hello...." << endl;
		cout << "hello world! It's me,thread #" << i << endl;
		pthread_exit(NULL);
		return 0;
	}
};

int main()
{
	for (int i = 0; i < NUM_THREAD; i++)
	{
		cout << "In main: creating thread #" << i << endl;
		int ret = pthread_create(&tid[i], NULL, say_hello, (void *)i);//创建线程 参数：线程id，线程参数，线程运行函数地址，运行函数的参数
		if (ret != 0)//创建线程成功，返回0
		{
			cout << "pthread_create error:error_code=" << ret << endl;
			return 0;
		}
		Sleep(100);
	}
	for (int i = 0; i < NUM_THREAD; i++)
	{
		pthread_join(tid[i], NULL);
	}
	pthread_exit(NULL);//等待线程退出后，进程结束，否则进程强制结束，线程处于未终止状态
	return 0;
}

