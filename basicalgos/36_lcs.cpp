#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string get_lcs(char *s1,char*s2){
	int m = strlen(s1);
	int n = strlen(s2);
	int mark[n+1][m+1];
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			mark[i][j] = 0;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s1[j]==s2[i]) mark[i][j] = mark[i-1][j-1] +1;
			else mark[i][j] = max(mark[i-1][j],mark[i][j-1]);
		}
	}
	string s = "";
	for(int i=n,j=m;i>0&&j>0;){
		if(s1[j]==s2[i]){
		   	s = s1[j] + s;
			i--;
			j--;
		}else if(mark[i-1][j]>mark[i][j-1]) i--;
		else j--;
	}
	return s;
}
int main()
{
	char s1[100],s2[100];
	strcpy(s1,"Hello, this is a test");
	strcpy(s2,"Well, I don't know whether this is a test. Hello");
	string s = get_lcs(s1,s2);
	cout << s1 << endl << s2 << endl;
	cout << "'" << s  << "'" << endl;
	return 0;
}
