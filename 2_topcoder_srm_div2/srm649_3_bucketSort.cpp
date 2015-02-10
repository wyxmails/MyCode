/*

Problem Statement
    
You are given a vector <int> A and an int N that is a power of 2. All elements of A are between 0 and N-1, inclusive.  You can now choose an integer B which is between 0 and N-1, inclusive. This integer determines a new sequence C defined as follows: For each valid i, C[i] = (A[i] xor B).  Given the sequence C, we will count the pairs of indices (i,j) such that both i<j and C[i]<C[j]. Compute and return the largest result we can obtain.
Definition
    
Class:
XorSequenceEasy
Method:
getmax
Parameters:
vector <int>, int
Returns:
int
Method signature:
int getmax(vector <int> A, int N)
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
XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
-
For example 42 XOR 7 is performed as follows. First, the numbers are converted to binary: 42 is 101010 and 7 is 111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 7 becomes 000111. Then 101010 XOR 000111 = 101101 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 101101 = 45, so 42 XOR 7 = 45.
Constraints
-
N will be between 2 and 1,073,741,824 (2^30), inclusive.
-
N will be a power of 2.
-
The number of elements in A will be between 1 and 50, inclusive.
-
Each element in A will be between 0 and N-1, inclusive.
Examples
0)

    
{3,2,1,0,3,2}
4
Returns: 8
For B=3 we get C={0,1,2,3,0,1}. For this C there are 8 pairs (i,j) such that i<j and C[i]<C[j]. These are the 8 pairs: (0,1), (0,2), (0,3), (0,5), (1,2), (1,3), (2,3), and (4,5). No other choice of B produces more than 8 pairs.
1)

    
{3,0,4,6,1,5,7,6}
8
Returns: 21

2)

    
{3,1,4,1,5,9,2,6,5,3,5,8,9,7,9}
16
Returns: 76

3)

    
{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}
8
Returns: 0
Regardless of the value of B you choose, all elements in C will be equal. Thus, the number of pairs we seek is always zero.
4)

    
{408024109,11635919,196474438,117649705,812669700,553475508,445349752,271145432,730417256,738416295
,147699711,880268351,816031019,686078705,1032012284,182546393,875376506,220137366,906190345,16216108
,799485093,715669847,413196148,122291044,777206980,68706223,769896725,212567592,809746340,964776169
,928126551,228208603,918774366,352800800,849040635,941604920,326686120,920977486,964528038,659998484
,207195539,607901477,725914710,655525412,949610052,142750431,766838105,1024818573,836758851,97228667}
1073741824
Returns: 720

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class XorSequenceEasy{
public:
	int getmax(vector <int> A, int N){
		int n = A.size();
		int bits = log2(N);
		int b=0;
		int res = 0;
		for(int i=bits-1;i>=0;--i){
			int tmp0 = b;
			int tmp1 = b|(1<<i);
			vector<int> c0(n,0);
			vector<int> c1(n,0);
			for(int j=0;j<n;++j){
				c0[j] = tmp0^A[j];;
				c1[j] = tmp1^A[j];
			}
			int cc0 = count(c0);
			int cc1 = count(c1);
			b = cc0>cc1?tmp0:tmp1;
			if(i==0) res = max(cc0,cc1);
		}
		return res;
	}
	int count(vector<int> &c){
		int n = c.size();
		int cnt=0;
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				if(c[j]>c[i]) cnt++;
		return cnt;
	}
};
