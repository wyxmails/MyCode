#include <iostream>
#include <string>
using namespace std;
int main(){
	string s = "I";
	cout << "s.size(): " << s.size() << endl;
	cout << ' '-'0' << endl;
	cout << sizeof(long long) << " " << sizeof(long) << " " << sizeof(int) << endl; 
	int arr[] = {3, 2, 5, 2, 1, 5, 3};
	int num=0,i;
	for(i=0;i<7;++i){
		num ^= arr[i];
	}
	cout << "single: " << num << endl;
	int c = 2^2;
	cout << c << endl;
	return 0;
}
