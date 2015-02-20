/*

Problem Statement
    
The dividing game is played as follows: You start by taking a clean sheet of paper and writing down some positive integer. Then you repeat the following process: Let X be the last integer you wrote. If X is odd, the game ends. Otherwise, divide X by 2 and write down the result.

For example, if you start the game by writing 12 you will then write 12/2 = 6, followed by 6/2 = 3, and as 3 is odd, the game ends there. Your paper now contains the numbers 12, 6, and 3.

Cat Taro has just played the game starting with the integer A. Jiro has also played the game but he started with the integer B. You are given the ints A and B. Return the number of integers that were written both by Taro and by Jiro.
Definition
    
Class:
TaroJiroDividing
Method:
getNumber
Parameters:
int, int
Returns:
int
Method signature:
int getNumber(int A, int B)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Constraints
-
A and B will be between 1 and 1,000,000,000, inclusive.
Examples
0)

    
8
4
Returns: 3
Taro will write the integers {8,4,2,1}. Jiro will write {4,2,1}. The three integers written by both of them are 4, 2, and 1.
1)

    
4
7
Returns: 0

2)

    
12
12
Returns: 3

3)

    
24
96
Returns: 4

4)

    
1000000000
999999999
Returns: 0

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <set>
using namespace std;

class TaroJiroDividing{
public:
	int getNumber(int A, int B){
		int res = 0;
		set<int> mark;
		mark.insert(A);
		while(A%2==0){
			A /= 2;
			mark.insert(A);
		}
		if(mark.find(B)!=mark.end()) res++;
		while(B%2==0){
			B /= 2;
			if(mark.find(B)!=mark.end()) res++;
		}
		return res;
	}
};
