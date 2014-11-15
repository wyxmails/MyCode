#include <iostream>
#include <vector>
using namespace std;
/*
 Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 
 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 
 
 A partially filled sudoku which is valid.
 
Note:
 A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */
bool isValidSudoku(vector<vector<char> > &board) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	int arr[9];	
	if(board.size()!=9) return false;
	if(board[0].size()!=9) return false;
	for(int i=0;i<9;++i){
		for(int m=0;m<9;++m) arr[m] = 0;
		for(int j=0;j<9;++j){
			if(board[i][j]=='.') continue;
			int tmp = int(board[i][j]-'0');
			if(tmp<=0||tmp>9) return false;
			if(arr[tmp-1]!=0) return false;
			arr[tmp-1] = 1;
		}
		for(int m=0;m<9;++m) arr[m] = 0;
		for(int j=0;j<9;++j){
			if(board[j][i]=='.') continue;
			int tmp = int(board[j][i]-'0');
			if(tmp<=0||tmp>9) return false;
			if(arr[tmp-1]!=0) return false;
			arr[tmp-1] = 1;
		}
	}
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			for(int m=0;m<9;++m) arr[i] = 0;
			for(int k=0;k<3;++k){
				for(int m=0;m<3;++m){
					if(board[3*i+k][3*j+m]=='.') continue;
					int tmp = int(board[3*i+k][3*j+m]-'0');
					if(tmp<=0||tmp>9) return false;
					if(arr[tmp-1]!=0) return false;
					arr[tmp-1] = 1;
				}
			}
		}
	}
	return true;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int n = board.size();
        for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            if(board[i][j]!='.'){
                if(!valid(board,i,j)) return false;
            }
        }
        return true;
    }
    bool valid(vector<vector<char> > &board,int i,int j){
        int n = board.size();
        for(int k=0;k<n;++k){
            if(k!=i&&board[k][j]==board[i][j]) return false;
            if(k!=j&&board[i][k]==board[i][j]) return false;
        }
        for(int r=(i/3)*3;r<(i/3+1)*3;++r){
            for(int c=(j/3)*3;c<(j/3+1)*3;++c){
                if(r==i&&c==j) continue;
                if(board[r][c]==board[i][j]) return false;
            }
        }
        return true;
    }
};

int main(int argc,char*argv[]){
	return 0;
}
