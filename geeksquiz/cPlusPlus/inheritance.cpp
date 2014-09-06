#include <iostream>
using namespace std;

// define an object of derived class, 
//all the base class's constructor will be called in the order of inheritand
//and destructor in reverse order
class Base1{
	public:
		Base1(){
			cout << "Base1's constructor called" << endl;
		}
		~Base1(){
			cout << "Base1's destructor called" << endl;
		}
};
class Base2{
	public:
		Base2(){
			cout << "Base2's constructor called" << endl;
		}
		~Base2(){
			cout << "Base2's destructor called" << endl;
		}
};
class Derived: public Base1,public Base2{
	public:
		Derived(){
			cout << "Derived's constructor called" << endl;
		}
		~Derived(){
			cout << "Derived's destructor called" << endl;
		}
};

//virtual inheritance
class Base{
	int arr[10];
};
class b1:public Base{};
class b2:public Base{};
class D1:public b1,public b2{};
class b3:virtual public Base{};
class b4:virtual public Base{};
class D2:public b3,public b4{};

//function call
class P{
	public:
		void print(){cout << " Inside P " << endl;}
};
class Q:public P{
	public:
		void print(){cout << " Inside Q " << endl;}
};
class R: public Q{};

/*
 A Base class pointer/reference can point/refer to a derived class object,
 but the other way is not possible
 */
//base class can only access base members or virual functions
class M{
	public:
		void show(){cout << " In M " << endl;}
};
class N:public M{
public:
	int x;
	void show(){cout << " In N " << endl;}
	N(){x=10;}
};

//hidden, fun(int i) is also hidden, because there is a fun() in Hd.
class H{
	public:
		int fun(){cout << "H::fun() called" << endl;}
		int fun(int i) {cout << "H::fun(int i) called" << endl;}
};
class Hd:public H{
	public:
		int fun(){cout << "Hd::fun() called" << endl;}
};

//object slicing
//when we assign an object of derived class to an object of base type,
//the derived class object is sliced off,
//andd all the data members inherited from base class are copied
class S{
	public:
		virtual string print() const{
			return "This is S base class";
		}
};
class Sd:public S{
	public:
		virtual string print() const{
			return "This is Sd derived class";
		}
};
void describe(S s){
	cout << s.print() << endl;
}

//construct base
class CC{
	public:
		int x,y;
	public:
		CC(int i,int j){x=i;y=j;}
};
class CCd:public CC{
	public:
		//CCd(int i,int j):x(i),y(j){} //compiler error
		CCd(int i,int j):CC(i,j){}
		void print(){cout << x << " " << y << endl;}
};

//diamond problem
class DP{
	protected:
		int a;
	public:
		DP(){a=0;}
};
//class DPd1:public DP{  //compiler error
class DPd1:virtual public DP{
	public:
		int c;
};
//class DPd2:public DP{  //compiler error
class DPd2:virtual public DP{
	public:
		int c;
};
class DPdd:public DPd1,public DPd2{
	public:
		void show(){cout << a << endl;}
};

//ambiguous
class A1{
	public:
		char c;
};
class A2{
	public:
		char c;
};
class Ad:public A1,public A2{
	public:
		void show(){
			//cout << c << endl; //compiler error
			cout << A1::c << endl;
		}
};

int main(int argc,char*argv[]){
	Derived d;
	cout << sizeof(D1) << endl;
	cout << sizeof(D2) << endl; //16 extra bytes are for bookkeeping information stored by the compiler
	R r;
	r.print();
	M *mm,m;
	N n;
	mm = &n;
	mm->show();
	//cout << mm->x << endl;  //base pointer can only access base class member or virtual functions
	Hd hd;
	//hd.fun(5); //compiler error
	hd.H::fun(5);
	//object slicing
	S s;
	Sd sd;
	describe(s);
	describe(sd);  //not a pointer, so still call base class
	//construct  base
	CCd ccd(10,10);
	ccd.print();
	//diamong problem
	DPdd dp;
	dp.show();
	//ambiguous
	Ad ad;
	ad.show();
	return 0;
}
