/*
 Problem Statement
     
 You have a vector <int> A with N elements.  Your goal is to change it into a vector <int> that contains each number from 1 to N exactly once. The change will consist of zero or more steps. In each step, you may pick an arbitrary element of A and increment its value by k. You may pick the same element multiple times. Note that you are not allowed to decrement the value of any element.  You are given the int k and the vector <int> A. Return "POSSIBLE" if it is possible to achieve your goal. Return "IMPOSSIBLE" otherwise.
 Definition
     
Class:
IncrementingSequence
Method:
canItBeDone
Parameters:
int, vector <int>
Returns:
string
Method signature:
string canItBeDone(int k, vector <int> A)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
Return value is case-sensitive. For example, you can't return "Possible" or "possible" instead of "POSSIBLE".
Constraints
-
k will be between 1 and 10, inclusive.
-
A will contain between 1 and 50 elements, inclusive.
-
Each element of A will be between 1 and 50, inclusive.
Examples
0)

    
3
{1,2,4,3}
Returns: "POSSIBLE"
This sequence of length 4 already contains all numbers from 1 to 4 exactly once. Note that their order does not matter.
1)

    
5
{2,2}
Returns: "IMPOSSIBLE"

2)

    
1
{1,1,1,1,1,1,1,1}
Returns: "POSSIBLE"
There are many ways to achieve the goal. For example, it is possible to obtain the sequence {1,2,3,4,5,6,7,8}. To do this, just increment the element at each position one by one until it reaches the required value.
3)

    
2
{5,3,3,2,1}
Returns: "IMPOSSIBLE"
We want to have the values {1,2,3,4,5}, in any order. Currently, we are missing the 4. As k=2, the only way to produce a 4 is by incrementing a 2. But if we increment our only 2, we will have no way of producing another 2.
4)

    
9
{1,2,3,1,4,5,6,7,9,8}
Returns: "POSSIBLE"

5)

    
2
{1,1,1,1,1,1,2,2,2,2,2,2}
Returns: "POSSIBLE"

6)

    
1
{1}
Returns: "POSSIBLE"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IncrementingSequence{
public:
	string canItBeDone(int k, vector <int> A);
};
string IncrementingSequence::canItBeDone(int k, vector <int> A){
	string pos = "POSSIBLE";
	string impos = "IMPOSSIBLE";
	int n = A.size();
	vector<int> B(n,0);
	vector<int> C;
	for(int i=0;i<n;++i){
		if(A[i]>n) return impos;
		if(A[i]>0&&B[A[i]-1]==0) B[A[i]-1] = A[i];
		else C.push_back(A[i]);
	}
	vector<int> left;
	for(int i=0;i<n;++i){
		if(B[i]==0) left.push_back(i+1);
	}
	int m = C.size();
	if(m==0) return pos;
	sort(C.begin(),C.end());
	sort(left.begin(),left.end());
	for(int i=0;i<m;++i){
		for(int j=0;j<C.size();++j){
			if(C[j]>left[i]) return impos;
			if((left[i]-C[j])%k==0){
				C.erase(C.begin()+j); break;
			}else if(j==C.size()-1) return impos;
		}
	}
	return pos;
}
