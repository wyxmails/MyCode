/*

Problem Statement
    
Fox Ciel has a robot. The robot is located on an infinite plane. At the beginning, the robot starts at the coordinates (0, 0). The robot can then make several steps. The steps are numbered starting from 0.  In each step, Ciel must choose one of two directions for the robot: right (x coordinate increases) or up (y coordinate increases). In step k, the robot will move 3^k units in the chosen direction. It is not allowed to skip a step.  You are given ints x and y. Return "Possible" (quotes for clarity) if it is possible that the robot reaches the point (x,y) after some (possibly zero) steps. Otherwise, return "Impossible".
Definition
    
Class:
PowerOfThreeEasy
Method:
ableToGet
Parameters:
int, int
Returns:
string
Method signature:
string ableToGet(int x, int y)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
x will be between 0 and 1,000,000,000, inclusive.
-
y will be between 0 and 1,000,000,000, inclusive.
Examples
0)

    
1
3
Returns: "Possible"
In step 0 Ciel will send the robot right to (1,0). In step 1 she will send it up to (1,3).
1)

    
1
1
Returns: "Impossible"

2)

    
3
0
Returns: "Impossible"

3)

    
1
9
Returns: "Impossible"
Note that it is not allowed to move the robot right in step 0, skip step 1, and then move the robot up in step 2.
4)

    
3
10
Returns: "Possible"

5)

    
1093
2187
Returns: "Possible"

6)

    
0
0
Returns: "Possible"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class PowerOfThreeEasy{
public:
	string ableToGet(int x, int y){
		while(x!=0||y!=0){
			if(x%3==1&&y%3==0) x--;
			else if(x%3==0&&y%3==1) y--;
			else return "Impossible";
			x/=3;
			y/=3;
		}
		return "Possible";
	}
};
