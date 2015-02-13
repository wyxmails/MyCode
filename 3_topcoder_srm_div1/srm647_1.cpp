/*

Problem Statement
    
The citizens of Byteland want to build N new buildings. The new buildings will all stand in a line and they will be labeled 1 through N, in order. The city regulations impose some restrictions on the heights of the new buildings. You are given the parameters used in these restrictions: two vector <int>s x and t. The restrictions are described below.
The height of each building must be a nonnegative integer.
The height of building 1 must be 0.
The absolute value of the difference between any two adjacent buildings must be at most 1.
For each valid i, the height of building x[i] must be t[i] or less.
Given these restrictions, the citizens of Byteland want to build a building that will be as tall as possible. Return the largest possible height some of the N buildings may have.
Definition
    
Class:
BuildingTowersEasy
Method:
maxHeight
Parameters:
int, vector <int>, vector <int>
Returns:
int
Method signature:
int maxHeight(int N, vector <int> x, vector <int> t)
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
N will be between 1 and 100,000, inclusive.
-
x will contain between 0 and min(N,50) elements, inclusive.
-
t will have exactly the same number of elements as x.
-
Each element of x will be between 1 and N, inclusive.
-
x[i] < x[i+1] for all valid i.
-
Each element of t will be between 0 and 100,000, inclusive.
Examples
0)

    
10
{3,8}
{1,1}
Returns: 3
In this case we are going to build 10 buildings. We have two constraints: the height of building 3 can be at most 1, and the height of building 8 can also be at most 1. The tallest possible new building in this city can have height 3. One optimal skyline looks as follows: {0,1,1,2,3,3,2,1,1,0}.
1)

    
100000
{}
{}
Returns: 99999
There are no additional constraints so, for each valid i, the height of building i can be (i-1).
2)

    
2718
{1,30,400,1300,2500}
{100000,100000,100000,100000,100000}
Returns: 2717

3)

    
20
{4,7,13,15,18}
{3,8,1,17,16}
Returns: 8

4)

    
447
{32,35,55,60,61,88,91,97,128,151,181,186,192,196,198,237,259,268,291,314,341,367,389,390,391,428,435}
{81,221,172,641,25,953,330,141,123,440,692,394,200,649,78,726,50,810,501,4,216,407,2,172,0,29,14}
Returns: 120

5)

    
97638
{8,1749,4550,5388,6752,7089,9737,14891,16671,16821,17691,19753,24589,
25348,30114,32213,34376,36467,37699,41490,44784,44893,57316,58275,58567,
61122,61489,63195,64776,65905,68788,69908,72853,78152,78784,82779,84488,
86277,88611,92793,93214,97583}
{16610,6,497,14,42892,31,79,1203,518,31147,597,7846,1396,8309,12,14,1148,
433,23693,13,1939,244,19,46,27,611,412,10,27023,19141,34,15667,588,10,229,
83,390,14,38441,16021,4,39386}
Returns: 6343

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class BuildingTowersEasy{
public:
	int maxHeight(int N, vector <int> x, vector <int> t){
		vector<int> build(N,INT_MAX);
		if(x.size()>0) build[x[0]-1] = t[0];
		build[0] = 0;
		for(int i=1;i<x.size();++i)
			build[x[i]-1] = t[i];
		for(int i=1;i<N;++i)
			build[i] = min(build[i],build[i-1]+1);
		for(int i=N-2;i>=0;--i)
			build[i] = min(build[i],build[i+1]+1);
		int res = 0;
		for(int i=0;i<N;++i)
			res = max(res,build[i]);
		return res;
	}
};
