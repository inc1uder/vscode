template <class T>//用T表示某个成员变量的类型，某个函数的返回类型
class Vector{
public:
	Vector(int);
	~Vector();
	Vector(const Vector&);
	Vector& operator=(const Vector&);//运算符重载
	T& operator[](int);//运算符重载
private:
	T* m_elements;
	int m_size;
}

//usage	

Vector<int> v1(100);
Vector<Complex> v2(256);

v1[20]=10;
v2[20]=v1[20];//ok if int->complex

template <class T>
Vector<T>::Vector(int size):m_size(size){
	m_elements=new T[m_size];
}

temlpate <class T>
T& Vector<T>::operator[](int indx){
	if(index<m_size&&index>0){
	  return m_elements[index];
	}
	else{......}
}

