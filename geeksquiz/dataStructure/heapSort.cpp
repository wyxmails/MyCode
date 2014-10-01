#include <iostream>
using namespace std;

void heapify(int arr[],int i,int n){
	int largest = i;
	int l = 2*i;
	int r = 2*i+1;
	if(l<=n&&arr[l]>arr[largest]) largest = l;
	if(r<=n&&arr[r]>arr[largest]) largest = r;
	if(largest!=i){
		int tmp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = tmp;
		heapify(arr,largest,n);
	}
}

void buildHeap(int arr[],int n){
	for(int i=n/2;i>0;--i){
		heapify(arr,i,n);
	}
}

void heapSort(int arr[]){
	int n = arr[0];
	buildHeap(arr,n);
	while(n>1){
		int tmp = arr[n];
		arr[n] = arr[1];
		arr[1] = tmp;
		n--;
		heapify(arr,1,n);
	}
}

void increaseKey(int arr[],int i, int key){
	if(arr[i]>key){
		cerr << "Key is smaller than original value" << endl;
		return;
	}
	arr[i] = key;
	while(i>1&&arr[i]>arr[i/2]){
		int tmp = arr[i];
		arr[i] = arr[i/2];
		arr[i/2] = tmp;
		i = i/2;
	}
}

void heapInsert(int arr[],int n,int key){
	n++;
	arr[n] = INT_MIN;
	increaseKey(arr,n,key);
}

int main(int argc,char*argv[]){
	int arr[] = {10,4,1,3,2,16,9,10,14,8,7};
	int n=arr[0];
	buildHeap(arr,n);
	for(int i=1;i<=n;++i)
		cout << arr[i] << " ";
	cout << endl;
	increaseKey(arr,5,20);
	for(int i=1;i<=n;++i)
		cout << arr[i] << " ";
	cout << endl;
	heapSort(arr);
	for(int i=1;i<=n;++i)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
