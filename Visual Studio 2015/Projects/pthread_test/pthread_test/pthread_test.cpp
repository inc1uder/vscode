// pthread_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 10

#pragma comment(lib,"pthreadVC2.lib")    //必不可少，这是告诉编译器在编译形成的.obj文件和.exe文件中加一条信息，使得链接器在链接库的时候要去找pthreadVC2.lib这个库，不要先去找别的库。（.exe文件找DLL 也是这种写法，例如 pthreadVC2.dll）
#define HAVE_STRUCT_TIMESPEC   //这将告诉pthreads的，Win32头，你已经有一个适当的timespec，并会让你的代码编译正常。

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