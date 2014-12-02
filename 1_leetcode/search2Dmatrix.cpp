#include <iostream>
#include <vector>
using namespace std;
/*
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 
 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 For example,
 
 Consider the following matrix:
 
 [
   [1,   3,  5,  7],
   [10, 11, 16, 20],
   [23, 30, 34, 50]
 ]
 Given target = 3, return true.
 */
bool searchMatrix(vector<vector<int> > &matrix, int target) {
	int m = matrix.size();
	int i=0;
	while(i<m){
		if(target==matrix[i][0]) return true;
		if(target>matrix[i][0]) i++;
		else{
			i--;
			break;
		}
	}
	if(i==m) i--;
	if(i<0) i=0;
	for(int j=0;j<matrix[i].size();++j)
		if(target==matrix[i][j]) return true;
	return false;
}

bool searchMatrix2(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        if(n==0) return false;
        int i=0;
        int j=n-1;
        while(i<m&&j>=0){
            if(target==matrix[i][j]) return true;
            else if(target<matrix[i][j]) j--;
            else i++;
        }
        return false;
}

bool searchMatrix3(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        if(n==0) return false;
        if(target<matrix[0][0]) return false;
        int start=0,end=m-1;
        while(start<end){
            int mid = (start+end)/2;
            if(matrix[mid][0]==target||matrix[mid][n-1]==target) return true;
            if(matrix[mid][0]>target) end = mid-1;
            else if(matrix[mid][n-1]<target) start = mid+1;
            else start = end = mid;
        }
        int l=0,r=n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[start][mid]==target) return true;
            else if(matrix[start][mid]>target) r = mid-1;
            else l = mid+1;
        }
        return false;
}

int main(int argc,char *argv[]){
	return 0;
}
