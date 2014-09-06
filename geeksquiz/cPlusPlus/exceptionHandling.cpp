#include <iostream>
using namespace std;

void fun(){
	int x=-1;
	try{
		cout << "Inside try" << endl;
		if(x<0){
			throw x;
			cout << "After throw" << endl;
		}
	}catch(int x){
		cout << "Exception Caught" << endl;
	}
	cout << "After catch" << endl;
}

/*
 If both base and derived classes are caught as exceptions 
 then catch block of derived class must appear before the base class. 
 If we put base class first 
 then the derived class catch block will never be reached. 
 */
class Base{};
class Derived:public Base{};
/*It is compiler error to put catch all block before any other catch. 
  The catch(...) must be the last catch block.*/

class Test{
	public:
		Test(){cout << "Constructing an object of Test" << endl;}
		~Test(){cout << "Destructing an object of Test" << endl;}
};

/*
  The destructors are called in reverse order of constructors. 
  Also, after the try block, 
  the destructors are called only for completely constructed objects.
 */
class T1{
	static int count;
	int id;
public:
	T1(){
		count++;
		id = count;
		cout << "Constructing object number " << id << endl;
		if(id==4) throw 4;
	}
	~T1(){cout << "Destructing object number " << id << endl;}
};
int T1::count = 0;

/*
 true about exception handling in C++? 
 1) There is a standard exception class like Exception class in Java. 
 2) All exceptions are unchecked in C++, i.e., compiler doesn't check if the exceptions are caught or not. 
 3) In C++, a function can specify the list of exceptions that it can throw using comma separated list like following.
   void fun(int a, char b) throw (Exception1, Exception2, ..) 
 */

/*When an exception is thrown and not caught, the program terminates abnormally.
 int fun() throw (int)
 {
     throw 10;
 }
 */

int main(int argc,char*argv[]){
	fun();
	/*class order*/
	Derived d;
	try{
		throw d;
	}catch(Derived d){//Base b)
		cout << "Caught Base Exception" << endl;
	}catch(Base b){//Derived d)//this should be put before base
		cout << "Caught Derived Exception" << endl;
	}

	/* catch all order */
	try{
		throw 10;
	}catch (int param){
		cout << "int exception\n";
	}catch (...){ //this be put first will be compiler error
		cout << "default exception\n";
	}
	/*inner outter*/
	try{
		try{
			throw 20;
		}catch(int n){
			cout << "Inner catch" << endl;
			throw;
		}
	}catch(int x){
		cout << "Outer catch" << endl;
	}
	//class
	try{
		Test t1;
		throw 10;
	}catch(int i){
		cout << "Caught " << i << endl;
	}
	//complete
	try{
		T1 array[5];
	}catch(int i){
		cout << "Caught " << i << endl;
	}
	return 0;
}
