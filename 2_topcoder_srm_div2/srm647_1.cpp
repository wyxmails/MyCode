/*

Problem Statement
    
A teacher is trying to arrange a group of students into a line. The teacher knows that whenever she places two students with the same age next to each other, they will talk and disturb everyone. She wants to avoid that.
You are given a vector <int> x. Each element of x is the age of one of the students.
Determine whether it is possible for the teacher to arrange the students in a line so that there are no disturbances. If it can be done, return "possible" (quotes for clarity). If there will always be some pair of adjacent students with the same age, return "impossible". Note that the return value is case-sensitive.
Definition
    
Class:
PeacefulLine
Method:
makeLine
Parameters:
vector <int>
Returns:
string
Method signature:
string makeLine(vector <int> x)
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
x will have between 1 and 25 elements, inclusive.
-
Each element of x will be between 1 and 25, inclusive.
Examples
0)

    
{1,2,3,4}
Returns: "possible"
In this case, no two students have the same age so any order works.
1)

    
{1,1,1,2}
Returns: "impossible"
Regardless of which order we choose, two of the 1s will always be adjacent.
2)

    
{1,1,2,2,3,3,4,4}
Returns: "possible"
One example of a peaceful line is {1,2,3,4,1,2,3,4}
3)

    
{3,3,3,3,13,13,13,13}
Returns: "possible"

4)

    
{3,7,7,7,3,7,7,7,3}
Returns: "impossible"

5)

    
{25,12,3,25,25,12,12,12,12,3,25}
Returns: "possible"

6)

    
{3,3,3,3,13,13,13,13,3}
Returns: "possible"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class PeacefulLine{
public:
	string makeLine(vector <int> x){
		vector<int> mark(26,0);
		int n = x.size();
		for(int i=0;i<n;++i)
			mark[x[i]]++;
		int maxi = (n+1)/2;
		for(int i=0;i<26;++i)
			if(mark[i]>maxi) return "impossible";
		return "possible";
	}
};
