/*

Problem Statement
    
Little Elephant from the Zoo of Lviv likes integers.

You are given an vector <int> A. On a single turn, Little Elephant can double (i.e., multiply by 2) any element of A. He may double the same element more than once, if he wants to. He wants to obtain an array in which all elements are equal. Return "YES" (quotes for clarity) if it is possible to do that and "NO" otherwise.
Definition
    
Class:
LittleElephantAndDouble
Method:
getAnswer
Parameters:
vector <int>
Returns:
string
Method signature:
string getAnswer(vector <int> A)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
The return value is case-sensitive. Make sure that you return the exact strings "YES" and "NO".
Constraints
-
A will contain between 1 and 50 elements, inclusive.
-
Each element of A will be between 1 and 1,000,000,000, inclusive.
Examples
0)

    
{1, 2}
Returns: "YES"
One possible way of making all elements equal is to double the element at index 0.
1)

    
{1, 2, 3}
Returns: "NO"
It's impossible to make all three elements equal in this case.
2)

    
{4, 8, 2, 1, 16}
Returns: "YES"

3)

    
{94, 752, 94, 376, 1504}
Returns: "YES"

4)

    
{148, 298, 1184}
Returns: "NO"

5)

    
{7, 7, 7, 7}
Returns: "YES"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class LittleElephantAndDouble{
public:
	string getAnswer(vector <int> A){
		string yes("YES"),no("NO");
		int n = A.size();
		for(int i=1;i<n;++i){
			int tmp = max(A[0],A[i])%min(A[0],A[i]);
			if(tmp) return no;
			tmp = max(A[0],A[i])/min(A[0],A[i]);
			if((tmp&(tmp-1))!=0) return no;
		}
		return yes;
	}
};
