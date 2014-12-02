/*
 Problem Statement
     
 Cat Taro has a square grid with N rows and N columns. Each cell of the grid is painted either black or white. You are given a vector <string> grid which represents the current state of the grid. Each element of grid represents one row of the grid. In grid, the character 'W' represents a white cell, and the character 'B' represents a black cell.

 Taro wants to choose a set of consecutive cells that are in the same column and are painted in the same color. Return the largest number of cells he can choose.
 Definition
     
Class:
TaroGrid
Method:
getNumber
Parameters:
vector <string>
Returns:
int
Method signature:
int getNumber(vector <string> grid)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
N will be between 1 and 50, inclusive.
-
grid will contain exactly N elements.
-
Each element of grid will contain exactly N characters.
-
Each character in grid will be 'W' or 'B'.
Examples
0)

    
{"W"}
Returns: 1

1)

    
{"WB",
 "BW"}
Returns: 1

2)

    
{"BWW",
"BBB",
"BWB"}
Returns: 3
He can choose the entire leftmost column (i.e., character 0 of each element of grid).
3)

    
{"BWBW",
"BBWB",
"WWWB",
"BWWW"}
Returns: 3

4)

    
{"BWB",
"BBW",
"BWB"}
Returns: 3

5)

    
{"BBWWBBWW",
"BBWWBBWW",
"WWBBWWBB",
"WWBBWWBB",
"BBWWBBWW",
"BBWWBBWW",
"WWBBWWBB",
"WWBBWWBB"}
Returns: 2
Note that the chosen cells must be consecutive.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
using namespace std;

class TaroGrid{
public:
	int getNumber(vector <string> grid);
};

int TaroGrid::getNumber(vector <string> grid){
	int N = grid.size();
	int res=1;
	for(int j=0;j<N;++j){
		int i=1;
		while(i<N){
			int cnt=1;
			while(i<N&&grid[i][j]==grid[i-1][j]){
				cnt++;i++;
			}
			if(cnt>res) res = cnt;
			i++;
		}
	}
	return res;
}
