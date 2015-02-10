/*

Problem Statement
    
You are given an integer sequence A and an int N that is a power of 2. All elements of A are between 0 and N-1, inclusive.  You can now choose an integer B which is between 0 and N-1, inclusive. This integer determines a new sequence C defined as follows: For each valid i, C[i] = (A[i] xor B).  Given the sequence C, we will count the pairs of indices (i,j) such that both i<j and C[i]<C[j]. Compute and return the largest result we can obtain.  You are given the int N. You are also given ints sz, A0, A1, P, Q, and R. Use the following pseudocode to generate the sequence A:  
A[0] = A0;
A[1] = A1;
for (i = 2; i < sz; i++) {
    A[i] = (A[i - 2] * P + A[i - 1] * Q + R) modulo N;
}
Definition
    
Class:
XorSequence
Method:
getmax
Parameters:
int, int, int, int, int, int, int
Returns:
long long
Method signature:
long long getmax(int N, int sz, int A0, int A1, int P, int Q, int R)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Notes
-
Watch out for integer overflow when generating the sequence A.
Constraints
-
N will be between 2 and 1,073,741,824 (2^30), inclusive.
-
N will be a power of 2.
-
sz will be between 2 and 131,072, inclusive.
-
A0 will be between 0 and N-1, inclusive.
-
A1 will be between 0 and N-1, inclusive.
-
P will be between 0 and N-1, inclusive.
-
Q will be between 0 and N-1, inclusive.
-
R will be between 0 and N-1, inclusive.
Examples
0)

    
4
6
3
2
0
1
3
Returns: 8
Using the provided pseudocode you should compute that A={3,2,1,0,3,2}. For B=3 we then get C={0,1,2,3,0,1}. For this C there are 8 pairs (i,j) such that i<j and C[i]<C[j]. These are the 8 pairs: (0,1), (0,2), (0,3), (0,5), (1,2), (1,3), (2,3), and (4,5). No other choice of B produces more than 8 pairs.
1)

    
8
8
2
5
3
1
4
Returns: 13
A={2,5,7,2,3,5,2,5}.
2)

    
8
7
3
0
1
2
4
Returns: 12
A={3,0,7,2,7,4,3}.
3)

    
32
15
7
9
11
2
1
Returns: 60
A={7,9,0,4,9,31,2,26,11,21,4,16,13,11,6}.
4)

    
131072
131072
7
7
1
0
0
Returns: 0
All elements of A are equal to 7. Regardless of the value of B you choose, all elements in C will be equal as well. Thus, the number of pairs we seek is always zero.
5)

    
131072
131070
411
415
398
463
9191
Returns: 4302679760

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class XorSequence{
public:
	long long getmax(int N, int sz, int A0, int A1, int P, int Q, int R){
		vector<int> A(sz,0);
		A[0] = A0;A[1] = A1;
		long long p=P,q=Q,r=R;
		for(int i=2;i<sz;++i)
			A[i] = (A[i-2]*p+A[i-1]*q+r)%N;
		vector<vector<int> > arrs;
		arrs.push_back(A);
		int bits = log2(N);
		return myGet(arrs,bits);
	}
	long long myGet(vector<vector<int> > arrs,int bits){
		long long res = 0;
		for(int i=bits-1;i>=0;--i){
			vector<vector<int> > next_arrs;
			long long t0=0,t1=0;
			for(vector<int> &A:arrs){
				vector<int> A0,A1;
				long long n0=0,n1=0;
				for(int j=0;j<A.size();++j){
					if(A[j]&(1<<i)){
						t0 += n0;
						n1++;
						A1.push_back(A[j]);
					}else{
						t1 += n1;
						n0++;
						A0.push_back(A[j]);
					}
				}
				if(i>0){
					if(!A0.empty()) next_arrs.emplace_back(move(A0));
					 
					if(!A1.empty()) next_arrs.emplace_back(move(A1));
				}
			}
			arrs.swap(next_arrs);
			res += max(t0,t1);
		}
		return res;
	}
};
