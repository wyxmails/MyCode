#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void bsort(int arr[],int n){
	int tmp;
	for(int i=1;i<n;++i){
		for(int j=0;j<n-i;++j){
			if(arr[j]<arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

int main(int argc,char*argv[]){
	srand(time(0));
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;++i){
		arr[i] = rand()%(2*n);
		cout << arr[i] << " " ;
	}
	cout << endl;
	bsort(arr,n);
	for(int i=0;i<n;++i) cout << arr[i] << " ";
	cout << endl;
	return 0;
}
