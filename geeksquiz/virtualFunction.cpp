#include <iostream>
using namespace std;

class Base{
	public:
		virtual void show(){cout << "In Base" << endl;}
};
class Derived:public Base{
	public:
		void show(){cout << "In Derived" << endl;}
};
/*true about pure virtual functions? 
  1) Their implementation is not known in a class where they are declared. 
  2) If a class has a pure virtual function, then the class becomes abstract class and an instance of this class cannot be created.
 */
/*abstract class
 cannot create instance
 but can create pointer or reference
 */
class vB{
	public:
		virtual void show()=0;
};

/*
  If we don't override the pure virtual function in derived class, 
  then derived class also becomes abstract class.
 */
class vD:public vB{};
class vD1:public vB{
	public:
		void show(){cout << "In vD1" << endl;}
};

/*
  constructor cannot be virtual, 
  destructor can be virtual
 */

//virtual destructor
class vDes{
	public:
		vDes(){cout << "vDes Constructor" << endl;}
		virtual ~vDes(){cout << "vDes Destructor" << endl;}
};
class vDesD:public vDes{
	public:
		vDesD(){cout << "vDesD Constructor" << endl;}
		virtual ~vDesD(){cout << "vDesD Destructor" << endl;}
};

/*static function cannot be virtual
 Static functions are class specific and may not be called on objects. 
 Virtual functions are called according to the pointed or referred object.
 */

//VPTR
class A{
	public:
		virtual void fun();
};
class B{
	public:
		void fun();
};

//D::fun() is virtual
class C{
	public:
		virtual void fun(){cout << "C::fun()" << endl;}
};
class D:public C{
	public:
		void fun(){cout << "D::fun()" << endl;}
};
class E:public D{
	public:
		void fun(){cout << "E::fun()" << endl;}
};


int main(int argc,char*argv[]){
	Base *bp = new Derived;
	bp->show();
	Base &br = *bp;
	br.show();
	Base *bp1,b;
	Derived d;
	bp = &d;
	bp->show();
	bp = &b;
	bp->show();
	//abstract class
	//vB vb; //compiler error
	vB *vbp;
	//vD vd; //compiler error
	vD *vdp;
	vD1 vd1;
	vB&vb1=vd1;
	vb1.show();
	//virtual destructor
	vDes *test; //nothing output
	vDes *vdes = new vDesD();
	delete vdes;
	//VPTR
	int asize= sizeof(A),bsize=sizeof(B);
	if(asize==bsize) cout << "a==b" << endl;
	else if(asize>bsize) cout << "a>b" << endl;
	else cout << "a<b" << endl;
	//
	D *dp = new E();
	dp->fun();
	//scope resolution
	C *cp = new D();
	cp->C::fun();
	return 0;
}
