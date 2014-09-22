/*
 Implement a function void reverse(char* str) in C or C++ 
 which reverses a null-terminated string.
 */
#include <iostream>
#include <cstring>
using namespace std;

void swap(char &a,char &b){
	a = a^b;
	b = a^b;
	a = a^b;
}

void reverse1(char *s){
	int n = strlen(s);
	for(int i=0;i<n/2;++i)
		swap(s[i],s[n-i-1]);
}

char * reverse(char *s){
	char *end = s;
	char *str = s;
	char tmp;
	while(*end) end++;
	end--;
	while(str<end){
		tmp = *str;
		*str = *end;
		*end = tmp;
		str++;end--;
	}
	return s;
}

int main(int argc,char*argv[]){
	char s[] = "abc";
	//char *s = "abc";  /*warning and segmentation fault*/
	//const char *s = "abc"; /*errors, const can not be changed*/
	cout << reverse(s) << endl;
	reverse1(s);
	cout << s << endl;
	return 0;
}
