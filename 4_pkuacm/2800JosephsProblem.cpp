//Periodically Arithmetic Sequence
#include <stdio.h>
#include <math.h>

int main(int argc,char*argv[]){
	long long n,k,r,t,start,end,s;
	while(scanf("%lld%lld",&n,&k)==2){
		r=0;
		if(n>k) r+= (n-k)*k;
		s = sqrt(k*1.0);
		t = k/s;
		for(long long i=s;i>1;--i){
			start = k/i;
			end = k/(i-1);
			if(start>n) break;
			if(end>n) end = n;
			r += (k%end+k%(start+1))*(end-start)/2;
		}
		for(long long i=1;i<=n&&i<=t;++i){
			r+= k%i;
		}
		printf("%lld\n",r);
	}
	return 0;
}
