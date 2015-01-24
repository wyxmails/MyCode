
/*
Problem Statement
    
The citizens of Byteland want to build N new buildings. The new buildings will all stand in a line and they will be labeled 1 through N, in order. The city regulations impose some restrictions on the heights of the new buildings. You are given the parameters used in these restrictions: an int K and two vector <int>s x and t. The restrictions are described below.
The height of each building must be a nonnegative integer.
The height of building 1 must be 0.
The absolute value of the difference between any two adjacent buildings must be at most K.
For each valid i, the height of building x[i] must be t[i] or less.
Given these restrictions, the citizens of Byteland want to build a building that will be as tall as possible. Return the largest possible height some of the N buildings may have.
Definition
    
Class:
BuildingTowers
Method:
maxHeight
Parameters:
int, int, vector <int>, vector <int>
Returns:
long long
Method signature:
long long maxHeight(int N, int K, vector <int> x, vector <int> t)
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
N will be between 1 and 1,000,000,000, inclusive.
-
K will be between 1 and 1,000,000,000, inclusive.
-
x will contain between 0 and min(N,500) elements, inclusive.
-
t will have exactly the same number of elements as x
-
Each element of x will be between 1 and N, inclusive.
-
x[i] < x[i+1] for all valid i.
-
Each element of t will be between 1 and 1,000,000,000, inclusive.
Examples
0)

    
10
1
{3,8}
{1,1}
Returns: 3
In this case we are going to build 10 buildings. The difference in height between adjacent buildings is at most 1. We also have two additional constraints: the height of building 3 can be at most 1, and the height of building 8 can also be at most 1. The tallest possible new building in this city can have height 3. One optimal skyline looks as follows: {0,1,1,2,3,3,2,1,1,0}.
1)

    
1000000000
1000000000
{}
{}
Returns: 999999999000000000
There are no additional constraints so, for each valid i, the height of building i can be (i-1)*1000000000.
2)

    
20
3
{4,7,13,15,18}
{8,22,1,55,42}
Returns: 22

3)

    
780
547990606
{34,35,48,86,110,170,275,288,313,321,344,373,390,410,412,441,499,525,538,568,585,627,630,671,692,699,719,752,755,764,772}
{89,81,88,42,55,92,19,91,71,42,72,18,86,89,88,75,29,98,63,74,45,11,68,34,94,20,69,33,50,69,54}
Returns: 28495511604

4)

    
7824078
2374
{134668,488112,558756,590300,787884,868112,1550116,1681439,1790994,
1796091,1906637,2005485,2152813,2171716,2255697,2332732,2516853,
2749024,2922558,2930163,3568190,3882735,4264888,5080550,5167938,
5249191,5574341,5866912,5936121,6142348,6164177,6176113,6434368,
6552905,6588059,6628843,6744163,6760794,6982172,7080464,7175493,
7249044}
{8,9,171315129,52304509,1090062,476157338,245,6,253638067,37,500,
29060,106246500,129,22402,939993108,7375,2365707,40098,10200444,
3193547,55597,24920935,905027,1374,12396141,525886,41,33,3692,
11502,180,3186,5560,778988,42449532,269666,10982579,48,3994,1,9}
Returns: 1365130725

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BuildingTowers{
public:
	long long maxHeight(int N, int K, vector <int> x, vector <int> t){
		int n = x.size();
		n = t.size();
		if(n==0) return (long long)(N-1)*(long long)K;
		long long res=0;
		for(int i=0;i<n;++i){
			if(i==0) t[i] = min((long long)t[0],(long long)K*(long long)(x[0]-1));
			else t[i] = min((long long)t[i],(long long)(x[i]-x[i-1])*(long long)K+t[i-1]);
			if(i+1<n)
				t[i] = min((long long)t[i],(long long)(x[i+1]-x[i])*(long long)K+t[i+1]);
		}

		res = max(res,(long long)(t[n-1]+(long long)K*(long long)(N-x[n-1])));

		for(int i=0;i<n;++i){
			long long tmp,t1,t2;
			int step;
			if(i==0){
				t1 = 0;t2=t[i];step=x[i]-1;
			}else{
				t1 = min(t[i],t[i-1]);
				t2 = max(t[i],t[i-1]);
				step = x[i]-x[i-1];
			}
			while(step>0){
				if(t1<=t2) t1 += K;
				else t2 += K;
				step--;
			}
			tmp = min(t1,t2);
			res = max(res,tmp);
		}
		return res;
	}
};
