#include <iostream>
#include <climits>
using namespace std;

int previous(int n){
	int i=0;
	//find the first 0, and count 1s
	int cnt = 0;
	for(;i<32;++i){
		if(n&(1<<i)) cnt++;
		else break;
	}
	cout << "i: " << i << endl;
	//find the first 1 after the first 0
	for(i=i+1;i<32;++i){
		if(n&(1<<i)){
			n = n&(~(1<<i));
			n = n|(1<<i-1);
		   	break;
		}
	}
	if(i>=31) return -1;
	if(cnt){
		n = n&((~0)<<(i-1));
		n = n|(((1<<cnt)-1)<<(i-cnt-1));
	}
	return n;
}

int next(int n){
	int i=0;
	//find the first 1
	for(;i<32;++i){
		if(n&1<<i) break;
	}
	cout << "i: " << i << endl;
	//find the first 0 after the first 1,and count 1s
	int cnt = 0;
	for(i=i+1;i<32;++i){
		if(n&1<<i){
			cnt++;
		}else{
			n |= 1<<i;
			n &= ~(1<<(i-1));
			break;
		}
	}
	cout << "i: " << i << endl;
	if(i>=31) return -1;
	if(cnt){
		n = n&((~0)<<i);
		n = n|(1<<cnt-1);
	}
	return n;
}

int main(int argc,char*argv[]){
	//string s = "1110110";
	//string s = "1";
	//string s = "0";
	string s = "1111111111111111111111111111111";
	int n = 0;
	cout << INT_MAX	<< endl;
	for(int i=0;i<s.size();++i){
		n = n*2 + int(s[i]-'0');
	}
	int big = next(n);
	cout << "n: " << n << endl;
	int tmp = n;
	while(tmp){
		cout << tmp%2;
		tmp/=2;
	}
	cout << endl << "big: " << big << endl;
	while(big){
		cout << big%2;
		big/=2;
	}
	int small = previous(n);
	cout << endl << "small: " << small << endl;
	while(small){
		cout << small%2;
		small/=2;
	}
	cout << endl;
	return 0;
}
