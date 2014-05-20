#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc,char*argv[]){
	string s1,s2,s3,s4;
	int r1,r2,r3,r4;
	r1=r2=r3=r4=0;
	cin>>s1>>s2>>s3>>s4;
	for(int i=0;i<4;++i){
		if(s1[i]=='b') r1 |= 1<<(4-i-1);
		else r1 &= ~1<<(4-i-1);
		if(s2[i]=='b') r2 |= 1<<(4-i-1);
		else r2 &= ~1<<(4-i-1);
		if(s3[i]=='b') r3 |= 1<<(4-i-1);
		else r3 &= ~1<<(4-i-1);
		if(s4[i]=='b') r4 |= 1<<(4-i-1);
		else r4 &= ~1<<(4-i-1);
	}
	cout << r1 << " " << r2 << " " << r3 << " " << r4 << endl;
}
