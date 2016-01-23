/*
329. Longest Increasing Path in a Matrix My Submissions Question
Total Accepted: 1740 Total Submissions: 5704 Difficulty: Medium
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:
nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:
nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m==0) return 0;
        n = matrix[0].size();
        if(n==0) return 0;
        int max_len = 1;
        vector<vector<int>> res(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                max_len = max(max_len,dfs(i,j,matrix,res));
            }
        }
        return max_len;
    }
    int dfs(int x,int y,const vector<vector<int>>& matrix,vector<vector<int>>& res){
        if(res[x][y]>0) return res[x][y];
        int max_len = 1;
        for(int i=0;i<4;++i){
            int t1 = x+xx[i],t2=y+yy[i];
            if(legal(t1,t2)&&matrix[t1][t2]>matrix[x][y]){
                if(res[t1][t2]>0)
                    max_len = max(max_len,res[t1][t2]+1);
                else
                    max_len = max(max_len,dfs(t1,t2,matrix,res)+1);
            }
        }
        res[x][y] = max_len;
        return max_len;
    }
    bool legal(int x,int y){
        if(x<0||x>=m) return false;
        if(y<0||y>=n) return false;
        return true;
    }
private:
    int m,n;
    int xx[4] = {-1,1,0,0};
    int yy[4] = {0,0,-1,1};
};
