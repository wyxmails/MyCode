//dp problems
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc,char*argv[]){
	int N,num;
	int Max;
	int j,left,right;
	int mark[100000];
	while(cin>>N){
		mark[0] = -1;
		Max=0;
		for(int i=0;i<N;++i){
			//cin>>num;
			scanf("%d",&num);
			if(num>mark[Max]){
				mark[++Max] = num;
				continue;
			}
			if(num==mark[Max]){
				continue;
			}
			left=0;
			right=Max;
			while(left<right){
				j = (left+right)/2 + 1;
				if(num<=mark[j])
					right = j-1;
				else
					left = j;
			}
			mark[right+1] = num;
		}
		cout << Max << endl;
	}
	return 0;
}
