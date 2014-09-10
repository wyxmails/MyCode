/*
 Given an array of integers, {1,0,2,0,3,0,0,4,5,6,7,0,0,0}, 
 you have to create a new array 
 which will be like (1,2,3,4,5,6,7,0,0,0,0,0,0,0}, 
 without using any other temporary array. 
 */

#include <iostream>
#include <vector>
using namespace std;

void mvZerosBack(vector<int> &vec){
	int n = vec.size();
	int zeros=0,l=-1,r=0;
	for(;r<n;++r){
		if(vec[r]!=0){
			l++;
			vec[l] = vec[r];
		}
	}
	for(l++;l<n;++l) vec[l] = 0;
}

int main(int argc,char*argv[]){
	int arrtmp[] = {1,0,2,0,3,0,0,4,5,6,7,0,0,0};
	vector<int> vec(arrtmp,arrtmp+sizeof(arrtmp)/sizeof(arrtmp[0]));
	mvZerosBack(vec);
	for(int i=0;i<vec.size();++i)
		cout << vec[i] << " ";
	cout << endl;
	return 0;
}
