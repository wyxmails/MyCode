#include <iostream>
using namespace std;

//loacal variable's name is same as member's name
class Test{
	private:
		int x;
	public:
		void setX(int x){
			this->x = x;
		}
		void print(){cout << "x= " << x << endl;}
};

//chained function calls
class Test1{
	private:
		int x;
		int y;
	public:
		Test1(int x=0,int y=0){
			this->x = x;
			this->y = y;
		}
		Test1 &setX(int a){x=a;return *this;}
		Test1 &setY(int b){y=b;return *this;}
		void print(){cout << "x= " << x << " y= " << y << endl;}
};

//compiler error
class Test3{
	private:
		int x;
	public:
		Test3(int x=0){ this->x = x; }
		void change(Test3*t){
			
			//this = t; /*compiler error, this is a const pointer, cannot be modified*/
		}
		void print(){cout << "x= " << x << endl;}
};

// static funtion and this pointer
class Test4{
	private:
		int x;
		int y;
	public:
		Test4(int x=0,int y=0){this->x = x;this->y = y;}
		static void fun1(){cout << "Inside fun1()";}
		static void fun2(){
			cout << "Inside fun2()";
			//this->fun1();  /*this is not available in static function, because static function can be called without object*/
		}
};

//delete this
class Test5{
	private:
		int x;
	public:
		Test5(){x=0;}
		void destroy(){
			//delete this; /*undefined behavior, core dump*/
		}
		void print(){cout << "x= " << x << endl;}
};

int main(int argc,char*argv[]){
	/*same name*/
	Test obj1;
	obj1.setX(5);
	obj1.print();
	/*chained funtion call*/
	Test1 obj2(6,6);
	obj2.setX(10).setY(20);
	obj2.print();
	/*compiler error*/
	Test3 obj3(7);
	Test3 *ptr = new Test3(10);
	obj3.change(ptr);
	obj3.print();
	/*static function*/
	Test4 obj4;
	obj4.fun2();
	/*delete this*/
	Test5 obj5;
	obj5.destroy();
	obj5.print();
	return 0;
}

