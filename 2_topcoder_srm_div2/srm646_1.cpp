/*

Problem Statement
    
John and Brus have a set of integers. You are given its elements in a vector <int> numbers. They can change the integers in numbers by performing some operations. In each operation John will pick a number and Brus will either increase or decrease it by 1.  You are also given an int k which is either 1 or 2. John and Brus want to have at least k integers with consecutive values in their set. Compute and return the smallest number of operations they have to perform.
Definition
    
Class:
TheConsecutiveIntegersDivTwo
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
k will be between 1 and 2, inclusive.
Examples
0)

    
{4, 47, 7}
2
Returns: 2
There are three optimal strategies:
Increase 4 two times to obtain {6,47,7}.
Decrease 7 two times to obtain {4,47,5}.
Increase 4 and decrease 7 to obtain {5,47,6}.
Note that the consecutive values can appear anywhere in the set, their position in numbers does not matter.
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

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TheConsecutiveIntegersDivTwo{
public:
	int find(vector <int> numbers, int k){
		if(k==1) return 0;
		sort(numbers.begin(),numbers.end());
		int res = numbers[1]-numbers[0];
		for(int i=2;i<numbers.size();++i)
			res = min(res,numbers[i]-numbers[i-1]);
		return res-1;
	}
};
