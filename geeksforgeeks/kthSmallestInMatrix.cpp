/*
 Find the kth smallest element in a (MxN) matrix.
 
 Can it be done in O(MxN) time with O(1) space? 
 */
#include <iostream>
#include <vector>
#include <cstdlib>
//#include <cmath>
using namespace std;

int myFind(vector<int>&matrix,int l,int r,int k){
	if(l>r) return -1;
	int f=l,i=l+1;
	for(;i<=r;++i){
		if(matrix[i]<matrix[f]){
			int tmp =matrix[f];
			matrix[f] = matrix[i];
			matrix[i] = matrix[f+1];
			matrix[f+1] = tmp;
			f++;
		}
	}
	if(f-l+1==k) return matrix[f];
	else if(f-l+1<k) return myFind(matrix,f+1,r,k-(f-l+1));
	else return myFind(matrix,l,f-1,k);
}

int findKthS(vector<int> &matrix,int k){
	int n = matrix.size();
	if(n==0) return -1;
	if(k<1) return -1;
	myFind(matrix,0,n-1,k);
}
int findKM(vector<vector<int> >&matrix,int k){
	int m = matrix.size();
	if(m==0) return -1;
	int n = matrix[0].size();
	if(n==0) return -1;
	if(k<1) return -1;
	int l,r;
	l=0;r=m*n-1;
	while(l<r){
		cout << "l: " << l << " r: " << r << endl;
		int f = l,i = l+1;
		int r1 = f/n, c1 = f%n;
		int v = matrix[r1][c1];
		for(;i<=r;++i){
			int r2 = i/n;
			int c2 = i%n;
			if(matrix[r2][c2]<matrix[r1][c1]){
				f++;
				int r3 = f/n,c3 = f%n;
				int tmp = matrix[r1][c1];
				matrix[r1][c1] = matrix[r2][c2];
				matrix[r2][c2] = matrix[r3][c3];
				matrix[r3][c3] = tmp;
				r1 = r3; c1 = c3;
			}
		}
		if(f+1==k) return matrix[f/n][f%n];
		else if(f+1>k) r = f-1;
		else l = f+1;
	}
	if(l+1==k) return matrix[l/n][l%n];
	return -1;
}
int main(int argc,char*argv[]){
	vector<int> vec;//={8,96,44,27,33,93,37,1,16,20};
	srand(time(NULL));
	vector<vector<int> > mat;
	for(int j=0;j<2;++j){
		vec.clear();
		for(int i=0;i<10;++i){
			int tmp = rand()%100;
			vec.push_back(tmp);
			cout << tmp << " ";
		}
		cout << endl;
		mat.push_back(vec);
	}
	cout << "vec: " << findKthS(vec,5) << endl;
	cout << "matrix: " << findKM(mat,6) << endl;
	return 0;
}
