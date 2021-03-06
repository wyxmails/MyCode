/*
Gray Code Total Accepted: 15118 Total Submissions: 47113 My Submissions
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.


*/

class Solution {
public:
    vector<int> grayCode(int n) {
        int m = 1<<n;
        vector<int> res;
        for(int i=0;i<m;++i){
            res.push_back(i^(i>>1));
        }
        return res;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        /*nth results = (n-1)th results + [(1<<(n-1))+reverse((n-1)th results)]*/
        vector<int> res;
        res.push_back(0);
        for(int i=0;i<n;++i){
            int len = res.size();
            int highbits = 1<<i;
            for(int j=len-1;j>=0;--j){
                res.push_back(highbits+res[j]);
            }
        }
        return res;
    }
};
