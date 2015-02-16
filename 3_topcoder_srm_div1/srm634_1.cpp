/*

Problem Statement
    
A store sells M different items, conveniently numbered 0 through M-1. For a shopping survey you interviewed N customers. Each customer responded to the survey with a list of items they've bought. Each customer bought at most one of each item. It is possible that some customers did not buy anything at all.
After collecting the responses, you've summed up the results and found that s[i] people have bought item i. Due to an unfortunate accident, you've then lost the actual survey responses. All you have left are the values s[i] you computed.
You are now supposed to report the number of big shoppers among the survey respondents. A big shopper is defined as a customer who has bought K or more items. Of course, having lost the detailed responses, you might be unable to determine the actual number of big shoppers.
You are given the ints N and K, and the vector <int> s with M elements. Compute and return the smallest possible number of big shoppers.
Definition
    
Class:
ShoppingSurveyDiv1
Method:
minValue
Parameters:
int, int, vector <int>
Returns:
int
Method signature:
int minValue(int N, int K, vector <int> s)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
N will be between 1 and 500, inclusive.
-
s will contain between 1 and 500 elements, inclusive.
-
Each element in s will be between 0 and N, inclusive.
-
K will be between 1 and the length of s, inclusive.
Examples
0)

    
10
2
{1, 2, 3}
Returns: 0
There are 10 customers. Item 0 was bought by 1 customer, item 1 by 2 customers, and item 2 by 3 of the customers. A big shopper is a customer who bought at least 2 items. Given this data it is possible that there are no big shoppers at all. (There could have been six customers who bought one item each, and four other customers who didn't buy anything at all.)
1)

    
5
2
{1, 2, 3}
Returns: 1

2)

    
4
4
{4, 4, 4, 2}
Returns: 2

3)

    
20
3
{1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3}
Returns: 10

4)

    
4
2
{1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1}
Returns: 2

5)

    
2
3
{1, 1, 1, 2}
Returns: 1

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ShoppingSurveyDiv1{
public:
	int minValue(int N, int K, vector <int> s){
		for(int i=0;i<N;++i){
			sort(s.begin(),s.end());
			reverse(s.begin(),s.end());
			if(s.size()>=K&&s[K-1]==N-i)
				return N-i;
			for(int j=0;j<K-1;++j)
				if(j<s.size()) s[j] -= 1;			
		}
		return 0;
	}
};
