/*

Problem Statement
    
You are given two ints: N and K. Lun the dog is interested in strings that satisfy the following conditions:
The string has exactly N characters, each of which is either 'A', 'B' or 'C'.
The string s has exactly K pairs (i, j) (0 <= i < j <= N-1) such that s[i] < s[j].
If there exists a string that satisfies the conditions, find and return any such string. Otherwise, return an empty string.
Definition
    
Class:
ABC
Method:
createString
Parameters:
int, int
Returns:
string
Method signature:
string createString(int N, int K)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Constraints
-
N will be between 3 and 30, inclusive.
-
K will be between 0 and N(N-1)/2, inclusive.
Examples
0)

    
3
3
Returns: "ABC"
This string has exactly three pairs (i, j) mentioned in the statement: (0, 1), (0, 2) and (1, 2).
1)

    
3
0
Returns: "CBA"
Please note that there are valid test cases with K = 0.
2)

    
5
10
Returns: ""
Five characters is too short for this value of K.
3)

    
15
36
Returns: "CABBACCBAABCBBB"
Please note that this is an example of a solution; other valid solutions will also be accepted.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class ABC{
public:
	string createString(int N, int K){
		int p1 = N/3;
		int p2 = (N-p1)/2;
		int p3 = N-p1-p2;
		if(p1*(p2+p3)+p2*p3<K) return "";
		string res = "";
		int h1 = N/2;
		int h2 = N-h1;
		if(h1*h2>=K) return create2(N,K);
		res.append(h1,'A');
		res.append(h2,'C');
		int left = K-h1*(N-h1);
		int b1 = h1-1, b2 = N-h2;
		int b=0;
		while(left>0&&b1>=0&&b2<N){
			int nextL,nextR;
			nextL = h1-1-b;
			nextR = h2-1-b;
			if(left>=max(nextL,nextR)){
				b++;
				if(nextL>nextR){
					res[b1--] = 'B';
					left -= nextL;
					h1--;
				}else{
					res[b2++] = 'B';
					left -= nextR;
					h2--;
				}
			}else if(left<min(nextL,nextR)){ b1--; b2++;h1--;h2--;}
			else{
				b++;
				if(nextL<nextR){
					res[b1--] = 'B';
					left -= nextL;
					h1--;
				}else{
					res[b2++] = 'B';
					left -= nextR;
					h2--;
				}
			}
		}
		if(left==0) return res;
		return "";
	}
	string create2(int n,int k){
		string res = "";
		res.append(n,'B');
		int a=0,b=n,i=0,left=k;
		while(i<n&&left>0){
			int next = b-1-a;
			if(left>=next){
				res[i] = 'A';
				left -= next;
				a++;
			}
			i++;
			b--;
		}
		if(left==0) return res;
		return "";
	}
};
