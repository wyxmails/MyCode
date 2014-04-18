/*
  Given two binary strings, return their sum (also a binary string).

  For example,
  a = "11"
  b = "1"
  Return "100".
   */
#include <iostream>
#include <string>
using namespace std;
string addBinary(string a, string b) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int i=a.size()-1;
	int j=b.size()-1;
	int carry=0;
	string sres = "";
	while(i>=0&&j>=0){
		if(a[i]=='1'&&b[j]=='1'){
			if(carry==1) sres = '1' + sres;
			else{
				carry = 1;
				sres = '0' + sres;
			}
		}else if(a[i]=='0'&&b[j]=='0'){
			if(carry==1){
				sres = '1' + sres;
				carry = 0;
			}else sres = '0' + sres;
		}else{
			if(carry==1)    sres = '0' + sres;
			else    sres = '1' + sres;
		}
		i--;
		j--;
	}
	while(i>=0){
		if(carry){
			if(a[i]=='1')
				sres = '0' + sres;
			else{
				sres = '1' + sres;
				carry = 0;
			}
		}else{
			sres = a[i] + sres;
		}
		i--;
	}
	while(j>=0){
		if(carry){
			if(b[j]=='1')
				sres = '0' + sres;
			else{
			sres = '1' + sres;
			carry = 0;
			}
		}else sres = b[j] + sres;
		j--;
	}
	if(carry) sres = '1' + sres;
	return sres;
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout << addBinary(s1,s2) << endl;
	return 0;
}
