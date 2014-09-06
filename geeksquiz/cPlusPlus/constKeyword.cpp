#include <iostream>
using namespace std;

void fun1(){
	const char*p = "12345";
	const char**q = &p;
	*q = "abcde";
	const char*s = ++p;
	p = "XYZWVU";
	cout << *++s << endl;
}

//const function: cannot modify data members of its class

//A const object can only call const functions
class Point{
	int x,y;
public:
	Point(int i=0,int j=0){x=i;y=j;}
	int getX() const {return x;}
	int getY() {return y;}
};

int main(int argc,char*argv[]){
	fun1();
	const Point t;
	cout << t.getX() << endl;
	//cout << t.getY() << endl; //compiler error
	return 0;
}
