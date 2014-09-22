/*
 write a method to replace all spaces in a string with '%20'. 
 You may assume that the string has sufficient space 
 at the end of the string to hold the additional characters, 
 and that you are given the "true" length of the string. 
 (Note: if implementing in Java, 
 please use a character array 
 so that you can perform this operation in place.)
 */
#include <iostream>
#include <cstring>
using namespace std;

string repSpace(string s){
	int n = s.size();
	string s1 = "";
	int i, end=0;
	for(i=0;i<n;++i){
		if(s[i]==' '){
			s1 += s.substr(end,i-end) + "%20";
			end = i+1;
		}
	}
	if(i>end)
		s1 += s.substr(end,i-end);
	return s1;
}

void repSpace1(char *s){
	int n = strlen(s);
	int cnt = 0;
	for(int i=0;i<n;++i)
		if(s[i]==' ')
			cnt++;
	int end = n+cnt*2;
	s[end--] = '\0';
	for(int i=n-1;i>=0;--i){
		if(s[i]==' '){
			s[end--] = '0';
			s[end--] = '2';
			s[end--] = '%';
		}else{
			s[end--] = s[i]; 
		}
	}
}

int main(int argc,char*argv[]){
	string s = "a ";// = "aa bb cc d";
	//cin>>s;
	cout << repSpace(s) << endl;
	char s1[] = "aa bb cc d";
	repSpace1(s1);
	cout << s1 << endl;
	return 0;
}
