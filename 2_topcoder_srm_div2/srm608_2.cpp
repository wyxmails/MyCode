/*

Problem Statement
    
TopCoder admin mystic_tc is sitting in front of a table. He found N sealed boxes of candies on the table.  He is not sure how many candies each box contains. However, he knows the following information:
The total number of candies in the boxes is C.
For each i, box i (0-based index) contains between 0 and high[i] candies, inclusive.
 You know that mystic_tc eats candies as follows: first he chooses a subset of the boxes, then he opens them and eats all the candies he found inside. He wants to eat at least X candies. And as he is smart, he will always choose a subset of boxes for which he is sure that they must contain at least X candies.  You are given the ints C and X, and the vector <int> high. Return the smallest number of boxes mystic_tc may choose.
Definition
    
Class:
MysticAndCandiesEasy
Method:
minBoxes
Parameters:
int, int, vector <int>
Returns:
int
Method signature:
int minBoxes(int C, int X, vector <int> high)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
high will contain between 1 and 50 elements, inclusive.
-
Each element of high will be between 1 and 50, inclusive.
-
C will be between 1 and the sum of all elements of high, inclusive.
-
X will be between 1 and C, inclusive.
Examples
0)

    
10
10
{20}
Returns: 1
There is only one box. It contains all 10 candies. In order to eat 10 candies mystic_tc must open it.
1)

    
10
7
{3, 3, 3, 3, 3}
Returns: 4
Now there are many possibilities for the contents of boxes. For example, there could be three boxes with 3 candies each, one box with 1 candy, and one empty box. Another possibility is that there could be five boxes with 2 candies each. Note that in this case mystic_tc could open three boxes and still get only 6 candies, so he needs to open at least four boxes to be sure he gets at least 7 candies. And it can be proved that if mystic_tc opens any four of these boxes, they will always contain at least 7 candies in total.
2)

    
100
63
{12, 34, 23, 45, 34}
Returns: 3
Open boxes 1, 3, 4 (0-based). It can be proved that these boxes contain at least 65 candies in total.
3)

    
19
12
{12, 9, 15, 1, 6, 4, 9, 10, 10, 10, 14, 14, 1, 1, 12, 10, 9, 2, 3, 6, 1, 7, 3, 4, 10, 3, 14}
Returns: 22

4)

    
326
109
{9, 13, 6, 6, 6, 16, 16, 16, 10, 16, 4, 3, 10, 8, 11, 17, 12, 5, 7, 8, 7, 4, 15, 7, 14, 2, 2, 1, 17, 1, 7, 7, 12, 17, 2, 9, 7, 1, 8, 16, 7, 4, 16, 2, 13, 3, 13, 1, 17, 6}
Returns: 15

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MysticAndCandiesEasy{
public:
	int minBoxes(int C, int X, vector <int> high){
		int left = C-X;
		sort(high.begin(),high.end());
		int n = high.size();
		for(int i=0;i<n;++i){
			if(high[i]>left) return n-i;
			left -= high[i];
		}
		return 1;
	}
};
