#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int sum,tmp;
	sum = 1<<n;
	bool first;
	for(int i=1;i<sum;++i){
		first = true;
		cout << "{";
		for(int j=0;j<n;++j){
			tmp = 1<<j;
			tmp = tmp&i;
			if(tmp){
				if(!first) cout << ",";
				first = false;
				cout << j+1;
			}
		}
		cout << "}";
		if(i!=(sum-1)) cout << ",";
	}
	cout << endl;
	return 0;
}
