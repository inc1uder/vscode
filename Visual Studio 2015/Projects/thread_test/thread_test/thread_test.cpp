// thread_test.cpp : �������̨Ӧ�ó������ڵ㡣
//mutex ���ͬһ�����ݴ���ʱ������������ݾ������������߳�ͬʱ����һ��������

#include "stdafx.h"
#include <iostream>  
#include <thread>  
#include <Windows.h>  
#include <mutex>  

using namespace std;

mutex mu;  //�̻߳������  

int totalNum = 100;

void thread01()
{
	while (totalNum > 0)
	{
		mu.lock(); //ͬ��������  
		cout << totalNum << "thread 1" << endl;
		totalNum--;
		Sleep(100);
		mu.unlock();  //�������  
	}
	return;
}
void thread02()
{
	while (totalNum >0)
	{
		mu.lock();
		cout << totalNum << "thread 2" << endl;
		totalNum--;
		Sleep(100);
		mu.unlock();
	}
	return;
}

int main()
{
	thread task01(thread01);
	thread task02(thread02);
	task01.detach();
	task02.detach();
	system("pause");
}


