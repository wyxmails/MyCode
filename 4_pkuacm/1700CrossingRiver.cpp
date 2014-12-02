#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int i,int j){
	return i<j;
}
int main(int argc,char*argv[]){
	int t,n,a,b,y,z,total,tmp,j;
	int arr[1010];
	scanf("%d",&t);
	while(t--){
		total = 0;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n,cmp);
		a = arr[0];
		b = arr[1];
		for(j=n-1;j>2;j-=2){
			z = arr[j];
			y = arr[j-1];
			if(2*b>(a+y)){
				total += a+y+a+z;
			}else{
				total += a+z+2*b;
			}
		}
		if(j==0){
			total += arr[j];
		}else if(j==1){
			total += arr[j];
		}else if(j==2){
			total += a+b+arr[j];
		}
		printf("%d\n",total);
	}
	return 0;
}
