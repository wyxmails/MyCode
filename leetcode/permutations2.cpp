/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> mid;
        sort(num.begin(),num.end());
        myPer(num,mid,res);
        return res;
    }
    void myPer(vector<int> &num,vector<int> &mid,vector<vector<int> >& res){
        int n = num.size();
        if(n==0){
            res.push_back(mid);
            return;
        }
        for(int i=0;i<n;++i){
            if(i!=0&&num[i]==num[i-1]) continue;
            vector<int> tmp = num;
            tmp.erase(tmp.begin()+i);
            mid.push_back(num[i]);
            myPer(tmp,mid,res);
            mid.pop_back();
        }
    }
};
