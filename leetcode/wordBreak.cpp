/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        string s1 = "#"+s;
        int n = s.size()+1;
        vector<bool> mark(n,false);
        mark[0] = true;
        for(int i=1;i<n;++i){
            for(int k=0;k<i;++k){
                mark[i] = mark[k]&&dict.end()!=dict.find(s1.substr(k+1,i-k));
                if(mark[i]) break;
            }
        }
        return mark[n-1];
    }
    
};
