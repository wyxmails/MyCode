/*
 Implement a method to perform basic string compression 
 using the counts of repeated characters. 
 For example, the string aabcccccaaa would become a2blc5a3. 
 If the "compressed" string would not become smaller 
 than the original string, 
 your method should return the original string.
 */
#include <iostream>
using namespace std;

string compactStr(const string &str){
	string res = "";
	int i=1,cnt=1,n=str.size();
	for(;i<n;++i){
		if(str[i]==str[i-1]){
		   	cnt++;
			if(i!=n-1) continue;
			else i++;
		}
		res = res + str[i-1]+char('0'+cnt);
		cnt = 1;
	}
	if(res.size()>=str.size()) return str;
	return res;
}

int count(const string&str){
	int cnt=1,n=str.size();
	if(n==0) return 0;
	char last = str[0];
	for(int i=1;i<n;++i){
		if(str[i]==last) continue;
		else{
			cnt++;
			last = str[i];
		}
	}
	return 2*cnt;
}
string compactStr2(const string&str){
	int size = count(str);
	int n = str.size();
	if(size>=n) return str;
	string res(size,' ');
	res[0] = str[0];
	int cnt=1;
	for(int i=1,j=1;i<n;++i){
		if(str[i]==str[i-1]){
			cnt++;
			if(i!=n-1) continue;
			else i++;
		}
		res[j++] = char('0'+cnt);
		if(i<n) res[j++] =  str[i];
		if(i==n-1) res[j] = '1';
		cnt=1;
	}
	return res;
}
int main(int argc,char*argv[]){
	string str = "abc";
	cout << compactStr(str) << endl;
	cout << compactStr2(str) << endl;
	str = "aabbcc";
	cout << compactStr(str) << endl;
	cout << compactStr2(str) << endl;
	str = "aabcccddd";
	cout << compactStr(str) << endl;	
	cout << compactStr2(str) << endl;	
	return 0;
}
