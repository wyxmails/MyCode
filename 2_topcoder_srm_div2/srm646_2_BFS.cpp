/*

Problem Statement
    
John is standing at the origin of an infinite two-dimensional grid. He is going to move along this grid. During each second he can either stay where he is or he can move by one unit in one of the four cardinal directions (north, south, east, or west). Some of the grid points are blocked. John is not allowed to move to a blocked grid point.  You are given the coordinates of the blocked grid points as vector <int>s x and y. For each valid i, the grid point that is x[i] units east and y[i] units north of the origin is blocked. You are also given an int k. Compute and return the maximal possible x-coordinate of a point John can reach in k seconds.
Definition
    
Class:
TheGridDivTwo
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
Each element of x will be between -1,000 and 1,000, inclusive.
-
Each element of y will be between -1,000 and 1,000, inclusive.
-
All pairs (x[i], y[i]) will be distinct.
-
Each pair (x[i], y[i]) will be different from (0, 0).
-
k will be between 1 and 1,000, inclusive.
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
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[2005][2005];
struct Q{
	int x,y,k;
	Q(int x,int y,int k):x(x),y(y),k(k){}
	friend bool operator < (const Q&a,const Q&b){
		if(a.k!=b.k) return a.k>b.k;
		if(a.x!=b.x) return a.x<b.x;
		return false;
	}
};

class TheGridDivTwo{
public:
	int find(vector <int> x, vector <int> y, int k){
		memset(visited,false,sizeof(visited));
		int n = x.size();
		for(int i=0;i<n;++i)
			visited[y[i]+1000][x[i]+1000] = true;
		priority_queue<Q> mq;
		Q nn(1000,1000,0);
		mq.push(nn);
		int res = 0;
		while(!mq.empty()){
			Q cur = mq.top();
			mq.pop();
			if(visited[cur.y][cur.x]) continue;
			visited[cur.y][cur.x] = true;
			res = max(res,cur.x-1000);
			if(cur.k==k) return res;
			
			int xx=cur.x+1,yy=cur.y;
			Q next1(xx,yy,cur.k+1);
			mq.push(next1);
			
			xx=cur.x-1,yy=cur.y;
			Q next2(xx,yy,cur.k+1);
			mq.push(next2);
			
			xx=cur.x,yy=cur.y+1;
			Q next3(xx,yy,cur.k+1);
			mq.push(next3);
			
			xx=cur.x,yy=cur.y-1;
			Q next4(xx,yy,cur.k+1);
			mq.push(next4);
		}
		return res;
	}
};
