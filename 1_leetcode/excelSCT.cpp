/*
Excel Sheet Column Title Total Accepted: 6445 Total Submissions: 37361 My Submissions Question Solution 
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n>0){
            int tmp = (n-1)%26;
            res = char('A'+tmp)+res;
            n = (n-1)/26;
        }
        return res;
    }
};
