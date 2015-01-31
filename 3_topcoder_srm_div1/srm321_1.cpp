/*

Problem Statement
    
You have a rectangular chocolate bar that consists of width x height square tiles. You can split it into two rectangular pieces by creating a single vertical or horizontal break along tile edges. For example, a 2 x 2 chocolate bar can be divided into two 2 x 1 pieces, but it cannot be divided into two pieces, where one of them is 1 x 1. You can repeat the split operation as many times as you want, each time splitting a single rectangular piece into two rectangular pieces. Your goal is to create a piece consisting of exactly nTiles tiles. Return the minimal number of split operations necessary to reach this goal. If it is impossible, return -1.
Definition
    
Class:
Chocolate
Method:
minSplitNumber
Parameters:
int, int, int
Returns:
int
Method signature:
int minSplitNumber(int width, int height, int nTiles)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
width will be between 1 and 10^9, inclusive.
-
height will be between 1 and 10^9, inclusive.
-
nTiles will be between 1 and 10^9, inclusive.
Examples
0)

    
5
4
12
Returns: 1
You can split the chocolate bar into two rectangular pieces 3 x 4 and 2 x 4 by creating a single vertical break. Only one break is necessary.
1)

    
12
10
120
Returns: 0
The chocolate bar consists of exactly 120 tiles.
2)

    
2
2
1
Returns: 2

3)

    
17
19
111
Returns: -1

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Chocolate{
public:
	int minSplitNumber(int width, int height, int nTiles){
		long long w = width,h=height;
		if(w*h==nTiles) return 0;
		if(w*h<nTiles) return -1;
		if(nTiles%w==0||nTiles%h==0) return 1;
		if(w>nTiles||h>nTiles) return 2;
		vector<int> fac = findFac(nTiles);
		for(int i=0;i<fac.size();i+=2){
			if(max(fac[i],fac[i+1])<=max(w,h)&&
				min(fac[i],fac[i+1])<=min(w,h)) return 2;
		}
		return -1;
	}
	vector<int> findFac(int n){
		vector<int> res;
		int end = n;
		for(int i=2;i<end;i++){
			if(n%i==0){
				res.push_back(i);
				res.push_back(n/i);
			}
			end = n/i;
		}
		return res;
	}
};
