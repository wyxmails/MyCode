/*
344. Reverse String   My Submissions QuestionEditorial Solution
Total Accepted: 16292 Total Submissions: 27649 Difficulty: Easy
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

*/

class Solution {
public:
    string reverseString(string s) {
        string res = "";
        int n = s.size();
        for(int i=n-1;i>=0;--i)
            res += s[i];
        return res;
    }
};
