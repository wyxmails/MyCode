//dp probleams
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define INFINITE 1000000
typedef struct plank{
	int l;
	int r;
	int h;
}plank;
struct plank arrp[1010];
int markl[1010];
int markr[1010];

int cmp(const void*s1,const void*s2){
	plank *p1,*p2;
	p1 = (plank*)s1;
	p2 = (plank*)s2;
	return p1->h-p2->h;
}

int main(int argc,char*argv[]){
	int t;
	int N,X,Y,Max;
	bool lflag,rflag;
	plank tmpplank;
	scanf("%d",&t);
	while(t){
		scanf("%d %d %d %d",&N,&X,&Y,&Max);
		for(int i=0;i<N;++i){
			scanf("%d %d %d",&arrp[i].l,&arrp[i].r,&arrp[i].h);
		}
		arrp[N].l = X;
		arrp[N].r = X;
		arrp[N].h = Y;
		qsort(arrp,N+1,sizeof(plank),cmp);
		markl[0] = arrp[0].h;
		markr[0] = arrp[0].h;
		for(int i=1;i<=N;++i){
			lflag = false;
			rflag = false;
			for(int j=i-1;j>=0;--j){
				if(lflag&&rflag) break;
				if(!lflag&&arrp[i].l>=arrp[j].l&&arrp[i].l<=arrp[j].r){
					int tmph = arrp[i].h-arrp[j].h;
					if(tmph<=Max){
						markl[i] = min(markl[j]+arrp[i].l-arrp[j].l+tmph,
								markr[j]+arrp[j].r-arrp[i].l+tmph);
					}else markl[i] = INFINITE;
					lflag = true;
				}
				if(!rflag&&arrp[i].r>=arrp[j].l&&arrp[i].r<=arrp[j].r){
					int tmph = arrp[i].h-arrp[j].h;
					if(tmph<=Max){
						markr[i] = min(markl[j]+arrp[i].r-arrp[j].l+tmph,
								markr[j]+arrp[j].r-arrp[i].r+tmph);
					}else markr[i] = INFINITE;
					rflag = true;
				}
			}
			if(!lflag){
				if(arrp[i].h<=Max) markl[i] = arrp[i].h;
				else markl[i] = INFINITE;
			}
			if(!rflag){
				if(arrp[i].h<=Max) markr[i] = arrp[i].h;
				else markr[i] = INFINITE;
			}
		}
		cout << markl[N] << endl;
		t--;
	}
	return 0;
}
