/*

Problem Statement
    
For any non-empty sequence of positive integers s1, s2, ..., sK their least common multiple is the smallest positive integer that is divisible by each of the given numbers. We will use "lcm" to denote the least common multiple. For example, lcm(3) = 3, lcm(4,6) = 12, and lcm(2,5,7) = 70.   You are given a vector <int> S and an int x. Find out whether we can select some elements from S in such a way that their least common multiple will be precisely x. Formally, we are looking for some s1, s2, ..., sK, K >= 1, such that each si belongs to S, and x=lcm(s1, s2, ..., sK). Return "Possible" if such elements of S exist, and "Impossible" if they don't.
Definition
    
Class:
LCMSetEasy
Method:
include
Parameters:
vector <int>, int
Returns:
string
Method signature:
string include(vector <int> S, int x)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
S will contain between 1 and 50 elements, inclusive.
-
Each element in S will be between 1 and 1,000,000,000, inclusive.
-
Elements in S will be distinct.
-
x will be between 2 and 1,000,000,000, inclusive.
Examples
0)

    
{2,3,4,5}
20
Returns: "Possible"
We can obtain 20 in multiple ways. One of them: 20 = lcm(4, 5).
1)

    
{2,3,4}
611
Returns: "Impossible"
If S={2,3,4}, the only values we can obtain are 2, 3, 4, 6, and 12.
2)

    
{2,3,4}
12
Returns: "Possible"

3)

    
{1,2,3,4,5,6,7,8,9,10}
24
Returns: "Possible"

4)

    
{100,200,300,400,500,600}
2000
Returns: "Possible"

5)

    
{100,200,300,400,500,600}
8000
Returns: "Impossible"

6)

    
{1000000000,999999999,999999998}
999999999
Returns: "Possible"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class LCMSetEasy{
public:
	string include(vector <int> S, int x){
		int left = x;
		for(int r=2;r*r<=left;++r){
			int cur=1;
			while(left%r==0){
				cur *= r;
				left /= r;
			}
			if(cur!=1){
				bool found = false;
				for(int i=0;!found&&i<S.size();++i){
					if(x%S[i]==0&&S[i]%cur==0)
						found = true;
				}
				if(!found) return "Impossible";
			}
		}
		if(left!=1){
			bool found = false;
			for(int i=0;!found&&i<S.size();++i){
				if(x%S[i]==0&&S[i]%left==0)
					found = true;
			}
			if(!found) return "Impossible";
		}
		return "Possible";
	}
};
