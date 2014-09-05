#include <iostream>
using namespace std;
/*static methods can only access static members(data and methods*/

class Test{
	static int x;
public:
	Test() {x++;}
	static int getX(){return x;}
};
int Test::x = 0;

class Player{
	private:
		int id;
		static int next_id;
	public:
		int getID(){return id;}
		Player(){id = next_id++;}
};

int Player::next_id = 1;

class A{
	private:
		int x;
	public:
		A(int _x) { x = _x; }
		int get() { return x; }
};

class B{
	static A a;
public:
	static int get(){return a.get();}
};
A B::a(0);//this is a must, or else will compiler error

class Test1{
	private:
		static int count;
	public:
		Test1& fun();
};
int Test1::count = 0;
Test1& Test1::fun(){
	Test1::count++;
	cout << Test1::count << " ";
	return *this;
}

class Test2{
	public:
		//void fun(); //compiler error
		static void fun();
};
//static void Test2::fun(){ //compiler error
void Test2::fun(){
	cout << "fun() is static" << endl;
}

int main(int argc,char*argv[]){
	cout << Test::getX() << " ";
	Test t[5];
	cout << Test::getX() << endl;
	Player p1;
	Player p2;
	Player p3;
	cout << p1.getID() << " ";
	cout << p2.getID() << " ";
	cout << p3.getID() << endl;
	B b;
	cout << b.get() << endl;
	Test1 t1;
	t1.fun().fun().fun().fun();
	cout << endl;
	Test2::fun();
	return 0;
}
