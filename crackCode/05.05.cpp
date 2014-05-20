#include <iostream>
using namespace std;

int cnvStep(int a,int b){
	int m = a^b;
	int cnt=0;
	int i=0;
	while(i<32){
		if(m&(1<<i)) cnt++;
		i++;
	}
	return cnt;
}

int main(int argc,char*argv[]){
	int a=-1;
	int b=14;
	cout << cnvStep(a,b) << endl;
	return 0;
}
