/*
Problem Statement
    
Alien Fred wants to destroy the Earth, but he forgot the password that activates the planet destroyer.

You are given a string S. Fred remembers that the correct password can be obtained from S by erasing exactly one character.

Return the number of different passwords Fred needs to try.
Definition
    
Class:
AlienAndPassword
Method:
getNumber
Parameters:
string
Returns:
int
Method signature:
int getNumber(string S)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
S will contain between 1 and 50 characters, inclusive.
-
Each character in S will be an uppercase English letter ('A'-'Z').
Examples
0)

    
"A"
Returns: 1
In this case, the only password Fred needs to try is an empty string.
1)

    
"ABA"
Returns: 3
The following three passwords are possible in this case: "BA", "AA", "AB".
2)

    
"AABACCCCABAA"
Returns: 7

3)

    
"AGAAGAHHHHFTQLLAPUURQQRRRUFJJSBSZVJZZZ"
Returns: 26

4)

    
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"
Returns: 1
Regardless of which character we erase, we will always obtain the same string. Thus there is only one possible password: the string that consists of 49 'Z's.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class AlienAndPassword{
public:
	int getNumber(string S){
		int n = S.size();
		int res = 0;
		for(int i=0;i<n;++i){
			if(i==0||S[i]!=S[i-1]) res++;
		}
		return res;
	}
};
