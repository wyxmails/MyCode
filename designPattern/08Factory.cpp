#include <iostream>
using namespace std;

class Operator{
public:
	virtual int getResult(int n1,int n2){}
};
class OpAdd:public Operator{
public:
	int getResult(int n1,int n2){
		return n1+n2;
	}
};
class OpSub:public Operator{
public:
	int getResult(int n1,int n2){
		return n1-n2;
	}
};
class Factory{
public:
	virtual Operator* createOp(){}
};
class FacAdd:public Factory{
public:
	Operator* createOp(){
		return new OpAdd();
	}
};
class FacSub:public Factory{
public:
	Operator* createOp(){
		return new OpSub();
	}	
};

int main(int argc,char*argv[]){
	int num1,num2;
	cout << "please enter operands: " << endl;
	cin>>num1>>num2;
	char c;
	cout << "please enter operator: " << endl;
	cin>>c;
	Factory *f = NULL;
	switch(c){
		case '+':
			f = new FacAdd();
			break;
		case '-':
			f = new FacSub();
			break;
		default:
			cout << "wrong operator!" << endl;
			return 0;

	}
	Operator *op = f->createOp();

	cout << op->getResult(num1,num2) << endl;
	return 0;
}
