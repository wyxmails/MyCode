/*
Excel Sheet Column Number Total Accepted: 4605 Total Submissions: 11068 My Submissions Question Solution 
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int n = s.size();
        for(int i=0;i<n;++i)
            res = res*26+int(s[i]-'A')+1;
        return res;
    }
};
