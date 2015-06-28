/*
Summary Ranges Total Accepted: 3489 Total Submissions: 16861

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if(n<=0) return res;
        int start=0;
        int end=0;
        stringstream ss;
        for(int i=1;i<n;++i){
            if(nums[i]-1>nums[i-1]){
                ss<<nums[start];
                if(i-1==start){
                    string tmp = ss.str();
                    res.push_back(tmp);
                }else{
                    ss<<"->"<<nums[i-1];
                    string tmp = ss.str();
                    res.push_back(tmp);
                }
                start=end=i;
                ss.str("");
            }else end = i;
        }
        ss<<nums[start];
        if(end==start){
            string tmp = ss.str();
            res.push_back(tmp);
        }else{
            ss<<"->"<<nums[end];
            string tmp = ss.str();
            res.push_back(tmp);
        }
        return res;
    }
};
