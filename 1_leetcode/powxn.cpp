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
double pow2(double x, int n) {
        double mini = 0.00000001;
        if(n==0) return 1;
        if(fabs(x-1.0)<0.00000001) return x;
        if(fabs(x+1.0)<0.00000001) return n%2?x:-x;
        bool flag = false;
        if(n<0){
            n = -n;
            flag = true;
        }
        double res = 1.0;
        while(n>0&&fabs(res)>0.00000001){
            res *= x;
            n--;
        } 
        return flag?1.0/res:res;
}

class Solution {
public:
    double pow(double x, int n) {
        if(n>0) return realPow(x,n);
        return 1/realPow(x,-n);
    }
    double realPow(double x,int n){
        if(n==0) return 1.0;
        if(n==1) return x;
        if(x==1) return x;
        if(x==-1) return (n%2)?x:-x;
        if(n%2){
            double res = realPow(x,n/2);
            return x*res*res;
        }
        double res = realPow(x,n/2);
        return res*res;
    }
};

int main(){
	int n;
	double x;
	cin>>n>>x;
	cout << pow(x,n) << endl;
}
