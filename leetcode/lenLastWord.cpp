#include <iostream>
using namespace std;
/*
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 
Note: A word is defined as a character sequence consists of non-space characters only.
 
 For example, 
 Given s = "Hello World",
 return 5.
 */
int lengthOfLastWord(const char *s) {
	int i=0;
	while(s[i]!='\0') i++;
	int cnt = 0;
	i--;
	
	while(i>=0&&s[i]==' ') i--;
	while(i>=0&&s[i]!=' '){
		cnt++;
		i--;
	}
	return cnt;
}
int main(int argc,char*argv[]){
	return 0;
}
