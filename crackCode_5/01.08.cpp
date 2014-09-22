/*
 Assume you have a method isSubstring,
 which checks if one word is a substring of another.
 Given two strings, s1 and s2, write code to check,
 If s2 is a rotation of s1 using only one call to isSubstring 
 (e.g.,"waterbottLe"is a rotation of"erbottLewat").
 */
#include <iostream>
using namespace std;

bool isSubstring(const string &s1,const string &s2){
	int n = s1.size();
	int m = s2.size();
	for(int i=0;i<n-m;++i){
		if(s1[i]==s2[0]){
			string tmp = s1.substr(i,m);
			if(tmp==s2) return true;
		}
	}
	return false;
}

bool isRotate(const string &s1,const string &s2){
	string tmp = s1+s1;
	return isSubstring(tmp,s2);
}

int main(int argc,char*argv[]){
	string s1 = "bottLewater";
	string s2 = "erbottLewat";
	if(isRotate(s1,s2)) cout << "Is rotate" << endl;
	else cout << "Not rotate" << endl;
	return 0;
}
