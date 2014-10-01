/*
 Write a function to swap a number in place
 (that is, without temporary variables.)
 */
#include <iostream>
using namespace std;

void swap(int &n1,int &n2){
	n1 ^= n2;
	n2 ^= n1;
	n1 ^= n2;
}
void swap2(int&n1,int&n2){
	n1 = n1-n2;
	n2 = n1+n2;
	n1 = n2-n1;
}
int main(int argc,char*argv[]){
	int n1,n2;
	cin>>n1>>n2;
	swap(n1,n2);
	cout << n1 << " " << n2 << endl;
	swap2(n1,n2);
	cout << n1 << " " << n2 << endl;
	return 0;
}
