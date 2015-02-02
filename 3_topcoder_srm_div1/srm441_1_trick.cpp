/*

Problem Statement
    
A permutation A[0], A[1], ..., A[N-1] is a sequence containing each integer between 0 and N-1, inclusive, exactly once. Each permutation A of length N has a corresponding child array B of the same length, where B is defined as follows:
B[0] = 0
B[i] = A[B[i-1]], for every i between 1 and N-1, inclusive.
A permutation is considered perfect if its child array is also a permutation.  Below are given all permutations for N=3 with their child arrays. Note that for two of these permutations ({1, 2, 0} and {2, 0, 1}) the child array is also a permutation, so these two permutations are perfect.
Permutation		Child array
{0, 1, 2}		{0, 0, 0}
{0, 2, 1}		{0, 0, 0}
{1, 0, 2}		{0, 1, 0}
{1, 2, 0}		{0, 1, 2}
{2, 0, 1}		{0, 2, 1}
{2, 1, 0}		{0, 2, 0}
You are given a vector <int> P containing a permutation of length N. Find a perfect permutation Q of the same length such that the difference between P and Q is as small as possible, and return this difference. The difference between P and Q is the number of indices i for which P[i] and Q[i] are different.
Definition
    
Class:
PerfectPermutation
Method:
reorder
Parameters:
vector <int>
Returns:
int
Method signature:
int reorder(vector <int> P)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
P will contain between 1 and 50 elements, inclusive.
-
P will contain each integer between 0 and N-1, inclusive, exactly once, where N is the number of elements in P.
Examples
0)

    
{2, 0, 1}
Returns: 0
P is a perfect permutation, so we can use the same permutation for Q. The difference is then 0 because P and Q are the same.
1)

    
{2, 0, 1, 4, 3}
Returns: 2
Q might be {2, 0, 3, 4, 1}.
2)

    
{2, 3, 0, 1}
Returns: 2
Q might be {1, 3, 0, 2}.
3)

    
{0, 5, 3, 2, 1, 4}
Returns: 3

4)

    
{4, 2, 6, 0, 3, 5, 9, 7, 8, 1}
Returns: 5

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PerfectPermutation{
public:
	int reorder(vector <int> P){
		int n = P.size();
		vector<bool> visited(n,false);
		int res = 0;
		for(int i=0;i<n;++i){
			if(visited[i]) continue;
			int next = i;
			while(!visited[next]){
				visited[next] = true;
				next = P[next];
			}
			res++;
		}
		if(res==1) res = 0;
		return res;
	}
};
