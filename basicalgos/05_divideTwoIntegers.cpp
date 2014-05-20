#include <iostream>
using namespace std;

unsigned int mydiv(unsigned int dividend,unsigned int divisor){
	if(dividend<divisor) return 0;
	if(dividend==divisor) return 1;

	int bitcnt=0;
	int num = divisor;
	if((num<<1)>num){
		num = divisor<<1;
		while(dividend>num){
			bitcnt++;
			if((num<<1)>num) num <<= 1;
			else break;
		}
	}
	return mydiv(dividend-(divisor<<bitcnt),divisor)+(1<<bitcnt);
}

int divide(int dividend,int divisor){
	bool neg1,neg2;
	neg1 = dividend<0;
	neg2 = divisor<0;
	unsigned int u_dividend;
	unsigned int u_divisor;
	if(dividend<0){
		u_dividend = (unsigned int)(dividend^-1)+1;
	}else u_dividend = dividend;
	if(divisor<0){
		u_divisor = (unsigned int)(divisor^-1)+1;
	}else u_divisor = divisor;
	int result = mydiv(u_dividend,u_divisor);
	if(neg1^neg2) result = (result^-1) +1;
	return result;
}	

int main(){
	int dividend,divisor;
	cin>>dividend>>divisor;
	cout << divide(dividend,divisor) << endl;
	return 0;
}
