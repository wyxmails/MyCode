//dp problems
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
char s1[210];
char s2[210];
int maxlen[210][210];
int i,j;
int main(int argc,char*argv[]){
	while(scanf("%s%s",s1,s2)>0){
		for(i=0;i<210;++i){
			for(j=0;j<210;++j){
			   	maxlen[i][j] = 0;
			}
		}
		for(i=0;s1[i]!='\0';++i){
			for(j=0;s2[j]!='\0';++j){
				if(s1[i]==s2[j]){
					maxlen[i+1][j+1] = maxlen[i][j] +1;
				}else{
					maxlen[i+1][j+1] = max(maxlen[i+1][j],maxlen[i][j+1]);
				}
			}
		}
		cout << maxlen[i][j] << endl;
	}
	return 0;
}
