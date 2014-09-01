/*
Restore IP Addresses Total Accepted: 13334 Total Submissions: 65120
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n=s.size();
        if(n<4||n>12) return res;
        string mid;
        myStore(s,0,4,mid,res);
        return res;
    }
    void myStore(string s,int index,int f,string &mid,vector<string>& res){
        if(f==0){
            if(index==s.size()) res.push_back(mid);
            return;
        }
        if(index>=s.size()) return;
        if(mid.size()>0) mid += ".";
        if(s[index]=='0'){
            mid += s[index];
            myStore(s,index+1,f-1,mid,res);
            mid.resize(mid.size()-1);
        }else{
            for(int i=0;i<3&&i+index<s.size();++i){
                string tmp = s.substr(index,i+1);
                if(i==2&&atoi(tmp.c_str())>255) break;
                mid += tmp;
                myStore(s,index+i+1,f-1,mid,res);
                mid.resize(mid.size()-tmp.size());
            }
        }
        if(mid.size()>0) mid.resize(mid.size()-1);
    }
};
