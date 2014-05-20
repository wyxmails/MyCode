#include <iostream>
using namespace std;

struct Node{
	int val;
	Node *left;
	Node *right;
	Node(int v):val(v),left(NULL),right(NULL){}
};

void maxheapify(int arr[],int s,int n){
	int l=2*(s+1)-1;
	int r=2*(s+1);
	int largest = s;
	if(l<n&&arr[l]>arr[s]) largest = l;
	if(r<n&&arr[r]>arr[largest]) largest = r;
	if(largest!=s){
	   	int v = arr[largest];
		arr[largest] = arr[s];
		arr[s] = v;
		maxheapify(arr,largest,n);
	}
}

void buildmaxheap(int arr[],int n){
	for(int i=n/2;i>=0;--i){
		maxheapify(arr,i,n);
	}
}

void heapsort(int arr[],int n){
	buildmaxheap(arr,n);
	for(int i=n-1;i>=1;--i){
		int v = arr[i];
		arr[i] = arr[0];
		arr[0] = v;
		maxheapify(arr,0,i);
	}
}

int main(){
	int n;
	cout << "input arr size and values: " << endl;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	heapsort(arr,n);
	for(int i=0;i<n;++i) cout << arr[i] << " ";
	cout << endl;
	return 0;
}
