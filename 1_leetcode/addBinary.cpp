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
string addBinary2(string a, string b) {
        int m = a.size();
        if(m==0) return b;
        int n = b.size();
        if(n==0) return a;
        int carr = 0;
        string res = "";
        int i=m-1;
        int j=n-1;
        while(i>=0&&j>=0){
            int n1 = a[i]-'0';
            int n2 = b[j]-'0';
            if((n1+n2+carr)%2) res = '1'+res;
            else res = '0'+res;
            carr = (n1+n2+carr)/2;
            i--;j--;
        }
        while(i>=0){
            int n1 = a[i]-'0';
            if((n1+carr)%2) res = '1'+res;
            else res = '0'+res;
            carr = (n1+carr)/2;
            i--;
        }
        while(j>=0){
            int n1 = b[j]-'0';
            if((n1+carr)%2) res = '1'+res;
            else res = '0'+res;
            carr = (n1+carr)/2;
            j--;
        }
        if(carr) res = '1'+res;
        return res;
}

class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(),n2=b.size();
        int carr=0;
        string res = "";
        int i,j;
        for(i=n1-1,j=n2-1;i>=0||j>=0;--i,--j){
            if(i>=0) carr += int(a[i]-'0');
            if(j>=0) carr += int(b[j]-'0');
            res = char(carr%2+'0')+res;
            carr /= 2;
        }
        if(carr) res = char(carr+'0')+res;
        return res;
    }
};

int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout << addBinary(s1,s2) << endl;
	return 0;
}
