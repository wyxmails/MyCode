#include <iostream>
using namespace std;

class base{
	public:
		int a;
		base(){
			cout << "Constructing base" << endl;
		}
		virtual ~base(){ //correct 
		//~base(){  // derived class may not be destructed
			cout << "Destructing base" << endl;
		}
};

class derived:public base{
	public:
		int b;
		derived(){
			cout << "Constructing derived" << endl;
		}
		~derived(){
			cout << "Destructing derived" << endl;
		}
};

int i;
class A{
	public:
		A(){i=5;}
		~A(){i=10;}
};
int foo(){
	i=3;
	A ob;
	return i;
}

class B{
	int id;
	static int count;
public:
	B(){
		count++;
		id = count;
		cout << "constructor for id: " << id << endl;
	}
	~B(){
		cout << "destructor for id: " << id << endl;
	}
};
int B::count=0;
int main(){
	derived *d = new derived();
	base *b = d;
	delete b;
	cout << foo() << endl;  // destructor is called after return value was assigned
	B obj[3];
	return 0;
}
