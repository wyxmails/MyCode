#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void num_occur(int arr[],int len, int num){
	int l,r,m;
	l=0;r=len-1;
	while(l<=r){
		m = l+(r-l)/2;
		if(arr[m]>=num) r=m-1;
		else l=m+1;
	}
	int s=r+1;
	l=0;r=len-1;
	while(l<=r){
		m = l+(r-l)/2;
		if(arr[m]<=num) l=m+1;
		else r=m-1;
	}
	int e=l-1;
	cout << "number of num: " << e-s+1 << endl;
}

int main(){
	int n;
	cin>>n;
	int arr[3*n];
	srand(time(0));
	for(int i=0;i<3*n;++i){
		if(i==0)
			arr[i] = rand()%2;
		else
			arr[i] = arr[i-1]+rand()%2;
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "num: " << n/2 << endl;
	num_occur(arr,3*n,n/2);
	return 0;
}
