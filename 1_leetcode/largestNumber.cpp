/*
Largest Number Total Accepted: 8309 Total Submissions: 55631 My Submissions Question Solution 
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

bool cmp(const string&a,const string&b){
    string tmp1,tmp2;
    tmp1 = a+b;
    tmp2 = b+a;
    return tmp1>tmp2;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> vec;
        int n = num.size();
        for(int i=0;i<n;++i){
            string tmp = to_string(num[i]);
            vec.push_back(tmp);
        }
        sort(vec.begin(),vec.end(),cmp);
        string res = "";
        for(int i=0;i<n;++i)
            res += vec[i];
        while(res.size()>1&&res[0]=='0') res.erase(res.begin());
        return res;
    }
};
