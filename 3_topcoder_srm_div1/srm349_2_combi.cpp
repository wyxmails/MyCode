/*

Problem Statement
    
You are attempting to create a new game that is played by rolling several dice. In order to determine scoring, you need to first know how many different formations can be rolled with those dice. We define a formation as the collection of values that are shown on the dice, without regard to order. Thus, {1, 1, 2}, {1, 2, 1}, and {2, 1, 1} are all the same formation, whereas {1, 1, 2}, {1, 2, 2} and {1, 1, 3} are all different formations. Note that even though two dice may have a different number of sides, for the purpose of counting formations, only the number shown on them matters.
You are given a vector <int> sides, where the i-th element is the number of sides on the i-th die. The sides of an n-sided die contain all numbers between 1 and n, inclusive. Return the number of different formations that can be made from those dice.
Definition
    
Class:
DiceGames
Method:
countFormations
Parameters:
vector <int>
Returns:
long long
Method signature:
long long countFormations(vector <int> sides)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
sides will contain between 1 and 32 elements, inclusive.
-
Each element of sides will be between 1 and 32, inclusive.
Examples
0)

    
{4}
Returns: 4
A single die with four sides can have four formations.
1)

    
{2, 2}
Returns: 3
This is essentially the equivalent of flipping two coins. We can get Heads/Heads, Heads/Tails, or Tails/Tails.
2)

    
{4, 4}
Returns: 10
Here, there are 10 formations we can make: {1, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 2}, {2, 3}, {2, 4}, {3, 3}, {3, 4}, {4, 4}.
3)

    
{3, 4}
Returns: 9
Now it is impossible to get {4, 4} because the first die has only 3 sides.
4)

    
{4, 5, 6}
Returns: 48

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long mark[33][33];

class DiceGames{
public:
	long long countFormations(vector <int> sides){
		memset(mark,-1,sizeof(mark));
		sort(sides.begin(),sides.end());
		int n = sides.size();
		return myCount(sides,n-1,sides[n-1]);
	}
	long long myCount(const vector<int>&sides,int cur,int h){
		if(h<1) return 0;
		if(cur<0) return 0;
		if(h==1) return 1;
		if(cur==0) return min(h,sides[cur]);
		long long res = 0;
		int height = min(h,sides[cur]);
		if(mark[cur][height]!=-1) return mark[cur][height];
		for(int i=height;i>0;--i){
			res += myCount(sides,cur-1,i);
		}
		mark[cur][height] = res;
		return res;
	}
};
