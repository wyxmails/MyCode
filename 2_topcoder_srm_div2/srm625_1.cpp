/*
 Problem Statement
     
 You are given an int y. We are looking for any vector <int> x that satisfies the following constraints: 
 x has exactly three elements
 ( x[0] * x[1] ) + x[2] = y
 Each x[i] must be between -1000 and 1000, inclusive.
 No x[i] can be equal to 0 or 1.
 Find and return one such x.  If there are multiple valid solutions, you may return any of them. You may assume that for our constraints on y (specified below) at least one valid x always exists.
 Definition
     
Class:
AddMultiply
Method:
makeExpression
Parameters:
int
Returns:
vector <int>
Method signature:
vector <int> makeExpression(int y)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
y will be between 0 and 500, inclusive.
Examples
0)

    
6
Returns: {2, 2, 2 }
2*2 + 2 = 6  Note that this is one of many possible solutions. Another solution is:  3*3 + (-3) = 6
1)

    
11
Returns: {2, 3, 5 }

2)

    
0
Returns: {7, 10, -70 }
Note that 0 and 1 are not allowed, thus a result like 0 * 0 + 0 would be incorrect.
3)

    
500
Returns: {-400, -3, -700 }
Some or all of the returned numbers may be negative.
4)

    
2
Returns: {2, 2, -2 }

5)

    
5
Returns: {5, 2, -5 }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
using namespace std;
class AddMultiply{
public:
vector <int> makeExpression(int y);
};

vector<int> AddMultiply::makeExpression(int y){
	vector<int> res(3);
	if(y==0||y==1){
		res[0] = 2;
		res[1] = -2;
		res[2] = y-res[0]*res[1];
	}else if(abs(y)<=1000){
		res[0] = y;
		res[1] = 2;
		res[2] = -y;
		return res;
	}else{
		res[1] = max(2,y/1000);
		if(y%res[1]) res[0] = y/res[1];
		else res[0] = y/res[1]-1;
		res[2] = y-res[0]*res[1];
	}
	return res;
}
