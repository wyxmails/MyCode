#include <iostream>
using namespace std;

void reverse(int A[], int len){
	int i=0;
	int j=len-1;
	int tmp;
	while(i<j){
		tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
		i++;
		j--;
	}
}

void rotate_array(int A[], int len, int d){
	reverse(A,d);
	reverse(A+d,len-d);
	reverse(A,len);
}
int main(){
	int arr[7] = {1,2,3,4,5,6,7};
	int n;
	cin>>n;
	rotate_array(arr,7,n);
	for(int i=0;i<7;++i){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
