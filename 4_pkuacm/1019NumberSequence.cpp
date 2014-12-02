#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(int argc,char*argv[]){
	long long t,n,i,pos,out,length;
	long long arr[31270];
	long long sum[31270];
	//init table
	arr[1] = 1;
	sum[1] = 1;
	for(i=2;i<31270;++i){
		arr[i] = arr[i-1] + (int)log10((double)i) + 1;
		sum[i] = arr[i] + sum[i-1];
	}
	scanf("%lld",&t);
	while(t){
		scanf("%lld",&n);
		i=1;
		while(sum[i]<n) ++i;
		pos = n-sum[i-1];
		length = 0;
		for(i=1;length<pos;++i){
			length += (int)log10((double)i) + 1;
		}
		out = (int)((i-1)/pow(10,length-pos))%10;
		cout << out << endl;
		t--;
	}
	return 0;
}
