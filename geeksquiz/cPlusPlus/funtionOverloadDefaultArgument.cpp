#include <iostream>
using namespace std;
/*default arguments*/
//int fun(int x=0,int y=0,int z){ /*compiler error*/
int fun(int x,int y=0,int z=0){  /*correct*/
	return (x+y+x);
}
/*not allowed overloaded functions types*/
/*
 1) function declarations that differ only in the return type
 	int fun(int x,int y); void fun(int x,int y);
 2) functions that differ only by static keyword in return type
 	int fun(int x,int y); static int fun(int x,int y);
 3) parameter declarations that differ only in pointer*versus an array
 	int fun(int *ptr,int n); int fun(int ptr[],int n);
 4) two parameter declarations that differ only in their default arguments
 	int fun(int x,int y); int fun(int x,int y=10);
 */

//const member function
class Test{
	protected:
		int x;
	public:
		Test(int i):x(i){}
		void fun() const {cout << "fun() const " << endl;}
		void fun() {cout << "fun() " << endl;}
};

//declaration default arguments
int fun1(int=0,int=0);

int main(){
	cout << fun(10) << endl;
	Test t1(10);
	const Test t2(20);
	t1.fun();
	t2.fun();
	cout << fun1(5) << endl;;
	return 0;
}
int fun1(int x,int y){return (x+y);}
