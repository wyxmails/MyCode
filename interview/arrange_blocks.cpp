/*
 You are given N blocks of height 1…N. In how many ways can you arrange these blocks in a row such that when viewed from left you see only L blocks (rest are hidden by taller blocks) and when seen from right you see only R blocks? Example given N=3, L=2, R=1 there is only one arrangement {2, 1, 3} while for N=3, L=2, R=2 there are two ways {1, 3, 2} and {2, 3, 1}.

 How should we solve this problem by programming? Any efficient ways?
 */

#include <iostream>
#include <algorithm>
using namespace std;

int fac(int n){
	int res = 1;
	for(int i=2;i<=n;++i)
		res *= i;
	return res;
}

int combi(int n,int k){
	return fac(n)/(fac(k)*fac(n-k));
}

int f(int n,int k){
	int res = 0;
	if(n<k) return 0;
	if(n==k) return 1;
	if(k<=0) return 0;
	if(k==1) return fac(n-1);
	for(int i=k;i<=n;++i)
		res += combi(n-1,i-1)*f(i-1,k-1)*fac(n-k);
	return res;
}

int ArrangeBlocks(int N,int L,int R){
	if(L+R>N+1) return 0;
	int res=0;
	for(int k=L;k<=N-R+1;++k){
		res += combi(N-1,k-1)*f(k-1,L-1)*f(N-k,R-1);
	}
	return res;
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	int n = rand()%10+1;
	int l= rand()%n;
	int r = rand()%n;
	cout << "n l r: " << n << " " << l << " " << r << endl;
	cout << ArrangeBlocks(n,l,r) << endl;
	cout << "3 2 1 : " << ArrangeBlocks(3,2,1) << endl;
	cout << "3 2 2 : " << ArrangeBlocks(3,2,2) << endl;
	cout << "3 1 1 : " << ArrangeBlocks(3,1,1) << endl;
	cout << "2 1 1 : " << ArrangeBlocks(2,1,1) << endl;
	return 0;
}
