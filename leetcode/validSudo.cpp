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
int main(int argc,char*argv[]){
	return 0;
}
