/*

Problem Statement
    
Alice and Kirito just played a game. The game consisted of a finite (possibly empty) sequence of turns. You do not know the exact number of turns. The turns were numbered starting from 1. In each turn, exactly one of our two players won. The winner of turn i scored i points.
You are given two long longs x and y. Find out whether it is possible that at the end of the game Alice had exactly x points and Kirito had exactly y points. If it is possible, return the smallest number of turns Alice could have won. If the given final result is not possible, return -1 instead.
Definition
    
Class:
AliceGameEasy
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
x and y will be between 0 and 1,000,000,000,000(10^12), inclusive.
Examples
0)

    
7
14
Returns: 2
This final result is possible. One possibility is that Alice won turns 1, 2, and 4 (for 1+2+4 = 7 points) and Kirito won turns 3, 5, and 6 (for 3+5+6 = 14 points). However, there are also some other possibilities in which Alice only won two of the six turns, so the correct answer is 2.
1)

    
10
0
Returns: 4
There must have been four turns and Alice must have won all four of them.
2)

    
932599670050
67400241741
Returns: 1047062
Watch out for integer overflow.
3)

    
7
13
Returns: -1

4)

    
0
0
Returns: 0

5)

    
100000
400500
Returns: 106

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class AliceGameEasy{
public:
	long long findMinimumValue(long long x, long long y){
		long long sum = x+y;
		sum *= 2;
		long long sq = sqrt(sum);
		sq--;
		bool pos = false;
		for(int i=0;i<3;++i){
			if(sq*(sq+1)==sum){ pos = true; break;}
			sq++;
		}
		if(!pos) return -1;
		int res = 0;
		while(x>0&&sq>0){
			if(x>=sq){
				x -= sq;
				res++;
				sq--;
			}else{
				res++;
				x = 0;
				break;
			}
		}
		if(x==0) return res;
		return -1;
	}
};
