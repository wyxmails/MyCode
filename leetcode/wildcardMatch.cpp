#include <iostream>
using namespace std;
/*
 Implement wildcard pattern matching with support for '?' and '*'.
 
 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "*") → true
 isMatch("aa", "a*") → true
 isMatch("ab", "?*") → true
 isMatch("aab", "c*a*b") → false
 */
bool isMatch(const char *s, const char *p) {
	const char *str = s;
	const char *ptr = p;
	bool star = false;
	for(;*str!='\0';str++,ptr++){
		if(*ptr=='?') continue;
		else if(*ptr=='*'){
			s = str;
			p = ptr;
			star = true;
			while(*p=='*') p++;
			if(*p=='\0') return true;
			ptr = p-1;
			str = s-1;
		}else{
			if(*str!=*ptr){
				if(!star) return false;
				s++;
				str = s-1;
				ptr = p-1;
			}
		}
	}
	while(*ptr=='*') ptr++;
	return (*ptr=='\0');
}
int main(int argc,char*argv[]){
	return 0;
}
