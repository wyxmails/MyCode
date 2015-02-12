/*

Problem Statement
    
You are given two ints: N and K. Lun the dog is interested in strings that satisfy the following conditions:
The string has exactly N characters, each of which is either 'A' or 'B'.
The string s has exactly K pairs (i, j) (0 <= i < j <= N-1) such that s[i] = 'A' and s[j] = 'B'.
If there exists a string that satisfies the conditions, find and return any such string. Otherwise, return an empty string.
Definition
    
Class:
AB
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
N will be between 2 and 50, inclusive.
-
K will be between 0 and N(N-1)/2, inclusive.
Examples
0)

    
3
2
Returns: "ABB"
This string has exactly two pairs (i, j) mentioned in the statement: (0, 1) and (0, 2).
1)

    
2
0
Returns: "BA"
Please note that there are valid test cases with K = 0.
2)

    
5
8
Returns: ""
Five characters is too short for this value of K.
3)

    
10
12
Returns: "BAABBABAAB"
Please note that this is an example of a solution; other valid solutions will also be accepted.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class AB{
public:	
	string createString(int N, int K){
		string res = "";
		int half = N/2;
		if(half*(N-half)<K) return res;
		int a=0,b=N,total=0;
		res.append(N,'B');
		int left = K;
		while(left>0&&b>0){
			int next = b-1-a;
			if(left>=next){
				res[N-b] = 'A';
				total += next;
				left -= next;
			}else{
				for(int i=b-1;i>a;--i){
					if(i-1-a<=left){
						res[N-i] = 'A';
						total += (i-1-a);
						left -= (i-1-a);
						b=i;
						break;
					}
				}
			}
			b--;
			a++;
		}
		if(left==0) return res;
		return  "";
	}
};
