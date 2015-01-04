/*

Problem Statement
    
It's winter time! You have some candies arranged in a row and now you want to choose some of them and give them to your friend.

You are given a vector <int> type. Each candy has a type, which is some positive integer. For each i, type[i] represents the type of i-th candy. You want to choose some non-empty subset of candies with the following property: if the number of candies you choose is K, their types must be precisely all the numbers from 1 to K, inclusive. Return the number of different ways to do that. (Two ways are considered different if there exists some candy that is chosen in only one of them.)
Definition
    
Class:
WinterAndCandies
Method:
getNumber
Parameters:
vector <int>
Returns:
int
Method signature:
int getNumber(vector <int> type)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
The answer will always fit in a signed 32-bit integer.
Constraints
-
type will contain between 1 and 50 elements, inclusive.
-
Each element of type will be between 1 and 50, inclusive.
Examples
0)

    
{1, 3, 2}
Returns: 3
There are 7 possible non-empty subsets in this case:
(1)
(3)
(2)
(1, 3)
(1, 2)
(3, 2)
(1, 3, 2)
Out of them, only first, fifth and seventh are valid. Thus, the answer is 3.
1)

    
{1, 1, 2}
Returns: 4
Note that the chosen subset can never contain two elements with the same type.
2)

    
{1, 3, 2, 5, 7, 4, 5, 4}
Returns: 9

3)

    
{1, 1, 2, 2, 3, 3, 4, 4, 5, 5}
Returns: 62

4)

    
{2}
Returns: 0

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class WinterAndCandies{
public:
	int getNumber(vector <int> type){
		sort(type.begin(),type.end());
		return myGet(type,0,1);
	}
	int myGet(vector<int> type,int index,int cur){
		int n = type.size();
		int tmp = index;
		while(tmp<n&&type[tmp]==cur) tmp++;
		if(tmp==index) return 0;
		return (tmp-index)*(1+myGet(type,tmp,cur+1));
	}
};
