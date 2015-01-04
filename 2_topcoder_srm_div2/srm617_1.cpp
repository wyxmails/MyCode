/*
Problem Statement
    
In this problem, some test cases have more than one correct output. We are using a special checker to verify that the output of your program is correct.  A positive integer x is called composite if there are positive integers y > 1 and z > 1 such that x = yz. In other words, a composite positive integer has a positive integer divisor other than 1 and itself. For example, 48 is composite because 48 = 4*12. The smallest few composite integers are 4, 6, 8, 9, and 10.  You are given an int n. Return a vector <int> with two elements. Both elements of the returned vector <int> must be positive composite integers, and their sum must be n.  For the given constraints on n at least one such pair always exists. Note that if there are many such pairs, your solution can return any one of them.
Definition
    
Class:
SilverbachConjecture
Method:
solve
Parameters:
int
Returns:
vector <int>
Method signature:
vector <int> solve(int n)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
n will be between 20 and 2000, inclusive.
Examples
0)

    
20
Returns: {8, 12 }
For n=20 there are seven correct answers: {4,16}, {6,14}, {8,12}, {10,10}, {12,8}, {14,6}, and {16,4}. Your program must return one of these seven answers.
1)

    
30
Returns: {15, 15 }
You may return two identical numbers.
2)

    
999
Returns: {699, 300 }

3)

    
45
Returns: {15, 30 }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class SilverbachConjecture{
public:
	vector <int> solve(int n){
		vector<int> res;
		if(n<8) return res;
		if(n%4==0){
			int v1 = n/2;
			res.push_back(v1);
			res.push_back(v1);
		}else{
			for(int i=4;i<n;i+=2){
				if(checkCom(n-i)){
					res.push_back(i);
					res.push_back(n-i);
					break;
				}
			}
		}
		return res;
	}
	bool checkCom(int n){
		if(n<=2) return false;
		if(n%2==0) return true;
		for(int i=3;i*i<=n;i+=2)
			if(n%i==0) return true;
		return false;
	}
};
