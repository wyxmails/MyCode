#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc,char*argv[]){
	int t,x,y;
	int o1,o2,o3,o4;
	char s1[10],s2[10];
	scanf("%d",&t);
	while(t){
		scanf("%s %s",s1,s2);
		x = abs(s1[0]-s2[0]);
		y = abs(s1[1]-s2[1]);
		if(x==0&&y==0){
		   	printf("0 0 0 0\n");
			t--;
			continue;
		}else if(x==y){
			o1 = x;
			o2 = 1;
			o3 = 2;
			o4 = 1;
		}else if(x==0||y==0){
			o1 = max(x,y);
			o2 = 1;
			o3 = 1;
			if(abs(s1[1]-s1[0])%2==abs(s2[1]-s2[0])%2) o4 = 2;
			else o4 = 0;
		}else if(x!=y){
			o1 = min(x,y) + abs(x-y);
			o2 = 2;
			o3 = 2;
			if(abs(s1[1]-s1[0])%2==abs(s2[1]-s2[0])%2) o4 = 2;
			else o4 = 0;
		}
		if(o4) printf("%d %d %d %d\n",o1,o2,o3,o4);
		else printf("%d %d %d Inf\n",o1,o2,o3);
		t--;
	}
	return 0;
}
