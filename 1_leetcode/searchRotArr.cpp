/*Search in Rotated Sorted Array
   Suppose a sorted array is rotated 
   at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 You are given a target value to search.
 If found in the array return its index, otherwise return -1. 
 You may assume no duplicate exists in the array.
 */
int search(int A[], int n, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int l=0,r=n-1;
	int m;
	while(l<=r){
		m = l + (r-l)/2;
		if(A[m]==target) return m;
		if(A[l]<=A[m]){
			if(A[l]<=target&&target<A[m])
				r = m-1;
			else
				l = m+1;
		}else{
			if(A[m]<target&&target<=A[r])
				l = m+1;
			else
				r = m-1;
		}
	}
	return -1;
}
int search2(int A[], int n, int target) {
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(target==A[mid]) return mid;
            else if(target<A[mid]){
                if(A[mid]<A[l]||A[l]<=target) r = mid-1;
                else l = mid+1; 
            }else{
                if(A[mid]>A[r]||A[r]>=target) l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
}
