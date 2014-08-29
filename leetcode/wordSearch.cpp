#include <iostream>
#include <vector>
using namespace std;
/*
 Given a 2D board and a word, find if the word exists in the grid.
 
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 
 For example,
 Given board =
 
 [
   ["ABCE"],
   ["SFCS"],
   ["ADEE"]
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.
 */
bool myExist(vector<vector<char> > &board, string word,int r,int c,int num){
	if(num>=word.size()) return true;
	if(r+1<board.size()&&board[r+1][c]==word[num]){
		board[r+1][c] = '.';
		if(myExist(board,word,r+1,c,num+1)) return true;
		board[r+1][c] = word[num];
	}
	if(r-1>=0&&board[r-1][c]==word[num]){
		board[r-1][c] = '.';
		if(myExist(board,word,r-1,c,num+1)) return true;
		board[r-1][c] = word[num];
	}
	if(c+1<board[0].size()&&board[r][c+1]==word[num]){
		board[r][c+1] = '.';
		if(myExist(board,word,r,c+1,num+1)) return true;
		board[r][c+1] = word[num];
	}
	if(c-1>=0&&board[r][c-1]==word[num]){
		board[r][c-1] = '.';
		if(myExist(board,word,r,c-1,num+1)) return true;
		board[r][c-1] = word[num];
	}
	return false;
}
bool exist(vector<vector<char> > &board, string word) {
	int m = board.size();
	if(m<=0) return false;
	int n = board[0].size();
	if(n<=0) return false;
	int num = word.size();
	if(num==0) return true;
	for(int i=0;i<board.size();++i){
		for(int j=0;j<board[0].size();++j){
			if(board[i][j]==word[0]){
				board[i][j] = '.';
				if(myExist(board,word,i,j,1)) return true;
				board[i][j] = word[0];
			}
		}
	}
	return false;
}
bool myEx(vector<vector<char> > &board,int i,int j,string word,int k){
        if(k>=word.size()) return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size()) 
            return false;
        if(board[i][j]==word[k]){
            char c = board[i][j];
            board[i][j] = ' ';
            if(myEx(board,i+1,j,word,k+1))
                return true;
            if(myEx(board,i-1,j,word,k+1))
                return true;
            if(myEx(board,i,j+1,word,k+1))
                return true;
            if(myEx(board,i,j-1,word,k+1))
                return true;
            board[i][j] = c;
        }
        return false;
}
bool exist2(vector<vector<char> > &board, string word) {
        if(word.size()==0) return true;
        int m = board.size();
        if(m==0) return false;
        int n = board[0].size();
        if(n==0) return false;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(myEx(board,i,j,word,0))
                    return true;
            }
        }
        return false;
}
int main(int argc,char*argv[]){
	return 0;
}
