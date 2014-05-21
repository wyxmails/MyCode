/*Reverse Words in a String*/
#include <iostream>
#include <string>
using namespace std;

void myReverse(string& s,int l,int r){
	char tmp;
	while(l<r){
		tmp = s[l];
		s[l] = s[r];
		s[r] = tmp;
		l++;
		r--;
	}
}
void reverseWords(string &s) {
	if(s.size()==0) return;
	int i=0;
	while(s[i]==' ') i++;
	s = s.substr(i);
	if(s.size()==0) return;
	i = s.size()-1;
	while(s[i]==' ') i--;
	s = s.substr(0,i+1);
	int n = s.size();
	if(n<=0) return;
	int l,r;
	l = r = 0;
	r = s.find(' ',l);
	while(r!=string::npos){
		myReverse(s,l,r-1);
		int tmp = r;
		while(s[tmp]==' ') tmp++;
		if(tmp>(r+1)){
			s = s.substr(0,r) + ' ' + s.substr(tmp);
			n = s.size();
		}
		l = r+1;
		r = s.find(' ',l);
	}
	if(l<n)
	myReverse(s,l,n-1);
	myReverse(s,0,n-1);
}
int main(int argc,char*argv[]){
	return 0;
}
