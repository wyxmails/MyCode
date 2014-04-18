/*Rotate Image
 You are given an n x n 2D matrix representing an image.
 Rotate the image by 90 degrees (clockwise).
 Follow up:
 Could you do this in-place?
 */
void rotate(vector<vector<int> > &matrix) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int i,j,n,tmp;
	n=matrix.size();
	for(i=0;i<n;++i){
		for(j=0;j<n/2;++j){
			tmp = matrix[i][j];
			matrix[i][j] = matrix[i][n-j-1];
			matrix[i][n-j-1] = tmp;
		}
	}
	for(i=0;i<n;++i){
		for(j=0;j<n-i;++j){
			tmp = matrix[i][j];
			matrix[i][j] = matrix[n-j-1][n-i-1];
			matrix[n-j-1][n-i-1] = tmp;
		}
	}
}
