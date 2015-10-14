/*
Number of Islands My Submissions Question Solution 
Total Accepted: 22490 Total Submissions: 94245 Difficulty: Medium
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        if(n==0) return 0;
        vector<vector<bool> > mark(m,vector<bool>(n,true));
        int res = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='1'&&mark[i][j]){
                    queue<pair<int,int> > myQ;
                    myQ.push(make_pair(i,j));
                    mark[i][j] = false;
                    while(!myQ.empty()){
                        pair<int,int> mp  = myQ.front();
                        myQ.pop();
                        int x = mp.first,y=mp.second;
                        if(x+1<m&&mark[x+1][y]&&grid[x+1][y]=='1'){
                            mark[x+1][y] = false;
                            myQ.push(make_pair(x+1,y));
                        }
                        if(x-1>=0&&mark[x-1][y]&&grid[x-1][y]=='1'){
                            mark[x-1][y] = false;
                            myQ.push(make_pair(x-1,y));
                        }
                        if(y+1<n&&mark[x][y+1]&&grid[x][y+1]=='1'){
                            mark[x][y+1] = false;
                            myQ.push(make_pair(x,y+1));
                        }
                        if(y-1>=0&&mark[x][y-1]&&grid[x][y-1]=='1'){
                            mark[x][y-1] = false;
                            myQ.push(make_pair(x,y-1));
                        }
                    }
                    res++;
                }else mark[i][j] = false;
            }
        }
        return res;
    }
};
