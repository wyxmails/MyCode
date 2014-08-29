/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> res;
        string str;
        set<char> set1,set2;
        for(int i=0;i<s.size();++i) set1.insert(s[i]);
        for(unordered_set<string>::iterator it=dict.begin();it!=dict.end();++it){
            for(int j=0;j<(*it).size();++j) set2.insert((*it)[j]);
        }
        if(set1.size()>set2.size()) return res;
        
        if(dict.find(s)!=dict.end()) res.push_back(s);
        vector<string> mid;
        for(int i=1;i<s.size();++i){
            mid.clear();
            string s1 = s.substr(0,i);
            if(dict.find(s1)!=dict.end()){
                string s2 = s.substr(i);
                mid = wordBreak(s2,dict);
                for(int j=0;j<mid.size();++j){
                    res.push_back(s1+" "+mid[j]);
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<string> res;
        if(n==0) return res;
        vector<string> mid;
        vector<bool> mark(n,true);
        myW(s,0,n,mid,res,dict,mark);
        return res;
    }
    void myW(string s, int l,int len,vector<string>&mid, vector<string>&res, unordered_set<string> &dict,vector<bool>&mark){
        if(l==len){
            string str = "";
            for(int i=0;i<mid.size();++i){
                if(i!=0) str += " ";
                str += mid[i];
            }
            res.push_back(str);
        }
        for(int i=l;i<len;++i){
            string str = s.substr(l,i-l+1);
            if(dict.find(str)!=dict.end()&&mark[i+1]){
                mid.push_back(str);
                int before = res.size();
                myW(s,i+1,len,mid,res,dict,mark);
                if(res.size()==before) mark[i+1] = false;
                mid.pop_back();
            }
        }
    }
};
