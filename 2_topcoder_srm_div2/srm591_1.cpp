/*

Problem Statement
    
A triple (x, y, z) is called an arithmetic progression if the equality y - x = z - y holds.  You are given three ints a, b and c. Your goal is to change the triple (a, b, c) into an arithmetic progression. You are only allowed to change one of the three numbers. The change must proceed as follows: First, you choose a non-negative real (not necessarily integer) number r. Then, you either add r to one of the three given numbers, or you subtract r from one of them. Return the minimum value of r which allows you to create an arithmetic progression.
Definition
    
Class:
TheArithmeticProgression
Method:
minimumChange
Parameters:
int, int, int
Returns:
double
Method signature:
double minimumChange(int a, int b, int c)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
a will be between 0 and 1000, inclusive.
-
b will be between 0 and 1000, inclusive.
-
c will be between 0 and 1000, inclusive.
Examples
0)

    
0
1
2
Returns: 0.0
The triple (0, 1, 2) is an arithmetic progression. Thus, you can choose r = 0.0 and add or subtract it from any of the given numbers without changing the triple.
1)

    
0
2
1
Returns: 1.5
Note that while (0, 1, 2) is an arithmetic progression, you cannot rearrange the numbers within the triple. You can choose r = 1.5 and subtract it from b, obtaining the triple (0, 0.5, 1).
2)

    
3
2
1
Returns: 0.0

3)

    
4
4
8
Returns: 2.0

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class TheArithmeticProgression{
public:
	double minimumChange(int a, int b, int c){
		double des1,des2,des3;
		double res = 0.0;
		des1 = b-(c-b);
		des2 = (double)a+double(c-a)/2.0;
		des3 = b+(b-a);
		res = fabs(des1-a);
		res = min(res,fabs(des2-b));
		res = min(res,fabs(des3-c));
		return res;
	}
};
