/*
Problem Statement
    
There are N points in the plane. You are given their description as two vector <int>s, x and y, with N elements each. The N points have coordinates (x[0],y[0]), (x[1],y[1]), ..., (x[N-1],y[N-1]).
 
You want to draw a single square onto the plane. The vertices of the square must have integer coordinates, and the sides of the square must be parallel to the coordinate axes. Additionally, at least N-2 of the N given points must lie strictly inside the square (i.e., not on its boundary).
 
Return the smallest possible area of a square that satisfies these constraints.
Definition
    
Class:
MinimumSquareEasy
Method:
minArea
Parameters:
vector <int>, vector <int>
Returns:
long long
Method signature:
long long minArea(vector <int> x, vector <int> y)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
x will contain between 3 and 50 elements, inclusive.
-
y will contain the same number of elements as x.
-
All points will be pairwise distinct.
-
Each element of x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-
Each element of y will be between -1,000,000,000 and 1,000,000,000, inclusive.
Examples
0)

    
{0, 1, 2}
{0, 1, 5}
Returns: 4
The square must contain at least one of the three given points. One of the optimal solutions is the square with opposite corners at (-1,-1) and (1,1).
1)

    
{-1, -1, 0, 2, 0}
{-2, -1, 0, -1, -2}
Returns: 9
This time the square must contain at least three of the five given points. The optimal solution is the square with opposite corners at (-2,-3) and (1,0).
2)

    
{1000000000, -1000000000, 1000000000, -1000000000}
{1000000000, 1000000000, -1000000000, -1000000000}
Returns: 4000000008000000004
In this case one of the optimal solutions is a square that contains all four points.
3)

    
{93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21}
{64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7}
Returns: 22801

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinimumSquareEasy{
public:
	long long minArea(vector <int> x, vector <int> y){
		long long maxi = 1000000001;
		long long res = maxi*maxi*4;
		int n = x.size();
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				int xmin=maxi,xmax = -maxi;
				int ymin = maxi,ymax = -maxi;
				for(int k=0;k<n;++k){
					if(k!=i&&k!=j){
						xmin = min(xmin,x[k]);
						xmax = max(xmax,x[k]);
						ymin = min(ymin,y[k]);
						ymax = max(ymax,y[k]);
					}
				}
				long long side = max(xmax-xmin+2,ymax-ymin+2);
				if(res>side*side) res = side*side;
			}
		}
		return res;
	}
};
