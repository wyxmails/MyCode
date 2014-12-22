/*

Problem Statement
    
You are given a vector <int> A with N elements, where N is even. Note that some elements of A may be negative. You are also given a int X which is guaranteed to be negative. You must divide the elements of A into N/2 disjoint pairs. (That is, each element of A must be in exactly one of those pairs.) Your goal is to maximize the number of pairs in which the product of the two elements is greater than or equal to X. Return the largest possible number of such pairs.
Definition
    
Class:
SplitIntoPairs
Method:
makepairs
Parameters:
vector <int>, int
Returns:
int
Method signature:
int makepairs(vector <int> A, int X)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
A will contain between 2 and 50 elements, inclusive.
-
The number of elements in A will be even.
-
Each element in A will be between -1,000,000,000 and 1,000,000,000, inclusive.
-
X will be between -1,000,000,000 and -1, inclusive.
Examples
0)

    
{2,-1}
-1
Returns: 0
One possible pair has product -2, which is lower than needed.
1)

    
{1,-1}
-1
Returns: 1
Here product is -1, it's enough.
2)

    
{-5,-4,2,3}
-1
Returns: 2
If first pair contains numbers -5 and -4, and second contains 2 and 3, both will have positive product.
3)

    
{5,-7,8,-2,-5,3}
-7
Returns: 3
Acceptable splitting is {5,8}, {-7,-5} and {-2,3}.
4)

    
{3,4,5,6,6,-6,-4,-10,-1,-9}
-2
Returns: 4

5)

    
{1000000,1000000}
-5
Returns: 1
Beware overflow.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SplitIntoPairs{
public:
	int makepairs(vector <int> A, int X){
		int n = A.size();
		sort(A.begin(),A.end());
		int neg=0,pos=0;
		long long sn=0,sp=0;
		for(int i=0;i<n;++i){
			if(A[i]<0) neg++;
			else{
				pos++;
				if(i!=0&&sn==0){
					sn = A[i-1];
					sp = A[i];
				}
			}
		}
		int res;
		if(neg&1){
			res = n/2-1;
			if(sn*sp>=X) res++;
		}else res = n/2;
		return res;
	}
};
