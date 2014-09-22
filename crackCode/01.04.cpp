/*
 Given two strings,
 write a method to decide if one is a permutation of the other.
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool anagram(string s1,string s2){
	int len = s1.size();
	if(len!=s2.size()) return false;
	sort(&s1[0],&s1[0]+len);
   	sort(&s2[0],&s2[0]+len);
	return s1==s2;
}

bool anagram1(string s1,string s2){
	int len = s1.size();
	if(len!=s2.size()) return false;
	int check[256];
	memset(check,0,sizeof(check));
	for(int i=0;i<len;++i){
		check[s1[i]]++;
		check[s2[i]]--;
	}
	for(int i=0;i<256;++i)
		if(check[i]!=0)
			return false;
	return true;
}

int main(int argc,char*argv[]){
	string s1 = "aabbcc";
	string s2 = "abccba";
	if(anagram(s1,s2)) cout << "Are Anagrams!" << endl;
	else cout << "Not Anagrams!" << endl;
	if(anagram1(s1,s2)) cout << "Are Anagrams!" << endl;
	else cout << "Not Anagrams!" << endl;
	return 0;
}
