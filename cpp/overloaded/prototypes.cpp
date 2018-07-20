常见运算符的格式

+-*/%^&|~
形式：
	const T operatorX(const T& l,constT& r) const;

! && || < <= == > >=
形式:
	bool T operatorX(const T& l,const T& r) const;

[]
形式：
	T& T::operator[](int index);

++ --
形式：
	const T& operator++();
	const T operator++(int);
	const T& operator--();
	const T operator--(int);

const Integer& Integer::operator++(){
	*this+=1;
	return *this;//++a返回自己的对象
}

const Integer Integer::operator++(int){
	Integer old(*this);
	++(*this);
	return old;//a++返回一个新的对象
}

 


