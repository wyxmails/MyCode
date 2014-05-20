#include <iostream>
using namespace std;

void countsort(int arr[],int n,int k){
	int c[k+1];
	for(int i=0;i<k+1;++i){
		c[i] = 0;
	}
	for(int i=0;i<n;++i){
		c[arr[i]]++;
	}
	for(int i=1;i<k+1;++i){
		c[i] += c[i-1];
	}
	int b[n];
	for(int i=n-1;i>=0;--i){
		b[c[arr[i]]-1] = arr[i];
		c[arr[i]]--;
	}
	for(int i=0;i<n;++i){
		arr[i] = b[i];
	}
}

int main(){
	int n,k;
	cout << "input n,k,and n numbers: " << endl;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	countsort(arr,n,k);
	for(int i=0;i<n;++i){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
