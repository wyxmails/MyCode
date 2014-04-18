#include <iostream>
#include <string>
using namespace std;

void rmvDup(string& s){
	/*for only [a~z]*/
	int n = s.size();
	if(n<2) return;
	int checker = 0;
	int tail=0;
	for(int i=0;i<n;++i){
		int val = s[i]-'a';
		if(!(checker&(1<<val))){
			s[tail++] = s[i];
			checker |= (1<<val);
		}
	}
	s = s.substr(0,tail);
}
void rmvDup1(string &s){
	/*for ASCII, O(n^2)*/
	int n = s.size();
	if(n<2) return;
	int tail = 0;
	for(int i=0;i<n;++i){
		int j;
		for(j=0;j<tail;++j){
			if(s[i]==s[j]) break;
		}
		if(j==tail) s[tail++] = s[i];
	}
	s = s.substr(0,tail);
}

void rmvDup2(string &s){
	/*for ASCII, with additional memory, O(n)*/
	int n = s.size();
	if(n<2) return;
	int tail = 0;
	int asc = 256;
	bool arr[asc];
	for(int i=0;i<asc;++i) arr[i] = false;
	for(int i=0;i<n;++i){
		if(!arr[s[i]]){
			s[tail++] = s[i];
			arr[s[i]] = true;
		}
	}
	s = s.substr(0,tail);
}

int main(int argc,char*argv[]){
	string s;// = "";
	cin>>s;
	rmvDup(s);
	cout << s << endl;
	string s1;
	cin>>s1;
	rmvDup1(s1);
	cout << s1 << endl;
	string s2;
	cin>>s2;
	rmvDup2(s2);
	cout << s2 << endl;
	return 0;
}
