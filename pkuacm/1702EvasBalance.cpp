#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc,char*argv[]){
	int t,w,tmp,i,MAX;
	int left[20],right[20];
	bool flag;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&w);
		for(i=0;i<20;++i){
			left[i] = 0;
			right[i] = 0;
		}
		for(i=0;;++i){
			if(w==0) break;
			tmp = w%3;
			if(tmp==2){
				left[i] = pow(3,i);
				w /= 3;
				w += 1;
			}else if(tmp==1){
				right[i] = pow(3,i);
				w /= 3;
			}else{
				w /= 3;
			}
		}
		MAX=i;
		flag = false;
		for(i=0;i<MAX;++i){
			if(left[i]){
				if(flag) printf(",");
				flag = true;
				printf("%d",left[i]);
			}
		}
		if(flag) printf(" ");
		else printf("empty ");
		flag = false;
		for(i=0;i<MAX;++i){
			if(right[i]){
				if(flag) printf(",");
				flag = true;
				printf("%d",right[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
