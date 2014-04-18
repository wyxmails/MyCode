/*Search for a Range
   Given a sorted array of integers, 
  find the starting and ending position of a given target value.
 Your algorithm's runtime complexity must be 
 in the order of O(log n).
 If the target is not found in the array, return [-1, -1].
 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
 */
vector<int> searchRange(int A[], int n, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int l,r,m;
	l=0;
	r=n-1;
	vector<int> res;
	res.push_back(-1);
	res.push_back(-1);
	while(l<=r){
		m = l + (r-l)/2;
		if(A[m]==target) break;
		if(A[m]<target){
			l = m+1;
		}else{
			r = m-1;
		}
	}
	if(A[m]==target){
		l=m;
		while(A[l]==target) l--;
		r=m;
		while(r<n&&A[r]==target) r++;
		res[0] = l+1;
		res[1] = r-1;
	}
	return res;
}
