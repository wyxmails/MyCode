/*
 Write an algorithm which computes the number of trailing zeros in nfactorial.
 */
#include <iostream>
using namespace std;

int countZeros(int n){
	int two,five,ten;
	ten=five=two=0;
	for(int i=1;i<=n;++i){
		int tmp = i;
		while(tmp>1){
			if(tmp%10==0){
				ten++;
				tmp /= 10;
			}else if(tmp%5==0){
				five++;
				tmp /= 5;
			}else if(tmp%2==0){
				tmp /= 2;
				two++;
			}else break;
		}
	}
	return ten+min(five,two);
}

int countZeros2(int n){
	int five = 0;
	int c=1;
	int f=5;
	for(int i=5;n/i>0;i*=5)	
		five += n/i;
	return five;
}

long long facN(int n){
	if(n==1) return 1;
	return n*facN(n-1);
}

int main(int argc,char*argv[]){
	cout << countZeros(5) << endl;
	cout << countZeros2(5) << endl;
	cout << facN(5) << endl;
	cout << countZeros(11) << endl;
	cout << countZeros2(11) << endl;
	cout << facN(11) << endl;
	cout << countZeros(16) << endl;
	cout << countZeros2(16) << endl;
	cout << facN(16) << endl;
	cout << countZeros(18) << endl;
	cout << countZeros2(18) << endl;
	cout << facN(18) << endl;
	cout << countZeros(100) << endl;
	cout << countZeros2(100) << endl;
	return 0;
}
