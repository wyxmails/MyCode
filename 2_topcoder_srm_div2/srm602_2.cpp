/*

Problem Statement
    
Snake Snuke has N rectangles cut out of paper. The rectangles are labeled 0 through N-1. You are given vector <int>s X and Y with N elements each. For each i, the sides of rectangle i have lengths X[i] and Y[i].  Snake Snuke will choose some of his rectangles and place them onto a table, one rectangle at a time, in any order he likes. Each rectangle (except for the first one) must overlap the immediately previous one, so at the end Snuke will have a pile of rectangles. Snuke may rotate the rectangles, but once placed, the sides of each rectangle must be parallel to the sides of the table. (I.e., he may only swap the width and height of some rectangles he places.) After placing all the rectangles, Snuke computes the area that is covered by all N rectangles. (Formally, the area of their intersection.)  You are also given an int limit. The area computed by Snuke must be greater than or equal to limit.  Return the largest positive R such that Snuke can select some R of his rectangles and place them in such a way that the area of their intersection is at least limit. If there is no such R, return -1 instead.
Definition
    
Class:
PilingRectsDiv2
Method:
getmax
Parameters:
vector <int>, vector <int>, int
Returns:
int
Method signature:
int getmax(vector <int> X, vector <int> Y, int limit)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
X and Y will contain between 1 and 50 elements, inclusive.
-
X and Y will contain the same number of elements.
-
Each element of X and Y will be between 1 and 200, inclusive.
-
limit will be between 1 and 40000, inclusive.
Examples
0)

    
{1,2,3,1}
{3,2,4,4}
3
Returns: 3
He can choose rectangles 0, 2, and 3. These three rectangles can then be placed in such a way that both rectangle 2 and rectangle 3 cover rectangle 0 completely. For this placement, the area of their intersection will be exactly 3.
1)

    
{4,7}
{7,4}
25
Returns: 2
Note that he can rotate rectangles.
2)

    
{10}
{10}
9999
Returns: -1
There is no possible choice.
3)

    
{10}
{3}
30
Returns: 1

4)

    
{3,6,5,8,2,9,14}
{14,6,13,8,15,6,3}
27
Returns: 4

5)

    
{121,168,86,106,36,10,125,97,53,26,148,129,41,18,173,55,13,73,91,174,177,190,28,164,122,92,5,26,58,188,14,67,48,196,41,94,24,89,54,117,12,6,155,103,200,128,184,29,92,149}
{199,182,43,191,2,145,15,53,38,37,61,45,157,129,119,123,177,178,183,188,132,108,112,137,92,59,75,196,102,152,114,121,181,93,32,3,24,116,4,163,96,159,196,43,59,150,79,113,20,146}
5345
Returns: 24

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;
bool exists[201];
class PilingRectsDiv2{
public:
	int getmax(vector <int> X, vector <int> Y, int limit){
		int n = X.size();
		for(int i=0;i<n;++i)
			exists[X[i]] = exists[Y[i]] = true;
		int res = -1;
		for(int w=1;w<=200;++w){
			if(!exists[w]) continue;
			for(int h=1;h<=200;++h){
				if(!exists[h]||w*h<limit) continue;
				int cnt = 0;
				for(int i=0;i<n;++i){
					if((X[i]>=w&&Y[i]>=h)||(X[i]>=h&&Y[i]>=w)) cnt++;
				}
				if(cnt>0) res = max(res,cnt);
			}
		}
		return res;
	}
};
