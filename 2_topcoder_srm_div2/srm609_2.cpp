/*

Problem Statement
    
We have R red, G green, and B blue balls. We want to divide them into as few packages as possible. Each package must contain 1, 2, or 3 balls. Additionally, each package must be either a "normal set" (all balls in the package have the same color), or a "variety set" (no two balls have the same color). Compute and return the smallest possible number of packages.
Definition
    
Class:
PackingBallsDiv2
Method:
minPacks
Parameters:
int, int, int
Returns:
int
Method signature:
int minPacks(int R, int G, int B)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
R, G, and B will each be between 1 and 100, inclusive.
Examples
0)

    
4
2
4
Returns: 4
We have 4 red, 2 green, and 4 blue balls. Clearly, we need at least four packages to store 10 balls. One possibility of using exactly four packages looks as follows: RGB, RG, RR, BBB. (I.e., the first package has 1 ball of each color, the second package has a red and a green ball, and so on.)
1)

    
1
7
1
Returns: 3
Here the only possible solution is to have one package with RGB and two packages with GGG each.
2)

    
2
3
5
Returns: 4

3)

    
78
53
64
Returns: 66

4)

    
100
100
100
Returns: 100

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PackingBallsDiv2{
public:
	int minPacks(int R, int G, int B){
		vector<int> vec;
		vec.push_back(R);
		vec.push_back(G);
		vec.push_back(B);
		sort(vec.begin(),vec.end());
		int res = vec[0];
		vec[1] -= vec[0];
		vec[2] -= vec[0];
		res = vec[0]+vec[1]/3+vec[2]/3;
		int t1 = vec[1]%3;
		int t2 = vec[2]%3;
		if(t1&&t2) res += max(vec[1]%3,vec[2]%3);
		else if(t1||t2) res++;
		return res;
	}
};
