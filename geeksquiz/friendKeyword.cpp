#include <iostream>
using namespace std;

//friend can not be inherited
class A{
	//private: //both private and protected work
	protected:
		int x;
	public:
		A(){x=0;}
		friend void show();
};
class B:public A{
public:
	B():y(0){}
private:
	int y;
};
void show(){
	A a;
	B b;
	cout << "The default value of A::x = " << a.x << " ";
	//cout << "The default value of B::y = " << b.y;//compiler error, y is private and friend can not be inherited
}

class D;
class C{
	int c;
public:
	C():c(0){}
	void show(C&x,D&y);
};
class D{
	private:
		int d;
	public:
		D():d(0){}
		friend void C::show(C&x,D&y);
};
void C::show(C&x,D&y){
	x.c = 10;
	cout << "C::c= " << x.c << " D::d= " << y.d << endl;
}

int main(int argc,char*argv[]){
	C c;
	D d;
	c.show(c,d);
	return 0;
}
