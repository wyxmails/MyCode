/*

Problem Statement
    
John is standing at the origin of an infinite two-dimensional grid. He is going to move along this grid. During each second he can either stay where he is or he can move by one unit in one of the four cardinal directions (north, south, east, or west). Some of the grid points are blocked. John is not allowed to move to a blocked grid point.  You are given the coordinates of the blocked grid points as vector <int>s x and y. For each valid i, the grid point that is x[i] units east and y[i] units north of the origin is blocked. You are also given an int k. Compute and return the maximal possible x-coordinate of a point John can reach in k seconds.
Definition
    
Class:
TheGridDivOne
Method:
find
Parameters:
vector <int>, vector <int>, int
Returns:
int
Method signature:
int find(vector <int> x, vector <int> y, int k)
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
x will contain between 0 and 47 elements, inclusive.
-
x and y will contain the same number of elements.
-
Each element of x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-
Each element of y will be between -1,000,000,000 and 1,000,000,000, inclusive.
-
All pairs (x[i], y[i]) will be distinct.
-
Each pair (x[i], y[i]) will be different from (0, 0).
-
k will be between 1 and 1,000,000,000, inclusive.
Examples
0)

    
{1,1,1,1}
{-2,-1,0,1}
4
Returns: 2
The optimal strategy is to move two times north to (0, 2) and then two times east to (2,2).
1)

    
{-1, 0, 0, 1}
{0, -1, 1, 0}
9
Returns: 0
John can not make any moves.
2)

    
{}
{}
1000
Returns: 1000

3)

    
{1,0,0,-1,-1,-2,-2,-3,-3,-4,-4}
{0,-1,1,-2,2,-3,3,-4,4,-5,5}
47
Returns: 31

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

long long n,px[400],py[400];
long long dist[400][400];
int rim[][2] = {1,0,1,-1,0,-1,-1,-1,-1,0,-1,1,0,1,1,1};

void add(long long x,long long y){
	px[n] = x;
	py[n] = y;
	n++;
}

class TheGridDivOne{
public:
	int find(vector <int> x, vector <int> y, int steps){
		n=0;
		add(0,0);
		int m = x.size();
		for(int i=0;i<m;++i){
			for(int j=0;j<8;++j){
				long long xx=x[i]+rim[j][0],yy=y[i]+rim[j][1];
				add(xx,yy);
			}
		}
		for(long long i=0;i<n;++i)
			for(long long j=0;j<n;++j){
				if(i==j) dist[i][j] = 0;
				else{
					long long left = min(px[i],px[j]);
					long long right = max(px[i],px[j]);
					long long top = min(py[i],py[j]);
					long long bot = max(py[i],py[j]);
					bool block=false;
					for(int k=0;k<m;++k)
						if(x[k]>=left&&x[k]<=right&&y[k]>=top&&y[k]<=bot){
							block = true;break;
						}
					if(block) dist[i][j] = 1000000001;
					else dist[i][j] = right-left+bot-top;
				}
			}
		for(long long i=0;i<n;++i)
			for(long long j=0;j<n;++j)
				for(long long k=0;k<n;++k){	
					dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
				}
		long long res = 0;
		for(long long i=0;i<n;++i){
			if(dist[0][i]>steps) continue;
			long long more = steps-dist[0][i];
			for(int j=0;j<m;++j)
				if(x[j]>px[i]&&py[i]==y[j])
					more = min(more,x[j]-px[i]-1);
			res = max(res,px[i]+more);
			//cout << px[i] << " " << py[i] << " " << res << endl;
		}	
		return res;
	}
};
