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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(dict.find(s)!=dict.end()) return true;
        
        set<char> set1,set2;
        for(int i=0;i<s.size();++i) set1.insert(s[i]);
        for(unordered_set<string>::iterator it=dict.begin();it!=dict.end();++it){
            for(int j=0;j<(*it).size();++j) set2.insert((*it)[j]);
        }
        if(set2.size()<set1.size()) return false;
        
        for(int i=1;i<s.size();++i){
            string s1 = s.substr(0,i);
            if(dict.find(s1)!=dict.end()){
                string s2 = s.substr(i,s.size()-i);
                if(wordBreak(s2,dict)) return true;
            }
        }
        return false;
    }
};

class Solution2 {
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
