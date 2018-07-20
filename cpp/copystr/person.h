#ifndef _PERSON_H
#define _PERSON_H

class Person{
public:
	Person(const char *s);
	Person(const Person& w);
	~Person();
//private:
	char *name;
};

#endif
