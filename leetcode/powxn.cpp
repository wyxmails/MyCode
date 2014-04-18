/*Implement pow(x, n).*/
#include <iostream>
using namespace std;

double pow(double x, int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	double mini = 0.00000000001;
	if((x-1.0)*(x-1.0)<mini||(x-0.0)*(x-0.0)<mini){
		if(n==0) return 1.0;
		else return x;
	}
	if((x+1.0)*(x+1.0)<mini){
		if(n%2) return x;
		else return -x;
	}
	double res=1.0;
	if(n>=0){
		for(int i=0;i<n&&res*res>mini;++i){
		res *= x;
		}
	}else{
		for(int i=0;i>n&&res*res>mini;--i){
		res /= x;
		}
	}
	return res;
}

int main(){
	int n;
	double x;
	cin>>n>>x;
	cout << pow(x,n) << endl;
}
