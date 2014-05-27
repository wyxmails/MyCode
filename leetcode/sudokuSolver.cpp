#include <iostream>
#include <vector>
using namespace std;
/*
 Write a program to solve a Sudoku puzzle by filling the empty cells.
 
 Empty cells are indicated by the character '.'.
 
 You may assume that there will be only one unique solution.
 
 A sudoku puzzle...
 ...and its solution numbers marked in red.
 */
bool solve(vector<vector<char> > &board,int row,int col){
	for(int i=0;i<9;++i){
		if(i!=row&&board[i][col]==board[row][col]) return false;
		if(i!=col&&board[row][i]==board[row][col]) return false;
	}
	for(int i=3*(row/3);i<3*(row/3+1);++i){
		for(int j=3*(col/3);j<3*(col/3+1);++j){
			if(i!=row&&j!=col&&board[i][j]==board[row][col]) return false;
		}
	}
	return true;
}
bool solveSudoku(vector<vector<char> > &board) {
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			if('.'==board[i][j]){
			for(int k=1;k<=9;++k){
				board[i][j] = '0'+k;
				if( solve(board,i,j) && solveSudoku(board) )
					return true;
				board[i][j] = '.';
			}
			return false;
			}
		}
	}
	return true;
}
int main(int argc,char*argv[]){
	return 0;
}
