/*

Problem Statement
    
Have you ever had a dream, that you were so sure was real? What if you were unable to wake from that dream? How would you know the difference between the dream world and the real world?
  
To answer this complex puzzle, one of the questions that must be answered is to find out whether the world that you live in can be represented by a chess matrix.
  
Cells of a matrix are called adjacent if they share an edge. A matrix of zeroes and ones is called a chess matrix if there are no two adjacent cells that share the same value. Hence, in a chess matrix the zeroes and ones have to alternate in the same way the colors alternate on a chessboard:
  
 
  
You are given a vector <string> board that represents a rectangular grid of cells, with a 0 or a 1 in each cell. Each character of each element of board will be either '0' or '1'. In this grid we selected some rectangular subgrid that is a chess matrix. Return the largest possible area of the selected subgrid.
Definition
    
Class:
TheMatrix
Method:
MaxArea
Parameters:
vector <string>
Returns:
int
Method signature:
int MaxArea(vector <string> board)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
board will contain between 1 and 100 elements, inclusive.
-
Each element of the board is a string containing between 1 and 100 characters, inclusive.
-
All elements of board will have the same length.
-
Each character of each element of board will be either '0' or '1'.
Examples
0)

    
{"1", 
 "0"}
Returns: 2
The entire board is a chess matrix.
1)

    
{"0000"}
Returns: 1
The largest possible chess matrix here is just a single cell.
2)

    
{"01"}
Returns: 2
Again, the entire board is a chess matrix.
3)

    
{"001",
 "000",
 "100"}
Returns: 2
Each rectangular subgrid is determined by a contiguous range of rows and a contiguous range of columns. The four corners of this grid do not form a valid rectangular subgrid.
4)

    
{"0"}
Returns: 1

5)

    
{"101", 
 "010"}
Returns: 6

6)

    
{"101", 
 "011", 
 "101", 
 "010"}
Returns: 8

7)

    
{"11001110011000110001111001001110110011010110001011", 
 "10100100010111111011111001011110101111010011100001", 
 "11101111001110100110010101101100011100101000010001", 
 "01000010001010101100010011111000100100110111111000", 
 "10110100000101100000111000100001011101111101010010", 
 "00111010000011100001110110010011010110010011100100", 
 "01100001111101001101001101100001111000111001101010", 
 "11010000000011011010100010000000111011001001100101", 
 "10100000000100010100100011010100110110110001000001", 
 "01101010101100001100000110100110100000010100100010", 
 "11010000001110111111011010011110001101100011100010", 
 "11101111000000011010011100100001100011111111110111", 
 "11000001101100100011000110111010011001010100000001", 
 "00100001111001010000101101100010000001100100001000", 
 "01001110110111101011010000111111101011000110010111", 
 "01001010000111111001100000100010101100100101010100", 
 "11111101001101110011011011011000111001101100011011", 
 "10000100110111000001110110010000000000111100101101", 
 "01010011101101101110000011000110011111001111011100", 
 "01101010011111010000011001111101011010011100001101", 
 "11011000011000110010101111100000101011011111101100", 
 "11100001001000110010100011001010101101001010001100", 
 "11011011001100111101001100111100000101011101101011", 
 "11110111100100101011100101111101000111001111110111", 
 "00011001100110111100111100001100101001111100001111", 
 "10001111100101110111001111100000000011110000100111", 
 "10101010110110100110010001001010000111100110100011", 
 "01100110100000001110101001101011001010001101110101", 
 "10110101110100110110101001100111110000101111100110", 
 "01011000001001101110100001101001110011001001110001", 
 "00100101010001100110110101001010010100001011000011", 
 "00011101100100001010100000000011000010100110011100", 
 "11001001011000000101111111000000110010001101101110", 
 "10101010110110010000010011001100110101110100111011", 
 "01101001010111010001101000100011101001110101000110", 
 "00110101101110110001110101110010100100110000101101", 
 "11010101000111010011110011000001101111010011110011", 
 "10010000010001110011011101001110110010001100011100", 
 "00111101110001001100101001110100110010100110110000", 
 "00010011011000101000100001101110111100100000010100", 
 "01101110001101000001001000001011101010011101011110", 
 "00000100110011001011101011110011011101100001110111", 
 "00110011110000011001011100001110101010100110010110", 
 "00111001010011011111010100000100100000101101110001", 
 "10101101101110111110000011111011001011100011110001", 
 "00101110010101111000001010110100001110111011100011", 
 "01111110010100111010110001111000111101110100111011"}
Returns: 12

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TheMatrix{
public:
	int MaxArea(vector <string> board){
		int m = board.size();
		if(m==0) return 0;
		int n = board[0].size();
		if(n==0) return 0;
		vector<vector<int> > mark(m+1,vector<int>(n+1,0));
		for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			if(j==0||board[i][j]!=board[i][j-1]) 
				mark[i][j+1] = mark[i][j]+1;
			else mark[i][j+1] = 1;
		int res = 0;
		for(int j=1;j<=n;++j){
			stack<int> ms;
			int start=0;
			for(int i=0;i<=m;){
				if(ms.empty()||
					(mark[ms.top()][j]<=mark[i][j]&&i!=m&&board[i][j-1]!=board[i-1][j-1])){
					if(ms.empty()&&i!=0&&i!=m&&board[i][j-1]==board[i-1][j-1]) start = i;
					ms.push(i++);
				}else{
					int t = ms.top();
					ms.pop();
					int v = ms.empty()?0:ms.top()+1;
					v = max(v,start);
					res = max(res,(i-v)*mark[t][j]);
				}
			}
		}
		return res;
	}
};
