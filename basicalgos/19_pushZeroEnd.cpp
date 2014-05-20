#include <iostream>
using namespace std;

void push_zero(int *A,int len){
	int i=0;
	int j=len-1;
	int tmp;
	while(i<j){
		if(A[i]!=0){i++;continue;}
		if(A[j]==0){j--;continue;}

		A[i] = A[j];
		A[j] = 0;
		i++;
		j--;
	}
}
int main(){
	//int arr[7] = {1,2,0,4,0,0,8};
	//int arr[7] = {0,0,0,0,0,0,0};
	int arr[7] = {1,2,3,4,3,3,0};
	for(int i=0;i<7;++i){
		cout << arr[i] << " ";
	}
	cout << endl;
	push_zero(arr,7);
	for(int i=0;i<7;++i){
		cout << arr[i] << " ";
	}
	cout << endl;

}
