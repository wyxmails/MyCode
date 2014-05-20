#include <iostream>
#include <string>
using namespace std;

int main(int argc,char*argv[]){
	 string s,tmps;
	 int n,dotpos,dotlen,numlen,tmp,carry;
	 int a[126],b[126],c[126];
	 int i,j;
	 while(cin>>s>>n){
		 for(i=0;i<126;++i) a[i] = b[i] = c[i] = 0;
		 dotpos = s.find_first_of('.');
		 dotlen = dotpos>=0?(s.size()-dotpos-1)*n:0;
		 for(i=s.size()-1,j=0;i>=0;--i)
		 	if(i!=dotpos) a[j++] = s[i]-'0';
		 while(a[j]==0) j--;
		 numlen = j+1;
		 for(i=0;i<126;++i) b[i] = a[i];
		 for(int cnt=1;cnt<n;++cnt){
			carry = 0;
		 	for(i=0;i<numlen;++i){
				for(j=0;j<126-i;++j){
					tmp = b[j]*a[i];
		 			c[i+j] += tmp%10 + carry;
					carry = tmp/10 + c[i+j]/10;
					c[i+j] %=10;
				}
		 	}
			for(i=0;i<126;++i){ b[i] = c[i];c[i] = 0;}
		 }
		 i=0;
		 while(b[i]==0) i++;
		 j=125;
		 while(b[j]==0) j--;
		 if(i>=dotlen){
		 	for(;j>=dotlen;--j)	cout << b[j];
			cout << endl;
		 }else{
			 for(j=j>=dotlen?j:(dotlen-1);j>=i;--j) {if(j==(dotlen-1)) cout << ".";cout << b[j];}
			 cout << endl;
		 }
	 }
	 return 0;
}
