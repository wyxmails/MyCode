/*
Edit Distance Total Accepted: 13868 Total Submissions: 54987 My Submissions
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n = word2.size();
        if(m==0||n==0) return m==0?n:m;
        vector<vector<int> > mark(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;++i) mark[i][0] = i;
        for(int j=0;j<=n;++j) mark[0][j] = j;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(word1[i]==word2[j]) mark[i+1][j+1] = mark[i][j];
                else mark[i+1][j+1] = 1+min(min(mark[i][j],mark[i][j+1]),mark[i+1][j]);
            }
        }
        return mark[m][n];
    }
};
