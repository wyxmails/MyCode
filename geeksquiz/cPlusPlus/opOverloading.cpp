#include <iostream>
#include <cstdlib>
using namespace std;

//overload new
class Test{
private:
	void* operator new(size_t size){}
	void* operator new[](size_t size){}
};
//operators that cannot be overloaded
/*
 .(Member Access or Dot operator)
 ?:(ternary or Conditional Operator)
 ::(Scope Resolution Operator)
 .*(Pointer-to-member Operator)
 */

// postfix ++ and prefix ++
class Complex{
	private:
		int real;
		int imag;
	public:
		Complex(int r=0, int i=0){
			real = r;
			imag = i;
		}
		friend ostream & operator <<(ostream&out,const Complex&c);
		Complex operator ++(int); //postfix ++
		Complex &operator ++(); //prefix ++
};
ostream&operator<<(ostream&out,const Complex&c){
	out << c.real;
	out << " +1 " << c.imag << endl;
	return out;
}

Complex &Complex::operator ++(){
	real++;imag++;
	return *this;
}

Complex Complex::operator ++(int i){
	Complex c1(real,imag);
	real++;imag++;
	return c1;
}

//conversion operator overloaded
class A{
	int i;
public:
	A(int ii=0):i(ii){}
	void show(){cout << i << endl;}
};
class B{
	int x;
public:
	B(int xx):x(xx){}
	operator A() const{return A(x);}
};
void g(A a){
	a.show();
}

//ambiguous conversion operator
class Test2{
	int y;
};
class Test1{
	int x;
	Test2 t2;
public:
	operator Test2(){return t2;}
	operator int(){return x;}
};
void fun(int x){cout << "fun(int) called" << endl;}
//void fun(Test2 t){cout << "fun(Test2) called" << endl;} //compiler error: ambiguous call
void fun(Test2& t){cout << "fun(Test2) called" << endl;}


//new and new keyword
class Test3{
	int x;
public:
	void *operator new(size_t size);
	void operator delete(void*);
	Test3(int i){
		x = i;
		cout << "Test3 Constructor called" << endl;
	}
	~Test3(){cout << "Test3 Destructor called" << endl;}
};
void *Test3::operator new(size_t size){
	void *storage = malloc(size);
	cout << "new called" << endl;
	return storage;
}
void Test3::operator delete(void *p){
	cout << "delete called" << endl;
	free(p);
}

//function call operator overloaded
class Point{
	int x,y;
public:
	Point():x(0),y(0){}
	Point& operator()(int dx,int dy);
	void show(){cout << "x=" << x << ",y=" << y << endl;}
};
Point&Point::operator()(int dx,int dy){
	x = dx;
	y = dy;
	return *this;
}

//conversion operator cannot be global
//here is an example for new and delete can be global
class Myclass{
	int x;
public:
	friend void*operator new(size_t size);
	friend void operator delete(void*);
	Myclass(int i){
		x = i;
		cout << "Myclass Constructor called" << endl;
	}
	~Myclass(){cout << "Myclass Destructor called" << endl;}
};
void*operator new(size_t size){
	void *storage = malloc(size);
	cout << "new called" << endl;
	return storage;
}
void operator delete(void *p){
	cout << "delete called" << endl;
	free(p);
}

int main(){
	//Test *obj = new Test; //private new can not be called
	//Test *arr = new Test[10]; //private new[] can not be called
	/*postfix ++ and prefix ++*/
	Complex c1(10,15);
	cout << c1;
	Complex c2(10,15);
	c2++;
	++c2;
	cout << c2;
	/*conversion operator overloaded*/
	B b(10);
	g(b);
	g(20);
	/*ambiguous conversion operator*/
	Test1 t;
	fun(t);
	/*new and new keyword*/
	Test3 *m = new Test3(5);
	delete m;
	/*function call operator overloaded*/
	Point pt;
	pt(3,2);
	pt.show();
	//new and delete can be global
	Myclass *mc = new Myclass(5);
	delete mc;
	return 0;
}
