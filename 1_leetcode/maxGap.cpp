/*
Maximum Gap Total Accepted: 3977 Total Submissions: 16569 My Submissions Question Solution 
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

*/

class Solution {
public:
    int maximumGap(vector<int> &num) {
        int n = num.size();
        if(n<2) return 0;
        set<int> mark;
        for(int i=0;i<n;++i)
            mark.insert(num[i]);
        auto it = mark.begin();
        int cur = *it;
        int res = 0;
        it++;
        for(;it!=mark.end();++it){
            res = max((*it)-cur,res);
            cur = *it;
        }
        return res;
    }
};
