#include "person.h"
#include <stdio.h>

int main()
{
	Person p1("John");

	Person p2(p1);//相当于p2=p1

	printf("p1.name=%p\n",p1.name);
	printf("p2.name=%p\n",p2.name);
	return 0;
}
