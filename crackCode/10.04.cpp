#include <iostream>
using namespace std;

int myDivide(int a,int b){
	int res = 0;
	if(b==0) return -1;
	int t=b;
	if(a>=0&&b>0){
		while(t<a){
			t += b;
			res++;
		}
	}else if(a<0&&b<0){
		while(t>a){
			t += b;
			res++;
		}
	}else if(a<0){
		a = -a;
		while(t<a){
			t += b;
			res--;
		}
	}else if(b<0){
		t = -t;
		while(t<a){
			t -= b;
			res--;
		}
	}
	return res;
}

int myMinus(int a,int b){
	int i;
	if(a>b){
		i=1;
		while(b+i<a) i++;
	}else{
		i=0;
		while(b+i>a) i--;
	}
	return i;
}

int myMult(int a,int b){
	int res = 0;
	if(a>0){
		for(int i=0;i<a;++i) res += b;
	}else if(b>0){
		for(int i=0;i<b;++i) res += a;
	}else{
		for(int i=0;i<-a;++i) res -= b;
	}
	return res;
}

int main(int argc,char*argv[]){
	int a,b;
	a=3;b=4;
	cout << "a: " << a << " b: " << b << endl;
	cout << myMinus(a,b) << endl;
	cout << myMult(a,b) << endl;
	cout << myDivide(a,b) << endl;
	a=10;b=3;
	cout << "a: " << a << " b: " << b << endl;
	cout << myMinus(a,b) << endl;
	cout << myMult(a,b) << endl;
	cout << myDivide(a,b) << endl;
	a=-1;b=6;
	cout << "a: " << a << " b: " << b << endl;
	cout << myMinus(a,b) << endl;
	cout << myMult(a,b) << endl;
	cout << myDivide(a,b) << endl;
	a=8;b=-6;
	cout << "a: " << a << " b: " << b << endl;
	cout << myMinus(a,b) << endl;
	cout << myMult(a,b) << endl;
	cout << myDivide(a,b) << endl;
	a=-2;b=-6;
	cout << "a: " << a << " b: " << b << endl;
	cout << myMinus(a,b) << endl;
	cout << myMult(a,b) << endl;
	cout << myDivide(a,b) << endl;
	a=0;b=0;
	cout << "a: " << a << " b: " << b << endl;
	cout << myMinus(a,b) << endl;
	cout << myMult(a,b) << endl;
	cout << myDivide(a,b) << endl;
	return 0;
}
