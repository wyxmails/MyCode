/*

Problem Statement
    
Andrew drew a bunch of points on a sheet of graph paper. You are given the coordinates of these points in two vector <int>s: X and Y. That is, for each valid i, there is a point at the coordinates (X[i], Y[i]).
 
Now Andrew wants to draw a rectangle. The sides of the rectangle must be parallel to the coordinate axes. (In other words, each side of the rectangle must be either horizontal or vertical.) Additionally, each of Andrew's points must be inside the rectangle or on its boundary.
 
Return the area of the smallest possible rectangle Andrew can draw.
Definition
    
Class:
BoundingBox
Method:
smallestArea
Parameters:
vector <int>, vector <int>
Returns:
int
Method signature:
int smallestArea(vector <int> X, vector <int> Y)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
X will have between 2 and 50 elements, inclusive.
-
X and Y will have the same number of elements.
-
Each element of X and Y will be between -100 and 100, inclusive.
-
The points described by X and Y will not be in a straight line horizontally or vertically. That is, the smallest rectangle will have a positive area.
Examples
0)

    
{0,1}
{1,0}
Returns: 1

1)

    
{0,-2,-1}
{-1,-1,-2}
Returns: 2
 
2)

    
{0,0,1,0,-1,2}
{0,1,2,-2,0,-1}
Returns: 12

3)

    
{9,-88,-40,98,-55,41,-38}
{-65,56,-67,7,-58,33,68}
Returns: 25110

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class BoundingBox{
public:
	int smallestArea(vector <int> X, vector <int> Y){
		int xmin,xmax,ymin,ymax;
		xmin=ymin=INT_MAX;
		xmax=ymax=INT_MIN;
		int n = X.size();
		for(int i=0;i<n;++i){
			if(X[i]<xmin) xmin = X[i];
			if(X[i]>xmax) xmax = X[i];
			if(Y[i]<ymin) ymin = Y[i];
			if(Y[i]>ymax) ymax = Y[i];
		}
		return (xmax-xmin)*(ymax-ymin);
	}
};
