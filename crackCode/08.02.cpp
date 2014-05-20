#include <iostream>
using namespace std;

int gridPaths(int N,int M){
	if(N==1&&M==1) return 0;
	if(N==1) return 1;
	if(M==1) return 1;
	int r = gridPaths(N-1,M);
	int d = gridPaths(N,M-1);
	return r+d;
}
bool bad(int r,int c){
	return false;
}
int gridPathsLimit(int N,int M){
	if(N==1&&M==1) return 0;
	if(N==1){
		int tmp = M;
		while(tmp>0){
			if(bad(tmp,N)) return 0;
			tmp--;
		}
		return 1;
	}
	if(M==1){
		int tmp = N;
		while(tmp>0){
			if(bad(M,tmp)) return 0;
			tmp--;
		}
		return 1;
	}
	int r,d;
	r=d=0;
	if(!bad(N-1,M)) r = gridPathsLimit(N-1,M);
	if(!bad(N,M-1)) d = gridPathsLimit(N,M-1);
	return r+d;
}

int main(int argc, char*argv[]){
	cout << gridPaths(1,1) << endl;
	cout << gridPaths(1,2) << endl;
	cout << gridPaths(2,1) << endl;
	cout << gridPaths(2,2) << endl;
	cout << gridPaths(10,8) << endl;
	cout << gridPathsLimit(10,8) << endl;
	return 0;
}
