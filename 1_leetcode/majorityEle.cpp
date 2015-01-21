/*
Majority Element Total Accepted: 9484 Total Submissions: 28263 My Submissions Question Solution 
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n = num.size();
        unordered_map<int,int> mark;
        for(int i=0;i<n;++i){
            mark[num[i]]++;
            if(mark[num[i]]*2>n) return num[i];
        }
        return -1;
    }
};
