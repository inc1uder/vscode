// thread_test2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  
#include <thread>  
#include <Windows.h>  

using namespace std;

void thread01(int args)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Thread " << args << "is working ！" << endl;
		Sleep(100);
	}
}
#define NUM_THREAD 3
int main()
{
	
	thread task01[NUM_THREAD];
	for (int i = 0; i < NUM_THREAD; i++)
	{
		task01[i] = thread(thread01,i);
		Sleep(50);
	}
	
	for (int i = 0; i < NUM_THREAD; i++)
	{
		//task01[i].detach();
		task01[i].join();
	}
	

	for (int i = 0; i < 5; i++)
	{
		cout << "Main thread is working ！" << endl;
		Sleep(200);
	}
	system("pause");
}