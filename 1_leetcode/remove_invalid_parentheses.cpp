/*
301. Remove Invalid Parentheses My Submissions Question
Total Accepted: 6847 Total Submissions: 22847 Difficulty: Hard
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]

*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        vector<bool> left(n,false);
        int l=0,r=0;
        max_len = 0;
        set<string> mid;
        getRes(0,l,r,left,mid,s);
        vector<string> res;
        for(auto it=mid.begin();it!=mid.end();++it){
            if((*it).size()==max_len)
                res.push_back(*it);
        }
        return res;
    }
    void getRes(int cur,int l,int r,vector<bool> &left,set<string> &res,string s){
        if(cur>=n){
            if(l==r)
                addRes(left,s,res);
            return;
        }
        if(s[cur]=='('){ 
            left[cur] = false;
            getRes(cur+1,l,r,left,res,s);
            left[cur] = true;
            getRes(cur+1,l+1,r,left,res,s);
        }else if(s[cur]==')'){
            left[cur] = false;
            getRes(cur+1,l,r,left,res,s);
            left[cur] = true;
            if(r+1<=l)
                getRes(cur+1,l,r+1,left,res,s);
        }else{
            left[cur] = true;
            getRes(cur+1,l,r,left,res,s);
        }
    }
    void addRes(const vector<bool> &left,string s,set<string> &res){
        string str = "";
        for(int i=0;i<n;++i){
            if(left[i]){
                str += s[i];
            }
        }
        int len = str.size();
        max_len = max(max_len,len);
        res.insert(str);
    }
private:
    int n;
    int max_len;
};
