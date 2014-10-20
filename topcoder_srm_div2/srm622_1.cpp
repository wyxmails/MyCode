/*
 Problem Statement
     
 The Fibonacci sequence is defined as follows:
 F[0] = 0
 F[1] = 1
 for each i >= 2: F[i] = F[i-1] + F[i-2]
 Thus, the Fibonacci sequence starts as follows: 0, 1, 1, 2, 3, 5, 8, 13, ... The elements of the Fibonacci sequence are called Fibonacci numbers.  You're given an int N. You want to change N into a Fibonacci number. This change will consist of zero or more steps. In each step, you can either increment or decrement the number you currently have. That is, in each step you can change your current number X either to X+1 or to X-1.  Return the smallest number of steps needed to change N into a Fibonacci number.
 Definition
     
Class:
FibonacciDiv2
Method:
find
Parameters:
int
Returns:
int
Method signature:
int find(int N)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
N will be between 1 and 1,000,000, inclusive.
Examples
0)

    
1
Returns: 0
The number 1 is already a Fibonacci number. No changes are necessary.
1)

    
13
Returns: 0
The number 13 is also a Fibonacci number.
2)

    
15
Returns: 2
The best way to change 15 into a Fibonacci number is to decrement it twice in a row (15 -> 14 -> 13).
3)

    
19
Returns: 2
You can increase it by 2 to get 21.
4)

    
1000000
Returns: 167960
This is the biggest possible number that you can get as input.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
using namespace std;

class FibonacciDiv2{
public:
int find(int N);
};

int FibonacciDiv2::find(int N){
	int a=0,b=1;
	while(b<N){
		int tmp = b;
		b = a+b;
		a = tmp;
	}
	if(b==N) return 0;
	int sub1 = b-N;
	int sub2 = N-a;
	return min(sub1,sub2);
}
