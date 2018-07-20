// pthread_test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 10

#pragma comment(lib,"pthreadVC2.lib")    //�ز����٣����Ǹ��߱������ڱ����γɵ�.obj�ļ���.exe�ļ��м�һ����Ϣ��ʹ�������������ӿ��ʱ��Ҫȥ��pthreadVC2.lib����⣬��Ҫ��ȥ�ұ�Ŀ⡣��.exe�ļ���DLL Ҳ������д�������� pthreadVC2.dll��
#define HAVE_STRUCT_TIMESPEC   //�⽫����pthreads�ģ�Win32ͷ�����Ѿ���һ���ʵ���timespec����������Ĵ������������

void *PrintHello(void *threadid)
{
	int tid;
	tid = (int)threadid;
	printf("Hello World!It's me,thread #%d!\n", tid);
	pthread_exit(NULL);
	return 0;
}
int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc, t;
	for (t = 0; t < NUM_THREADS; t++)
	{
		printf("In main:creating thread %d\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		if (rc)
		{
			printf("ERROR:return code from pthread_create() is %d\n", rc);
			return 0;
		}
	}
	pthread_exit(NULL);
	return 0;
}