/*

Problem Statement
    
Fox Ciel is going to play Gomoku with her friend Fox Jiro. Ciel plays better, so before they start she allowed Jiro to put some of his pieces on the board.   You are given a vector <string> board that represents a square board. The character board[i][j] represents the cell with coordinates (i,j). Each of those characters is either '.' (representing an empty cell) or 'o' (representing a cell with Jiro's piece).   Of course, Ciel does not want Jiro to win the game before she has a chance to play. Thus she now has to check the board and determine whether there are five consecutive tokens somewhere on the board.   Determine whether there are 5 consecutive cells (horizontally, vertically, or diagonally) that contain Jiro's tokens. Return "found" (quotes for clarity) if there are five such cells anywhere on the board. Otherwise, return "not found".
Definition
    
Class:
FoxAndGomoku
Method:
win
Parameters:
vector <string>
Returns:
string
Method signature:
string win(vector <string> board)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
n will be between 5 and 15, inclusive.
-
board will contain exactly n elements.
-
Each element in board will contain exactly n characters.
-
Each character in board will be 'o' or '.'.
Examples
0)

    
{"....o.",
 "...o..",
 "..o...",
 ".o....",
 "o.....",
 "......"}
Returns: "found"
There is five continue pieces diagonally.
1)

    
{"oooo.",
 ".oooo",
 "oooo.",
 ".oooo",
 "....."}
 
Returns: "not found"
There is no five-in-a-row on this board.
2)

    
{"oooo.",
 ".oooo",
 "oooo.",
 ".oooo",
 "....o"}
 
Returns: "found"
Five consecutive tokens can be found in the following cells: (0,0), (1,1), (2,2), (3,3), and (4,4).
3)

    
{"o.....",
 ".o....",
 "..o...",
 "...o..",
 "....o.",
 "......"}
Returns: "found"

4)

    
{"o....",
 "o.o..",
 "o.o.o",
 "o.o..",
 "o...."}
Returns: "found"

5)

    
{"..........",
 "..........",
 "..oooooo..",
 "..o.......",
 "..o.......",
 "..oooooo..",
 ".......o..",
 ".......o..",
 "..oooooo..",
 ".........."}
 
Returns: "found"

6)

    
{"..........",
 "..........",
 "..oooo.o..",
 "..o.......",
 "..o.......",
 "..o.oooo..",
 ".......o..",
 ".......o..",
 "..oooo.o..",
 ".........."}
Returns: "not found"

7)

    
{"ooooo",
 "ooooo",
 "ooooo",
 "ooooo",
 "ooooo"}
Returns: "found"

8)

    
{".....",
 ".....",
 ".....",
 ".....",
 "....."}
Returns: "not found"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class FoxAndGomoku{
public:
	string win(vector <string> board){
		string yes("found"),no("not found");
		int n = board.size();
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(board[i][j]=='o'){
					//horizontal
					int k;
					for(k=1;k<5&&i+k<n;++k)
						if(board[i+k][j]!='o') break;
					if(k==5) return yes;
					//vertical
					for(k=1;k<5&&j+k<n;++k)
						if(board[i][j+k]!='o') break;
					if(k==5) return yes;
					//diagnal
					for(k=1;k<5&&i+k<n&&j+k<n;++k)
						if(board[i+k][j+k]!='o') break;
					if(k==5) return yes;
					//counter diagnal
					for(k=1;k<5&&i-k>=0&&j+k<n;++k)
						if(board[i-k][j+k]!='o') break;
					if(k==5) return yes;
				}
			}
		}
		return no;
	}
};
