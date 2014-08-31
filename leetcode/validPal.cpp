/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r = s.size()-1;
        while(l<r){
            if(s[l]==s[r]||tolower(s[l])==tolower(s[r])){
                l++; r--;
            }else{
                int t1 = s[l]-'0';
                int t2 = tolower(s[l])-'a';
                if((t1<0||t1>9)&&(t2<0||t2>=26)) l++;
                else{
                    t1 = s[r]-'0';
                    t2 = tolower(s[r])-'a';
                    if((t1<0||t1>9)&&(t2<0||t2>=26)) r--;
                    else return false;
                }
            }
        }
        return true;
    }
};
