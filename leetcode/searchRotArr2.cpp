/*
Search in Rotated Sorted Array II
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(A[mid]==target) return true;
            else if(A[l]<A[mid]){
                if(target>A[mid]||target<A[l]) l = mid+1;
                else r = mid-1;
            }else if(A[l]>A[mid]){
                if(target<A[mid]||target>=A[l]) r = mid-1;
                else l = mid+1;
            }else l++;
        }
        return false;
    }
};
