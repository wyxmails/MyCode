/*
 Write an algorithm such that if an element in an MxN matrix is 0, 
 its entire row and column are set to 0.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void setZero(vector<vector<int> >&arr){
	int m = arr.size();
	if(m==0) return;
	int n = arr[0].size();
	if(n==0) return;
	bool flagR0=false,flagC0=false;
	for(int i=0;i<m;++i){
		if(arr[i][0]==0){
		   	flagC0 = true;
			break;
		}
	}
	for(int j=0;j<n;++j){
		if(arr[0][j]==0){
			flagR0 = true;
			break;
		}
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<n;++j){
			if(arr[i][j]==0){
				arr[i][0] = 0;
				arr[0][j] = 0;
			}
		}
	}
	for(int i=0;i<m;++i){
		if(arr[i][0]==0){
			for(int j=0;j<n;++j)
				arr[i][j] = 0;
		}
	}
	for(int j=0;j<n;++j){
		if(arr[0][j]==0){
			for(int i=0;i<m;++i)
				arr[i][j] = 0;
		}
	}
	if(flagR0){
		for(int j=0;j<n;++j)
			arr[0][j] = 0;
	}
	if(flagC0){
		for(int i=0;i<m;++i)
			arr[i][0] = 0;
	}
}

int main(int argc,char*argv[]){
	vector<vector<int> > arr(5,vector<int>(5,0));
	srand(time(NULL));
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			int tmp = rand()%10;
			arr[i][j] = tmp;
			cout << tmp << " ";
		}
		cout << endl;
	}
	setZero(arr);
	cout << "after set Zero: " << endl;
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
