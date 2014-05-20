#include <iostream>
using namespace std;

int arr[20];
void cntFib(){
	arr[0] = 1;
	arr[1] = 2;
	for(int i=2;i<20;++i){
		arr[i] = arr[i-1] + arr[i-2];
	}
	cout << "arr[19]: " << arr[19] << endl;
}
int biFib(int n){
	int result = 0;
	for(int i=19;i>=0;--i){
		if(arr[i]<=n){
			result = result*10 +1;
			n -= arr[i];
		}else
			result *= 10;
	}
	return result;
}
int main(int argc,char*argv[]){
	int n,result;
	cntFib();
	while(cin>>n){
		result = biFib(n);
		cout << "result: " << result << endl;
	}
	return 0;
}
