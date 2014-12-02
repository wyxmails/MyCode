/*
Maximum Subarray Total Accepted: 23393 Total Submissions: 69375 My Submissions
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int M = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;++i){
            sum += A[i];
            M = max(sum,M);
            if(sum<0) sum = 0;
        }
        return M;
    }
};

/*Divide & Conquer*/
class SolutionDC {
public:
    int maxSubArray(int A[], int n) {
        int M = INT_MIN;
        return myMax(A,0,n-1,M);
    }
    int myMax(int A[],int l,int r,int &M){
        if(l>r) return INT_MIN;
        int mid = (l+r)/2;
        int lmax = myMax(A,l,mid-1,M);
        int rmax = myMax(A,mid+1,r,M);
        M = max(lmax,M);
        M = max(rmax,M);
        int ll,rr,sum;
        ll=sum=0;
        for(int i=mid-1;i>=l;--i){
            sum += A[i];
            if(sum>ll) ll = sum;
        }
        rr=sum=0;
        for(int i=mid+1;i<=r;++i){
            sum += A[i];
            if(sum>rr) rr = sum;
        }
        M = max(ll+rr+A[mid],M);
        return M;
    }
};
