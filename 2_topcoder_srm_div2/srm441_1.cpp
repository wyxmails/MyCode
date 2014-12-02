/*
 Problem Statement
     
 If X and Y are two strings of equal length N, then the difference between them is defined as the number of indices i where the i-th character of X and the i-th character of Y are different. For example, the difference between the words "ant" and "art" is 1.  You are given two strings, A and B, where the length of A is less than or equal to the length of B. You can apply an arbitrary number of operations to A, where each operation is one of the following:
 Choose a character c and add it to the beginning of A.
 Choose a character c and add it to the end of A.
 Apply the operations in such a way that A and B have the same length and the difference between them is as small as possible. Return this minimum possible difference.
 Definition
     
Class:
DifferentStrings
Method:
minimize
Parameters:
string, string
Returns:
int
Method signature:
int minimize(string A, string B)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
A and B will each contain between 1 and 50 characters, inclusive.
-
A and B will both contain only lowercase letters ('a'-'z').
-
The length of A will be less than or equal to the length of B.
Examples
0)

    
"koder"
"topcoder"
Returns: 1
You can prepend "top" to "koder" and you'll get "topkoder". The difference between "topkoder" and "topcoder" is 1.
1)

    
"hello"
"xello"
Returns: 1
A and B already have the same length so you cannot add any characters to A.
2)

    
"abc"
"topabcoder"
Returns: 0

3)

    
"adaabc"
"aababbc"
Returns: 2

4)

    
"giorgi"
"igroig"
Returns: 6

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class DifferentStrings{
public:
	int minimize(string A, string B);
};

int cmp(string A,string B,int index=0){
	int n = A.size();
	int diff = 0;
	for(int i=0;i<n;++i)
		if(A[i]!=B[index+i]) diff++;
	return diff;
}

int DifferentStrings::minimize(string A, string B){
	if(A.size()==B.size()) return cmp(A,B);
	int n = A.size();
	int m = B.size();
	int min_diff=INT_MAX;
	for(int i=0;i<=m-n;++i)
		min_diff = min(min_diff,cmp(A,B,i));
	return min_diff;
}
