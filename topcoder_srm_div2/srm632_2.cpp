/*
 Problem Statement
     
 We have a sequence of N positive integers: a[0] through a[N-1]. You do not know these integers. All you know is the number of trailing zeros in their binary representations. You are given a vector <int> d with N elements. For each i, d[i] is the number of trailing zeros in the binary representation of a[i].
 For example, suppose that a[0]=40. In binary, 40 is 101000 which ends in three zeros. Therefore, d[0] will be 3.
 You like geometric sequences. (See the Notes section for a definition of a geometric sequence.) You would like to count all non-empty contiguous subsequences of the sequence a[0], a[1], ..., a[N-1] that can be geometric sequences (given the information you have in d).
 More precisely: For each pair (i,j) such that 0 <= i <= j <= N-1, we ask the following question: "Given the values d[i] through d[j], is it possible that the values a[i] through a[j] form a geometric sequence?"
 For example, suppose that d = {0,1,2,3,2}. For i=0 and j=3 the answer is positive: it is possible that the values a[0] through a[3] are {1,2,4,8} which is a geometric sequence. For i=1 and j=4 the answer is negative: there is no geometric sequence with these numbers of trailing zeros in binary.
 Compute and return the number of contiguous subsequences of a[0], a[1], ..., a[N-1] that can be geometric sequences.
 Definition
     
Class:
PotentialGeometricSequence
Method:
numberOfSubsequences
Parameters:
vector <int>
Returns:
int
Method signature:
int numberOfSubsequences(vector <int> d)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
A geometric sequence is any sequence g[0], g[1], ..., g[k-1] such that there is a real number q (the quotient) with the property that for each valid i, g[i+1] = g[i]*q. For example, {1,2,4,8} is a geometric sequence with q=2, {7,7,7} is a geometric sequence with q=1, and {18,6,2} is a geometric sequence with q=1/3.
Constraints
-
N will be between 1 and 50, inclusive.
-
d will contain exactly N elements.
-
Each element of d will be between 0 and 100, inclusive.
Examples
0)

    
{0,1,2}
Returns: 6
One possibility is that a[0]=3, a[1]=6, and a[2]=12. In this case, all contiguous subsequences of this sequence are geometric.
1)

    
{1,2,4}
Returns: 5
All one-element and two-element subsequences are geometric. The entire sequence cannot be geometric.
2)

    
{3,2,1,0}
Returns: 10

3)

    
{1,2,4,8,16}
Returns: 9

4)

    
{1,3,5,5,5,5,64,4,23,2,3,4,5,4,3}
Returns: 37

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
using namespace std;

class PotentialGeometricSequence{
public:
	int numberOfSubsequences(vector <int> d);
};

int PotentialGeometricSequence::numberOfSubsequences(vector <int> d){
	int n = d.size();
	if(n==0||n==1) return n;
	if(n==2) return n+1;
	int res = 0;
	int sub = d[1]-d[0];
	int start = 0;
	for(int i=2;i<n;++i){
		if(d[i]-d[i-1]!=sub){
			sub = d[i]-d[i-1];
			res += ((i-start)*(i-start+1)/2-1);
			start = i-1;
		}
	}
	res += (n-start)*(n-start+1)/2;
	return res;
}
