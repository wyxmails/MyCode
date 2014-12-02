/*
 Problem Statement
     
 Cat Snuke is playing the Path Game.
  
 The Path Game is played on a rectangular grid of square cells. The grid has 2 rows and some positive number of columns. Each cell is either black or white.
  
 A left-to-right path in the grid is a sequence of white cells such that the first cell in the sequence is in the leftmost column, the last cell in the sequence is in the rightmost column, and each pair of consecutive cells shares a common side.
  
 The initial coloring of the grid is such that there is at least one left-to-right path. You are given this initial coloring as a vector <string> board with two elements. For each i and j, board[i][j] is either '#' (representing a black cell) or '.' (representing a white cell).
  
 Snuke may color some of the white cells black. After he does so, there must still be at least one left-to-right path left on the board. The goal of the game is to color as many cells black as possible. Compute and return the largest number of cells Snuke can color black. (Note that the cells that are already black do not count.)
 Definition
     
Class:
PathGameDiv2
Method:
calc
Parameters:
vector <string>
Returns:
int
Method signature:
int calc(vector <string> board)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
board will contain 2 elements.
-
Each element in board will contain between 1 and 50 characters, inclusive.
-
All elements in board will have the same length.
-
Each character in board will be '#' or '.'.
-
The grid described by board will contain a left-to-right path.
Examples
0)

    
{"#...."
,"...#."}
Returns: 2
Snuke can color at most two white cells black. One possible final state of the board looks as follows:
#....
..###
1)

    
{"#"
,"."}
Returns: 0
Snuke can't color any cells.
2)

    
{"."
,"."}
Returns: 1

3)

    
{"....#.##.....#..........."
,"..#......#.......#..#...."}
Returns: 13

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PathGameDiv2{
public:
int calc(vector <string> board);
};

int PathGameDiv2::calc(vector <string> board){
	int whites=0;
	int n = board[0].size();
	int p1 = board[0].find_first_of('#');
	int p2 = board[1].find_first_of('#');
	if(p1==-1) p1=n;
	if(p2==-1) p2=n;
	int cur = p1>p2?0:1;
	int trans = 0;
	for(int i=0;i<n;++i){
		if(board[0][i]=='.') whites++;
		if(board[1][i]=='.') whites++;
		if(board[cur][i]=='#'){
			trans++;
			cur = !cur;
		}
	}
	int res = whites-n-trans;
	return res;
}

