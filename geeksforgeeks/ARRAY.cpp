/*
 we have given a char array like "a1b2c3"
 we have to convert this array to array like this “abbccc” .
 This has to be done in place 
 as we have given that array has just enough space 
 to hold the expanded array.
example:
1)input: a1b1c1
output:abc
length of array will be shortened.

2)input: a2b2c2
output:aabbcc
length of array will be equal to given array.

3)input: a3b4
output:aaabbbb
length of array will be greater than given array.

 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void alpNum2alp(char A[]){
	int i=-1;
	int len=0;
	do{
		i += 2;
		len += int(A[i]-'0');
	}while(A[i+1]!='\0');
	int n = strlen(A);
	cout << "len: " << len << " n: " << n << endl;
	int l1,l2,r1,r2;
	l1=0;l2=1;r2=n-1;r1=len-1;
	while(l2<=r2){
		static int m=1;
		if(m%5==0) cout << "l2r2: " << l2 << " " << r2 << endl;
		m++;
		if(m==30) break;
		if(l1<l2){
			int cnt = int(A[l2]-'0');
			while(l1<l2&&cnt-->0){
				A[l1++] = A[l2-1];
			}
			if(cnt>1){
				A[l2] = char(cnt+'0');
			}else{
			   if(cnt==1) A[l1++] = A[l2-1];
		   	   l2 += 2;
			}
		}else{
			int cnt =  int(A[r2]-'0');
			while(r1>r2&&cnt-->0){
				A[r1--] = A[r2-1];
			}
			if(cnt>2) A[r2] = char(cnt+'0');
			else{
			   	if(cnt>0){
					A[r1--] = A[r2-1];
					if(cnt==2) r1--;
				}
				r2 -= 2;
			}
		}
	}
	A[len] = '\0';
}
int alpNum2alp2(char A[]){
	int n = strlen(A);
	int cnt = 0;
	int l=0;
	for(int i=1;i<n;i+=2){
		cnt += int(A[i]-'0');
		if(A[i]=='1') A[l++] = A[i-1];
		else{
			A[l++] = A[i-1];
			A[l++] = A[i];
		}
	}
	l--;
	for(int i=cnt-1;i>=0;){
		int tmp = int(A[l]-'0');
		if(tmp>0&&tmp<10){
			while(tmp-->0) A[i--] = A[l-1];
			l -= 2;
		}else A[i--] = A[l--];
	}
	A[cnt] = '\0';
}

int main(int argc,char*argv[]){
	char A[30] = "a1b2c3";
	//abbccc
	alpNum2alp2(A);
	for(int i=0;i<strlen(A);++i) cout << A[i];
	cout << endl;
	char A1[30] = "a5b3c3";
	//aaaaabbbccc
	alpNum2alp2(A1);
	for(int i=0;i<strlen(A1);++i) cout << A1[i];
	cout << endl;
	char A2[30] = "a1b4c1";
	//abbbbc
	alpNum2alp2(A2);
	for(int i=0;i<strlen(A2);++i) cout << A2[i];
	cout << endl;
	char A3[30] = "a5v9d2e7";
	//aaaaavvvvvvvvvddeeeeeee
	alpNum2alp2(A3);
	for(int i=0;i<strlen(A3);++i) cout << A3[i];
	cout << endl;
	char A4[30] = "a1b1c1d1e1f9g1h1j1k1";
	//abcdefffffffffghjk
	//char A[30];
   	//gets(A);
	alpNum2alp2(A4);
	for(int i=0;i<strlen(A4);++i) cout << A4[i];
	cout << endl;
	return 0;
}
