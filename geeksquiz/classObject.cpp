#include <iostream>
using namespace std;

class Empty{};

class structClassBase{
	public:
		int x;
};
class DerivedClass:structClassBase{};
struct DerivedStruct:structClassBase{};

class Test{
	static int x;
	int *ptr;
	static int z;
	int y;
	int y1;
	int y2;
};

class Test1{
	public:
		int i;
		void get();
};
void Test1::get(){
	cout << "Enter the value of i: " << endl;
	cin>>i;
}
Test1 t1;

int main(){
	cout << "Empty: " << sizeof(Empty) << endl;
	cout << "int: " << sizeof(int) << " int*: " << sizeof(int*) << endl;
	Test t;
	cout << "Test: " << sizeof(t) << " " << sizeof(Test*) << endl;
	Test1 t1;
	t1.get();
	cout << "value of i in local t1: " << t1.i << " " << "" << ::t1.i << endl;
	::t1.get();
	cout << "value of i in global t1: " << ::t1.i << " " << t1.i << endl;
	DerivedClass dc;
	//dc.x = 20;  // error inaccessible
	DerivedStruct ds;
	ds.x = 30;
	return 0;
}
