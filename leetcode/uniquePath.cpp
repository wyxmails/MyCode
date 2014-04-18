/*Unique Paths
 A robot is located at the top-left corner of 
 a m x n grid (marked 'Start' in the diagram below).
 The robot can only move either down or right at any point in time. 
 The robot is trying to reach the bottom-right corner 
 of the grid (marked 'Finish' in the diagram below).
 How many possible unique paths are there?
Note: m and n will be at most 100.*/
int uniquePaths(int m, int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	static int arr[100][100];
	if(m==1||n==1) return 1;
	if(arr[m-1][n-1]!=0) return arr[m-1][n-1];
	int r = uniquePaths(m,n-1);
	int d = uniquePaths(m-1,n);
	arr[m-1][n-1] = r+d;
	return arr[m-1][n-1];
}
