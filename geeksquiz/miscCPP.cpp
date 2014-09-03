#include <iostream>
#include <vector>
using namespace std;

int x=1;
void fun(){
	int x=2;
	{
		int x = 3;
		cout << ::x << endl;
	}
}
//union share memories
union A{
	int a;
	unsigned int b;
	A(){a=10;}
	unsigned int getb(){return b;}
};
//private destructor make sure create object only by new
class Test{
	private:
		~Test(){cout << "destructor" << endl;}
	friend void destructTest(Test*);
};

void destructTest(Test*ptr){
	delete ptr;
}

class a{
	public:
		a(){cout << "a constructor" << endl;}
		~a(){cout << "destroy" << endl;}
};

int main(){
	fun();
	A obj;
	cout << obj.getb() << endl;
	Test *ptr = new Test;
	//Test pp; //error ~Test() is private
	destructTest(ptr);
	cout << "v1" << endl;
	vector<a*> *v1 = new vector<a*>;
	cout << "v2" << endl;
	vector<a> *v2 = new vector<a>;
	cout << "a3" << endl;
	a a3;
	return 0;
}
