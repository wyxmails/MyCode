/*
 Problem Statement
     
 There is a rectangular hole in the ground. You are given the dimensions of this rectangle: ints holeH and holeW.
 You have a rectangular board. You are given its dimensions: ints boardH and boardW. You would like to use the board to cover the hole.
 There are some rules you must follow when covering the hole:
 You may rotate the board, but you must place it so that the sides of the board are parallel to the sides of the hole.
 The board must cover the entire hole.
 All corners of the board must be strictly outside the hole. (That is, they are not allowed to lie on the boundary of the hole.)
 If you can cover the hole using the board you have, return 1. Otherwise, return -1.
 Definition
     
Class:
RectangleCoveringEasy
Method:
solve
Parameters:
int, int, int, int
Returns:
int
Method signature:
int solve(int holeH, int holeW, int boardH, int boardW)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
holeW, holeH, boardW, and boardH will be between 1 and 1,000,000,000, inclusive.
Examples
0)

    
1
1
1
1
Returns: -1
The vertices of the board must not be on the boundary of the hole.
1)

    
3
5
4
6
Returns: 1
One possibility is to place the board so that it extends over the hole by 0.5 on each side.
2)

    
10
20
25
15
Returns: 1
Here we have to rotate the board by 90 degrees.
3)

    
3
10
3
12
Returns: 1

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
using namespace std;

class RectangleCoveringEasy{
public:
	int solve(int holeH, int holeW, int boardH, int boardW);
};

int RectangleCoveringEasy::solve(int holeH, int holeW, int boardH, int boardW){
	if(holeH<holeW){
		int tmp = holeH;
		holeH =  holeW;
		holeW = tmp; 
	}
	if(boardH<boardW){
		int tmp = boardH;
		boardH = boardW;
		boardW = tmp;
	}
	if(boardH<holeH||boardW<holeW) return -1;
	if(boardH==holeH&&boardW==holeW) return -1;
	return 1;
}
