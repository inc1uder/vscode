// pthread_test2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <pthread.h>
#include <iostream>
#include <Windows.h>

using namespace std;

#pragma comment(lib,"pthreadVC2.lib")//�ز����٣����Ǹ��߱������ڱ����γɵ�.obj�ļ���.exe�ļ��м�һ����Ϣ��ʹ�������������ӿ��ʱ��Ҫȥ��pthreadVC2.lib����⣬��Ҫ��ȥ�ұ�Ŀ⡣��.exe�ļ���DLL Ҳ������д�������� pthreadVC2.dll��
//#define HAVE_STRUCT_TIMESPEC//�⽫����pthreads�ģ�Win32ͷ�����Ѿ���һ���ʵ���timespec����������Ĵ������������


#define NUM_THREAD 10 //�߳���

pthread_t tid[NUM_THREAD];	  //�߳�ID
pthread_mutex_t mut;   //�������

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
		int ret = pthread_create(&tid[i], NULL, say_hello, (void *)i);//�����߳� �������߳�id���̲߳������߳����к�����ַ�����к����Ĳ���
		if (ret != 0)//�����̳߳ɹ�������0
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
	pthread_exit(NULL);//�ȴ��߳��˳��󣬽��̽������������ǿ�ƽ������̴߳���δ��ֹ״̬
	return 0;
}

