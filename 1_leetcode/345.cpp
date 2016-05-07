/*
345. Reverse Vowels of a String   My Submissions QuestionEditorial Solution
Total Accepted: 10310 Total Submissions: 29177 Difficulty: Easy
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

*/

class Solution {
public:
    string reverseVowels(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            if(!isVowel(s[l])){
                l++;
                continue;
            }
            if(!isVowel(s[r])){
                r--;
                continue;
            }
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            l++;
            r--;
        }
        return s;
    }
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'
            ||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        return false;
    }
};
