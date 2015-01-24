#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BuildingTowers{
public:
	long long maxHeight(int N, int K, vector <int> x, vector <int> t){
		int n = x.size();
		n = t.size();
		if(n==0) return (long long)(N-1)*K;
		long long res=0;
		t[0] = min((long long)t[0],(long long)K*x[0]);
		for(int i=1;i<n;++i)
			t[i] = min((long long)t[i],(long long)(x[i]-x[i-1])*K+t[i-1]);
		
		res = max(res,(long long)t[0]);

		res = max(res,(long long)(t[n-1]+K*(N-x[n-1])));

		for(int i=1;i<n;++i){
			long long tmp = (long long)((x[i]-x[i-1])/2)*K+min(K,max(t[i],t[i-1]));
			res = max(res,tmp);
		}
		return res;
	}
};
