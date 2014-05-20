#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
char *compStr(char *str){
	int cnt,len;
	char tmp;
	char *s1;
	char pstr[1024];
	memset(pstr,sizeof(pstr),0);
	s1 = str;
	len = 0;
	while(*s1!='\0'){
		tmp = *s1;
		cnt=0;
		while(*s1==tmp){
			cnt++;
			s1++;
		}
		sprintf(pstr+len,"%d%c",cnt,tmp);
		len += 2;
	}
	cout << pstr << endl;
	if(len>=(s1-str)) return str;
	else{
		s1 = pstr;
		return s1;
	}
}
char* strStr(char *haystack,char*needle){
	char *p,*q;
	while(*haystack!='\0'){
		p = haystack;
		q = needle;
		while(*p==*q&&*p!='\0'&&*q!='\0'){
			p++;
			q++;
		}
		if(*q=='\0') return haystack;
		if(*p=='\0') return NULL;
		haystack++;
	}
	return NULL;
}

int main(){
	//char *str1,*str2;
	//str1 = new char[6];
	//str2 = new char[4];
	char *p;
	char str1[1024],str2[1024];
	memset(str1,sizeof(str1),0);
	memset(str2,sizeof(str2),0);
	strcpy(str1,"abcde");
	strcpy(str2,"cde");
	p = strStr(str1,str2);
	printf("%s\n",p);
	strcpy(str1,"aaabbccddefgggg");
	printf("%s\n",str1);
	p = compStr(str1);
	printf("%s\n",p);
}
