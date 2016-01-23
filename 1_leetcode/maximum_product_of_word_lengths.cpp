/*
318. Maximum Product of Word Lengths My Submissions Question
Total Accepted: 8710 Total Submissions: 22556 Difficulty: Medium
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".
Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int max_p = 0;
        vector<int> mark(n,0);
        for(int i=0;i<n;++i){
            for(int k=0;k<words[i].size();++k)
                mark[i] |= 1<<(words[i][k]-'a');
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if((mark[i]&mark[j])==0)
                    max_p = max(max_p,int(words[i].size()*words[j].size()));
            }
        }
        return max_p;
    }
};
