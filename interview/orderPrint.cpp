//print all the possible order of the intergers in arr
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
int n;
void exchange(int arr[],int i,int start){
	int tmp = arr[i];
	arr[i] = arr[start];
	arr[start] = tmp;
}
int oprint(int arr[],int start,int end){
	if(start==end){
		for(int i=0;i<n;++i)
			cout << arr[i] << " ";
		cout << endl;
	}
	for(int i=start;i<=end;++i){
		exchange(arr,i,start);
		oprint(arr,start+1,end);
		exchange(arr,i,start);
	}
}

int main(int argc,char*argv[]){
	cin>>n;
	int arr[n];
	srand(time(0));
	for(int i=0;i<n;++i){
		arr[i] = rand()%(3*n);
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "start to process: " << endl;
	oprint(arr,0,n-1);
}
