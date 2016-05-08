/*
347. Top K Frequent Elements   My Submissions QuestionEditorial Solution
Total Accepted: 4624 Total Submissions: 10437 Difficulty: Medium
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> keys;
        map<int,vector<int>> times;
        for(int i=0;i<nums.size();++i){
            auto it = keys.find(nums[i]);
            if(it!=keys.end())
                it->second = it->second+1;
            else
                keys.insert(pair<int,int>(nums[i], 1));
        }
        for(auto it=keys.begin();it!=keys.end();++it){
            int v = it->second;
            times[v].push_back(it->first);
        }
        vector<int> res;
        for(auto it=times.rbegin();it!=times.rend();++it){
            vector<int> tmp = it->second;
            for(int i=0;i<tmp.size();++i){
                if(k>0){
                    res.push_back(tmp[i]);
                    k--;
                }else
                    break;
            }
            if(k==0) break;
        }
        return res;
    }
};
