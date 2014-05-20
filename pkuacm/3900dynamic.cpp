#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc,char*argv[]){
	int N,t;
	int M,w,c,tmpw,cost;
	int total[150][10000];
	int warr[150];
	int carr[150];
	scanf("%d",&t);
	while(t){
		scanf("%d%d",&N,&M);
		for(int i=1;i<=N;++i){
			scanf("%d",&w);
			for(int j=i*(i-1)/2+1;j<i*(i+1)/2+1;++j)
				warr[j] = w;
		}
		for(int i=1;i<=N;++i){
			scanf("%d",&c);
			for(int j=i*(i-1)/2+1;j<i*(i+1)/2+1;++j)
				carr[j] = c;
		}
		warr[0] = 0;
		carr[0] = 0;
		for(int i=0;i<=M;++i) total[0][i]=0;
		for(int i=1;i<=N*(N+1)/2;++i){
			total[i][0]=0;
			for(int j=1;j<=M;++j){
				if(warr[i]<=j){
					tmpw = j-warr[i];
					if(total[i-1][tmpw]+carr[i]>total[i-1][j])
						total[i][j] = total[i-1][tmpw]+carr[i];
					else
						total[i][j] = total[i-1][j];
				}else{
					total[i][j] = total[i-1][j];
				}
			}
		}

		cost = -1;
		for(int i=1;i<=M;++i){
			if(total[N*(N+1)/2][i]>cost){
				cost = total[N*(N+1)/2][i];
				if(i>5000)
					cout << "w: " << i << " c: " << cost << endl;
			}
		}
		cout << cost << endl;
		t--;
	}
	return 0;
}
