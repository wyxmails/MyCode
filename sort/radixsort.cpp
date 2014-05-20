#include <iostream>
using namespace std;

void csort(int arr[],int n,int k,int bit){
	int c[k+1];
	int p = 1;
	for(int i=0;i<bit;++i) p *= 10;
	for(int i=0;i<=k;++i) c[i] = 0;
	for(int i=0;i<n;++i){
		int tmp = (arr[i]/p)%10;
		c[tmp]++;
	}
	for(int i=1;i<=k;++i){
		c[i] += c[i-1];
	}
	int b[n];
	for(int i=n-1;i>=0;--i){
		int tmp = (arr[i]/p)%10;
		b[c[tmp]-1] = arr[i];
		c[tmp]--;
	}
	for(int i=0;i<n;++i) arr[i] = b[i];
}

void radixsort(int arr[],int n,int d){
	int b[n];
	for(int i=0;i<d;++i){
		csort(arr,n,9,i);
	}
}

int main(){
	int n,d;
	cout << "input n, d and n numbers: " << endl;
	cin>>n>>d;
	int arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	radixsort(arr,n,d);
	for(int i=0;i<n;++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}
