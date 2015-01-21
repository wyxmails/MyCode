/*

Problem Statement
    
We have chosen a finite set of points in the plane. You are given their coordinates in the vector <int>s x and y: for each valid i, there is a point with coordinates (x[i],y[i]). We are interested in triangles with the following properties:
Each vertex of the triangle is one of our chosen points.
The point (0,0) lies inside the triangle.
Return the number of such triangles. Note that the constraints guarantee that there are no degenerate triangles and that the point (0,0) never lies on the boundary of a triangle.
Definition
    
Class:
TrianglesContainOrigin
Method:
count
Parameters:
vector <int>, vector <int>
Returns:
long long
Method signature:
long long count(vector <int> x, vector <int> y)
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
x and y will contain between 3 and 2500 elements, inclusive.
-
x and y will contain the same number of elements.
-
Each element of x and y will be between -10,000 and 10,000, inclusive.
-
No two points will be the same.
-
No three points will be collinear.
-
No point will be on the origin.
-
There will be no two points P and Q such that P, Q, and the origin are collinear.
Examples
0)

    
{-1,-1,1}
{1,-1,0}
Returns: 1
There is exactly one possible triangle. It does contain the origin.
1)

    
{-1,-1,1,2}
{1,-1,2,-1}
Returns: 2
There are four possible triangles. Two of them contain the origin. One is the triangle with vertices in (-1,1), (-1,-1), and (2,-1). The other is the triangle with vertices in (-1,-1), (1,2), and (2,-1).
2)

    
{-1,-2,3,3,2,1}
{-2,-1,1,2,3,3}
Returns: 8

3)

    
{1,5,10,5,-5,7,-9,-6,-3,0,8,8,1,-4,7,-3,10,9,-6}
{5,-6,-3,4,-2,-8,-7,2,7,4,2,0,-4,-8,7,5,-5,-2,-9}
Returns: 256

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TrianglesContainOrigin{
public:
	long long count(vector <int> x, vector <int> y){
		double pi = atan(1.0)*4;
		long long n = x.size();
		vector<double> mark(2*n);
		for(long long i=0;i<n;++i){
			mark[2*i] = atan2(y[i],x[i]);
			mark[2*i+1] = atan2(y[i],x[i])+ pi*2;
		}
		sort(mark.begin(),mark.end());
		long long res = n*(n-1)*(n-2)/6;
		long long cur=0;
		for(int i=0;i<n;++i){
			while(cur+1<2*n&&mark[cur+1]<mark[i]+pi-1e-9) cur++;
			long long len = cur-i;
			if(len>0) res -= len*(len-1)/2;
		}
		return res;
	}
};
