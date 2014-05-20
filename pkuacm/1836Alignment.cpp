#include <iostream>
using namespace std;
int main(int argc,char*argv[]){
	int n,tmp;
	double arr[1000];
	int maxleft[1000];
	int maxright[1000];
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	maxleft[0] = 1;
	for(int i=0;i<n;++i){
		tmp=0;
		for(int j=0;j<i;++j){
			if(arr[i]>arr[j]){
				if(maxleft[j]>tmp)
					tmp=maxleft[j];
			}
		}
		maxleft[i] = tmp+1;
	}
	maxright[0] = 1;
	for(int i=n-1;i>=0;--i){
		tmp=0;
		for(int j=n-1;j>i;--j){
			if(arr[i]>arr[j]){
				if(maxright[j]>tmp)
					tmp = maxright[j];
			}
		}
		maxright[i] = tmp+1;
	}
	int Max=0;
	for(int i=0;i<n;++i){
		for(int j=i;j<n;++j){
			tmp = maxleft[i]+maxright[j];
			if(i==j) tmp=tmp-1;
			if(tmp>Max) Max = tmp;
		}
	}
	cout << n-Max << endl;
	return 0;
}
