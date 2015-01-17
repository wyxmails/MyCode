/*

Problem Statement
    
John and Brus have some integers. You are given these integers in a vector <int> numbers. In one operation they can pick a number and increase/decrease it by 1. They want to have at least k consecutive integers. The order in which those integers appear in numbers does not matter. Return the minimal number of operations required to achieve the goal.
Definition
    
Class:
TheConsecutiveIntegersDivOne
Method:
find
Parameters:
vector <int>, int
Returns:
int
Method signature:
int find(vector <int> numbers, int k)
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
numbers will contain between 2 and 47 elements, inclusive.
-
Each element of numbers will be between -10,000,000 and 10,000,000, inclusive.
-
All elements of numbers will be distinct.
-
k will be between 1 and the number of elements in numbers, inclusive.
Examples
0)

    
{4, 7, 47}
2
Returns: 2
There are three optimal strategies:
Increase 4 two times to obtain {6,7,47}.
Decrease 7 two times to obtain {4,5,47}.
Increase 4 and decrease 7 to obtain {5,6,47}.
1)

    
{1, 100}
1
Returns: 0
No operation is needed.
2)

    
{-96, -53, 82, -24, 6, -75}
2
Returns: 20

3)

    
{64, -31, -56}
2
Returns: 24

4)

    
{-96, -53, 82, -24, 6, -75}
4
Returns: 90

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TheConsecutiveIntegersDivOne{
public:
	int find(vector <int> num, int k){
		if(k==1) return 0;
		sort(num.begin(),num.end());
		int n = num.size();
		int res=-1;
		for(int i=0;i+k<=n;++i){
			int mid=0;
			for(int j=i,m=i+k-1;j<m;++j,--m)
				mid += (num[m]-num[j]-(m-j));
			if(res==-1) res = mid;
			else res = min(res,mid);
		}
		return res;
	}
};
