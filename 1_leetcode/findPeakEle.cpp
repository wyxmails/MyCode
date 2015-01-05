/*
Find Peak Element Total Accepted: 8595 Total Submissions: 26922 My Submissions Question Solution 
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        int res = num[0]>num[n-1]?0:n-1;
        for(int i=1;i+1<n;++i){
            if(num[i]>num[i-1&&num[i]>num[i+1]])
                res = num[res]>num[i]?res:i;
        }
        return res;
    }
};

class Solution2 {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        int l=0,r=n-1;
        while(l<r){
            int m = l+(r-l)/2;
            if((m==0||num[m]>num[m-1])&&(m+1==n||num[m]>num[m+1])) return m;
            else if(m==0||num[m-1]<num[m]) l = m+1;
            else r = m-1;
        }
        return l;
    }
};
