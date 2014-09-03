#include <iostream>
using namespace std;

int &fun(){
	static int x = 10;
	return x;
}

int &fun1(){
	int x = 10;
	return x;
}

int main(){
	fun() = 30;
	cout << fun() << endl;
	fun1() = 30;
	cout << fun1() << endl;
	int x = 10;
	int & ref = x;
	ref = 20;
	cout << "x= " << x << endl;
	x = 30;
	cout << "ref= " << ref << endl;
	return 0;
}
