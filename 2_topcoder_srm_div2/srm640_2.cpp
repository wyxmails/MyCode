/*
Problem Statement
    
In this problem, you are going to play a simple number game. The rules of the game are as follows:
You have a single variable called x. Initially, x is set to 1.
In each step, you can change the value of x either to 2x or to 2x+1.
You are given a list of forbidden values. If at any moment your x is on the list, you lose the game.
You are also given a target value y. If at any moment your x is equal to y, you win the game. (Note that the previous item applies sooner: if y is forbidden, you lose the game when you reach it.)
If at any moment winning the game becomes impossible, you lose the game.
For example, assume that the forbidden values are 4 and 7, and the goal is 12. You can win the game as follows: change x from 1 to 2*1+1=3, then from 3 to 2*3=6, and then from 6 to 2*6=12.
You are given a vector<long long> table. The elements of table are the forbidden values.
You are also given a int k. Consider all possible goals y between 2 and (2^k)-1, inclusive. For how many of these goals is it possible to win the game? Compute and return the answer to that question.
Definition
    
Class:
NumberGameAgain
Method:
solve
Parameters:
int, vector<long long>
Returns:
long long
Method signature:
long long solve(int k, vector<long long> table)
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
k will be between 2 and 40, inclusive.
-
The number of elements in table will be between 0 and 20, inclusive.
-
all numbers in table will be between 2 and 2^k - 1, inclusive.
-
all numbers in table will be distinct.
Examples
0)

    
3
{2,4,6}
Returns: 2
There are three forbidden values: 2, 4, and 6. As k=3, we are considering y between 2 and (2^3)-1 = 7. This is how the game would end for each of these y's:
For y=2 we cannot win the game because 2 is forbidden.
For y=3 we can win the game: we change x from 1 to 3.
For y=4 we cannot win the game because 4 is forbidden.
For y=5 we cannot win the game. We would need to change x from 1 to 2 and then from 2 to 5, but we cannot do that because 2 is forbidden.
For y=6 we cannot win the game because 6 is forbidden.
For y=7 we can win the game: we change x from 1 to 3, and then from 3 to 7.
Thus, within the specified range there are two values of y for which we can win the game.
 
1)

    
5
{2,3}
Returns: 0
In this case, we will always reach a forbidden value after the very first step of the game. Therefore, there is no y for which we can win the game.
2)

    
5
{}
Returns: 30
With no forbidden values we can win this game for any y between 2 and 31, inclusive.
3)

    
40
{2,4,8,16,32141531,2324577,1099511627775,2222222222,33333333333,4444444444,2135}
Returns: 549755748288

4)

    
40
{}
Returns: 1099511627774

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class NumberGameAgain{
public:
	long long solve(int k, vector<long long> table){
		int n = table.size();
		if(n==0) return pow(2,k)-2;
		sort(table.begin(),table.end());
		long long res = pow(2,k)-2;
		for(int i=table.size()-1;i>=0;--i){
			long long cur = table[i];
			bool dup = false;
			while(cur>1){
				cur = cur/2;
				if(count(table.begin(),table.end(),cur)!=0){
					dup = true; break;
				}
			}
			if(!dup){
				res -= (pow(2,k)/pow(2,(int)log2(table[i]))-1);
			}
		}
		return res;
	}
};
