/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
class Solution {
public:
    int jump(int A[], int n) {
        if(n<=1) return 0;
        if(A[0]>=n-1) return 1;
        vector<int> mark(n,0);
        int j=1;
        while(j<=A[0]) mark[j++] = 1;
        for(int i=1;i<n;++i){
            int k = i+A[i];
            if(k<j) continue;
            for(int m = j;m<=k&&m<n;++m) mark[m] = mark[i]+1;
            j = k+1;
            if(j>=n) break;
        }
        return mark[n-1];
    }
};
