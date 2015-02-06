/*

Problem Statement
    
You have been hired to do some refactoring. You are not really sure what that is, but you think it has something to do with factoring a number multiple times.  Recall that a factorization of a positive integer n is a collection of at least two positive integers, each larger than one, whose product is n. Note that the order of the numbers in a factorization is ignored, so 2*12 and 12*2 represent the same factorization of 24. In fact, 24 has precisely 6 valid factorizations: 2*2*2*3, 2*2*6, 2*3*4, 2*12, 3*8, and 4*6.  To prepare for your job, write a program that, given an int n, returns the number of unique factorizations of n.
Definition
    
Class:
Refactoring
Method:
refactor
Parameters:
int
Returns:
int
Method signature:
int refactor(int n)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
n will be between 2 and 2,000,000,000 inclusive.
Examples
0)

    
24
Returns: 6
This is the example from the problem statement.
1)

    
9973
Returns: 0
9973 is a prime number, so there are no valid factorizations of 9973.
2)

    
9240
Returns: 295

3)

    
1916006400
Returns: 7389115
The number of factorizations will never be larger than this.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class Refactoring{
public:
	int refactor(int n){
		return f(n,2)-1;
	}
	int f(int n,int p){
		int res = 1;
		for(int i=p;i*i<=n;++i){
			if(n%i==0){
				res += f(n/i,i);
			}
		}
		return res;
	}
};
