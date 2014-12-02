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

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        static bool find = false;
        vector<int> res(2,-1);
        int l=0,r=n-1;
        int mid;
        while(l<=r){
            mid = (l+r)/2;
            if(A[mid]==target) break;
            else if(A[mid]<target) l = mid+1;
            else r = mid-1;
        }
        if(A[mid]==target){
            int t = mid;
            while(l<t){
                int m = (l+t)/2;
                if(A[m]<target) l = m+1;
                else{
                    if(m==t) break;
                    t = m;
                } 
            }
            res[0] = t;
            t = mid;
            while(t<r){
                int m = (r+t)/2;
                if(A[m]>target) r = m-1;
                else{
                    if(t==m) break;
                    t = m;
                }
            }
            if(t+1<n&&A[t+1]==target) res[1] = t+1;
            else res[1] = t;
        }
        return res;
    }
};


class Solution2 {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2,-1);
        if(n==0) return res;
        int l,r;
        l=0;r=n-1;
        while(l<r){
            int mid = (l+r)/2;
            if(A[mid]<target){
                l = mid+1;
                continue;
            }
            r = mid;
        }
        if(A[l]==target) res[0] = l;
        else return res;
        r = n;
        while(l<r){
            int mid = (l+r)/2;
            if(A[mid]>target){
                r = mid;
                continue;
            }
            l = mid+1;
        }
        res[1] = l-1;
        return res;
    }
};
