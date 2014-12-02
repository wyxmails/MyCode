/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(int A[], int n) {
        if(n==0) return true;
        if(A[0]>=n-1) return true;
        vector<bool> mark(n,false);
        int j=0;
        while(j<A[0]){
            mark[j] = true;
            j++;
        }
        for(int i=1;i<n;++i){
            if(i>j) return false;
            int k = i+A[i];
            if(k<j) continue;
            j = k;
            while(mark[k]==false){
                mark[k] = true;
                k--;
            } 
        }
        return mark[n-1];
    }
};
