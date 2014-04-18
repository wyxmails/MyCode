/*Unique Paths II
 Follow up for "Unique Paths":
 Now consider if some obstacles are added to the grids. 
 How many unique paths would there be?
 An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 For example,
 There is one obstacle in the middle of a 3x3 grid as illustrated below.
 [
   [0,0,0],
   [0,1,0],
   [0,0,0]
 ]
 The total number of unique paths is 2.
Note: m and n will be at most 100.
 */
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int m=obstacleGrid.size();
	int n=obstacleGrid[0].size();
	int arr[n+1];
	int i=n-1;
	m--;
	arr[i+1] = 0;
	while(i>=0&&obstacleGrid[m][i]==0){
		arr[i]=1;
		i--;
	}
	while(i>=0){
		arr[i] = 0;
		i--;
	}
	while(m-->0){
		for(i=n-1;i>=0;--i){
			arr[i] = (obstacleGrid[m][i]==1)?0:arr[i+1]+arr[i];
		}
	}
	return arr[0];
}
