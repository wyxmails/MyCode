/*

Problem Statement
    
You had a non-empty string s but you lost it. Cat Snuke found the string and removed one character from the string. Later, Snuke gave you the string t. Can this be the string created from your string s?  You are given the strings s and t. Return "Possible" (quotes for clarity) if t can be obtained from s by erasing exactly one character. Otherwise, return "Impossible". Note that the return value is case-sensitive.
Definition
    
Class:
DecipherabilityEasy
Method:
check
Parameters:
string, string
Returns:
string
Method signature:
string check(string s, string t)
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
The number of characters in s will be between 1 and 50, inclusive.
-
Every character in s will be a lowercase letter ('a'-'z').
-
The number of characters in t will be between 1 and 50, inclusive.
-
Every character in t will be a lowercase letter ('a'-'z').
Examples
0)

    
"sunuke"
"snuke"
Returns: "Possible"
If Cat Snuke erase the first 'u' from s, it will equal to t.
1)

    
"snuke"
"skue"
Returns: "Impossible"
Swapping characters is not allowed.
2)

    
"snuke"
"snuke"
Returns: "Impossible"
Erasing nothing is not allowed.
3)

    
"snukent"
"snuke"
Returns: "Impossible"
Cat Snuke can erase exactly one character.
4)

    
"aaaaa"
"aaaa"
Returns: "Possible"

5)

    
"aaaaa"
"aaa"
Returns: "Impossible"

6)

    
"topcoder"
"tpcoder"
Returns: "Possible"

7)

    
"singleroundmatch"
"singeroundmatc"
Returns: "Impossible"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class DecipherabilityEasy{
public:
	string check(string s, string t){
		int m = s.size();
		int n = t.size();
		if(n+1!=m) return "Impossible";
		int i=0,j=0;
		while(j<n&&s[i]==t[j]){i++;j++;}
		if(j==n) return "Possible";
		i++;
		while(j<n&&s[i]==t[j]){i++;j++;}
		if(j<n) return "Impossible";
		return "Possible";
	}
};
