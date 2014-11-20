/*
Problem Statement
    
Alien Fred wants to destroy the Earth. But before he does that, he wants to play the following game.

He has a rectangular board divided into unit cells. Each cell is initially painted black or white. You are given a vector <string> board. The character board[i][j] represents the cell with coordinates (i, j). Each of those characters is either 'B' (representing a black cell) or 'W' (representing a white cell). The game is played in turns. In each turn Fred can choose any row of the board and repaint all black cells of the row to white, and vice versa. (Note that he can only select rows, not columns. Formally, he can choose an index i and change all characters of board[i].)

Fred wants to have a large white square somewhere on his board. The sides of Fred's square must be parallel to the sides of the board. The white square may be a part of a larger white area. (I.e., the cells that touch the square may be both black and white.) Find a sequence of turns that produces the largest possible white square somewhere on the board, and return the area of that square.
Definition
    
Class:
AlienAndGame
Method:
getNumber
Parameters:
vector <string>
Returns:
int
Method signature:
int getNumber(vector <string> board)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
board will contain between 1 and 50 elements, inclusive.
-
Each element of board will contain between 1 and 50 characters, inclusive.
-
Each element of board will contain the same number of characters.
-
Each character in each element of board will be either 'B' or 'W'.
Examples
0)

    
{"BB",
 "WW"}
Returns: 4
The optimal strategy is to repaint row 0. After this change the entire board will be white, and thus we have a 2*2 white square.
1)

    
{"W"}
Returns: 1
Sometimes the optimal strategy requires no repainting.
2)

    
{"WBBB",
 "WBBB",
 "WWWW"}
Returns: 9
We should repaint row 0 and then repaint row 1. The resulting board will contain a 3*3 white square (in rows 0-2 and columns 1-3).
3)

    
{"W",
 "B",
 "W",
 "W",
 "W"}
Returns: 1

4)

    
{"BWBBWBB",
 "WWBWWBW",
 "BBBBBBW",
 "WBBBBWB",
 "BBWWWWB",
 "WWWWWWW",
 "BBWWBBB"}
Returns: 9

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class AlienAndGame{
public:
	int getNumber(vector <string> board){
		int m = board.size();
		if(m==0) return 0;
		int n = board[0].size();
		if(n==0) return 0;
		vector<vector<int> > mark(m+1,vector<int>(n,0));
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				if(j==0||board[i][j]!=board[i][j-1]) mark[i][j] = 1;
				else mark[i][j] = mark[i][j-1]+1;
			}
		}
		int res=0;
		for(int j=0;j<n;++j){
			stack<int> ms;
			for(int i=0;i<=m;){
				if(ms.empty()||mark[i][j]>=mark[ms.top()][j]) ms.push(i++);
				else{
					int h = mark[ms.top()][j];
					ms.pop();
					int side = min(h,ms.empty()?i:i-ms.top()-1);
					res = max(res,side*side);
				}
			}
		}
		return res;
	}
};
