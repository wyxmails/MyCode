#include <iostream>
using namespace std;

template <class T>
class Cal{
public:
	T n1,n2;
	virtual T getResult(){
		return 0;
	};
};
template <class T>
class Add : public  Cal<T>{
public:
	T getResult(){
		return this->n1+this->n2;
	}
};
template <class T>
class Sub : public Cal<T>{
public:
	T getResult(){
		return this->n1-this->n2;
	}
};
template <class T>
class Multi : public Cal<T>{
public:
	T getResult(){
		return this->n1*this->n2;
	}
};
template <class T>
class Divide : public Cal<T>{
public:
	T getResult(){
		if(this->n2==0){
			cerr << "\033[1;31m" << "ERROR: Dividor can not be zero!" << "\033[0m" << endl; 
			return 0;
		}
		return this->n1/this->n2;
	}
};
template <class T>
class CalFactory{
public:
	Cal<T> * createOp(char op){
		switch(op){
			case '+':
				return new Add<T>();
			case '-':
				return new Sub<T>();
			case '*':
				return new Multi<T>();
			case '/':
				return new Divide<T>();
			default:
				cerr << "\033[1;31m" << "ERROR: wrong operator!" << "\033[0m" << endl;
				return NULL;
		}
	}
};
int main(int argc,char*argv[]){
	double d1,d2;
	char op;
	cin>>d1>>op>>d2;
	Cal<double> *cal;
	CalFactory<double> cf;
	cal = cf.createOp(op);
	cal->n1 = d1;
	cal->n2 = d2;
	if(cal!=NULL) cout << cal->getResult() << endl;	
	return 0;
}
