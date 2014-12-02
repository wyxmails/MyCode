/*
 Problem Statement
     
 A store sells M different items, conveniently numbered 0 through M-1. For a shopping survey you interviewed N customers. Each customer responded to the survey with a list of items they've bought. Each customer bought at most one of each item. It is possible that some customers did not buy anything at all.
 After collecting the responses, you've summed up the results and found that s[i] people have bought item i. Due to an unfortunate accident, you've then lost the actual survey responses. All you have left are the values s[i] you computed.
 You are now supposed to report the number of big shoppers among the survey respondents. A big shopper is defined as a customer who has bought all M items. Of course, having lost the detailed responses, you might be unable to determine the actual number of big shoppers.
 You are given the int N and the vector <int> s with M elements. Compute and return the smallest possible number of big shoppers.
 Definition
     
Class:
ShoppingSurveyDiv2
Method:
minValue
Parameters:
int, vector <int>
Returns:
int
Method signature:
int minValue(int N, vector <int> s)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
N will be between 1 and 100, inclusive.
-
s will contain between 1 and 100 elements, inclusive.
-
Each element in s will be between 0 and N, inclusive.
Examples
0)

    
5
{3, 3}
Returns: 1
There are 5 customers and 2 items in the store. Each of the items was bought by three of the customers. Since there are five people and a total of six bought items, we must have at least one big shopper. And we can easily verify that there could have been exactly one big shopper and four other customers who have bought one item each.
1)

    
100
{97}
Returns: 97

2)

    
10
{9, 9, 9, 9, 9}
Returns: 5

3)

    
7
{1, 2, 3}
Returns: 0

4)

    
5
{3, 3, 3}
Returns: 0

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
using namespace std;

class ShoppingSurveyDiv2{
public:
	int minValue(int N, vector <int> s);
};

int ShoppingSurveyDiv2::minValue(int N, vector <int> s){
	int sum=0;
	int M = s.size();
	for(int i=0;i<M;++i){
		if(s[i]==0) return 0;
		sum += s[i];
	}
	int res = sum - N*(M-1);
	res = res>0?res:0;
	return res;
}
