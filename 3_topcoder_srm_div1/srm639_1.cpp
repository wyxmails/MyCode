/*

Problem Statement
    
Alice and Kirito just played a game. The game consisted of a finite (possibly empty) sequence of turns. You do not know the exact number of turns. The turns were numbered starting from 1. In each turn, exactly one of our two players won. The winner of turn i scored 2*i-1 points.
You are given two long longs x and y. Find out whether it is possible that at the end of the game Alice had exactly x points and Kirito had exactly y points. If it is possible, return the smallest number of turns Alice could have won. If the given final result is not possible, return -1 instead.
Definition
    
Class:
AliceGame
Method:
findMinimumValue
Parameters:
long long, long long
Returns:
long long
Method signature:
long long findMinimumValue(long long x, long long y)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
x and y are between 0 and 1,000,000,000,000, inclusive.
Examples
0)

    
8
17
Returns: 2
This final result is possible. Alice must have won at least two turns. One possibility is that Alice won turns 2 and 3 (for 3+5 = 8 points) and Kirito won turns 1, 4, and 5 (for 1+7+9 = 17 points).
1)

    
17
8
Returns: 3

2)

    
0
0
Returns: 0

3)

    
9
9
Returns: -1

4)

    
500000
500000
Returns: 294

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
//if root*root==x+y, then only 2 is ilegal, 
//because, if x or y is an odd number, it is legal,
// if x or y is an even number, it can be represented by 1 and an odd number, except 2.
class AliceGame{
public:
	long long findMinimumValue(long long x, long long y){
		if(x==2||y==2) return -1;
		long long root = sqrt(x+y);
		if(root*root!=x+y) return -1;
		long long res=0;
		for(long long p=root;p>=1;--p){
			if(x-(2*p-1)==2) continue;
			if(x>=2*p-1){
				x -= 2*p-1;
				res++;
			}
			if(x==0) break;
		}
		return res;
	}
};
