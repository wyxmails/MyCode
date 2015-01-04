/*

Problem Statement
    
It's winter time! Time to eat a lot of mandarins with your friends.

You have several bags with mandarins. You are given an vector <int> bags. For each i, the i-th element of bags represents the number of mandarins in the i-th bag. You are also given an int K. You want to choose exactly K bags and distribute them among you and your friends. To be as fair as possible, you want to minimize the difference between the chosen bag with most mandarins and the chosen bag with fewest mandarins. Return the smallest difference that can be achieved.
Definition
    
Class:
WinterAndMandarins
Method:
getNumber
Parameters:
vector <int>, int
Returns:
int
Method signature:
int getNumber(vector <int> bags, int K)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
bags will contain between 2 and 50 elements, inclusive.
-
Each element of bags will be between 1 and 1,000,000,000, inclusive.
-
K will be between 2 and N, inclusive, where N is the number of elements in bags.
Examples
0)

    
{10, 20, 30}
2
Returns: 10
There are three ways to choose two bags in this case: {10, 20}, {20, 30}, and {10, 30}. Both in the first case and in the second case the difference between the largest and the smallest number of mandarins is 10. In the third case the difference is 20. Thus, the smallest possible difference is 10.
1)

    
{4, 7, 4}
3
Returns: 3

2)

    
{4, 1, 2, 3}
3
Returns: 2

3)

    
{5, 4, 6, 1, 9, 4, 2, 7, 5, 6}
4
Returns: 1

4)

    
{47, 1000000000, 1, 74}
2
Returns: 27

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class WinterAndMandarins{
public:
	int getNumber(vector <int> bags, int K){
		int n = bags.size();
		sort(bags.begin(),bags.end());
		int res = INT_MAX;
		for(int i=0;i+K<=n;++i){
			res = min(bags[i+K-1]-bags[i],res);
		}
		return res;
	}
};
