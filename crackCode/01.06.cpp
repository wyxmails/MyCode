#include <iostream>
using namespace std;

void rotate(int arr[][3], int n){
	for(int i=0;i<n;++i){
		for(int j=0;j<n/2;++j){
			int tmp = arr[i][j];
			arr[i][j] = arr[i][n-j-1];
			arr[i][n-j-1] = tmp;
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n-i;++j){
			int tmp = arr[i][j];
			arr[i][j] = arr[n-j-1][n-i-1];
			arr[n-j-1][n-i-1] = tmp;
		}
	}
}

int main(int argc,char*argv[]){
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	rotate(arr,3);
	cout << "After rotate: " << endl;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return 0;
}
