#include <iostream>
using namespace std;

typedef struct test{
	int v;
	test(int v):v(v){cout << "test struct" << endl;}
}test;

class Test{
	public:
		Test(){cout << "Hello from Test() " << endl;}
}a;

class X{
	public:
		int x;
};

class Y{
	private:
		int y;
	public:
		Y(int i){  //conversion constructor
			y = i;
			cout << "Y constructor" << endl;
		}
};

int main(){
	cout << "Main Started" << endl;
	test t(1);
	X a = {10}; //why??
	X b = a;
	Y c = 5;  //conversion constructor
	cout << a.x << " " << b.x << " "  << endl;
	return 0;
}
