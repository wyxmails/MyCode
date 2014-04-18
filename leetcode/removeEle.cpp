/*Remove Element
   Given an array and a value, 
   remove all instances of that value in place 
   and return the new length.
 The order of elements can be changed. 
 It doesn't matter what you leave beyond the new length.
 */
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
//O(n^2)
int removeElement(int A[], int n, int elem) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	for(int i=0;i<n;++i){
		if(A[i]==elem){
			for(int j=i+1;j<n;++j){
				A[j-1] = A[j];
			}
			n--;
			i--;
		}
	}
	return n;
}
//O(n)
int removeElement2(int A[], int n, int elem) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(n==0) return n;
	int i=0,len=0;
	while(i<n){
		while(i<n&&A[i]==elem) i++;
		if(i<n) A[len++] = A[i++];
	}
	return len;
}
int main(){
	srand(time(0));
	int n,tmp;
	cin>>n;
	int A[n];
	int elem = rand()%n;
	cout << elem << endl;
	for(int i=0;i<n;++i){
		tmp = rand()%n;
		A[i] = tmp;
		cout << A[i] << " ";
	}
	cout << endl;
	n = removeElement(A,n,elem);
	cout << n << endl;
	for(int i=0;i<n;++i){
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
