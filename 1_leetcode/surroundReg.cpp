/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
void solve(vector<vector<char>> &board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        if(n==0) return;
        queue<pair<int,int> > mark;
        for(int i=0;i<m;++i){
            if(board[i][0]=='O'){
                board[i][0] = 'N';
                mark.push(make_pair(i,0));
            }
            if(board[i][n-1]=='O'){
                board[i][n-1] = 'N';
                mark.push(make_pair(i,n-1));
            }
        }
        for(int j=0;j<n;++j){
            if(board[0][j]=='O'){
                board[0][j] = 'N';
                mark.push(make_pair(0,j));
            }
            if(board[m-1][j]=='O'){
                board[m-1][j] = 'N';
                mark.push(make_pair(m-1,j));
            }
        }
        while(!mark.empty()){
            int r = mark.front().first;
            int c = mark.front().second;
            mark.pop();
            if(r>0&&board[r-1][c]=='O'){
                board[r-1][c] = 'N';
                mark.push(make_pair(r-1,c));
            }
            if(r<m-1&&board[r+1][c]=='O'){
                board[r+1][c] = 'N';
                mark.push(make_pair(r+1,c));
            }
            if(c>0&&board[r][c-1]=='O'){
                board[r][c-1] = 'N';
                mark.push(make_pair(r,c-1));
            }
            if(c<n-1&&board[r][c+1]=='O'){
                board[r][c+1] = 'N';
                mark.push(make_pair(r,c+1));
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='N') board[i][j] = 'O';
                else if(board[i][j]=='O') board[i][j] = 'X';
            }
        }
}
