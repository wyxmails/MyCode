#include <iostream>
using namespace std;

class Base{
	public:
		int x;
		Base(){cout << "constructor" << endl;}
		Base(const Base&rr){cout << "copy constructor" << endl;}
		Base& operator=(Base&r){cout << "assignment"<< endl;}
};

int main(int argc,char*argv[]){
	Base a;// = {10};
	Base b = a;
	a = b;
	return 0;
}
