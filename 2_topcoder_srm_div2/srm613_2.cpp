/*
Problem Statement
    
Cat Taro likes to play with his cat friends. Each of his friends currently sits on some coordinate on a straight line that goes from the left to the right. When Taro gives a signal, each of his friends must move exactly X units to the left or to the right.

You are given an vector <int> coordinates and the int X. For each i, the element coordinates[i] represents the coordinate of the i-th cat before the movement. Return the smallest possible difference between the positions of the leftmost cat and the rightmost cat after the movement.
Definition
    
Class:
TaroFriends
Method:
getNumber
Parameters:
vector <int>, int
Returns:
int
Method signature:
int getNumber(vector <int> coordinates, int X)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
coordinates will contain between 1 and 50 elements, inclusive.
-
Each element of coordinates will be between -100,000,000 and 100,000,000, inclusive.
-
X will be between 0 and 100,000,000, inclusive.
Examples
0)

    
{-3, 0, 1}
3
Returns: 3
The difference 3 is obtained if the cats move from {-3,0,1} to {0,-3,-2}.

 
1)

    
{4, 7, -7}
5
Returns: 4
The difference 4 is obtained if the cats move from {4,7,-7} to {-1,2,-2}.

 
2)

    
{-100000000, 100000000}
100000000
Returns: 0

3)

    
{3, 7, 4, 6, -10, 7, 10, 9, -5}
7
Returns: 7

4)

    
{-4, 0, 4, 0}
4
Returns: 4

5)

    
{7}
0
Returns: 0

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class TaroFriends{
public:
	int getNumber(vector <int> co, int X){
		int n = co.size();
		sort(co.begin(),co.end());
		int res = INT_MAX;
		for(int i=0;i<n;++i){
			int L = INT_MAX;
			int R = INT_MIN;
			for(int j=0;j<n;++j){
				int cur = co[j];
				cur += j<i?X:-X;
				if(cur<L) L = cur;
				if(cur>R) R = cur;
			}
			res = min(res,R-L);
		}
		return res;
	}
};
