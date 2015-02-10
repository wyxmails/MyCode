/*

Problem Statement
    
You have a string s that contains at least K characters. Cat Snuke will remove exactly K characters from the string. Afterwards, Snuke will show you the new string and you have to guess the original indices of all removed characters. You win the game if you guess all of them correctly.  For example, suppose that s="snuke" and K=2. Snuke removed two characters and showed you the string "nue". In this situation you can easily deduce that Snuke must have removed the characters s[0] and s[3]. You announce that the indices of removed characters are 0 and 3, and you win the game.  You are given the string s and the int K. Return "Certain" (quotes for clarity) if you can always be sure to win the game, regardless of which characters Snuke removes. Otherwise, return "Uncertain". Note that the return value is case-sensitive.
Definition
    
Class:
Decipherability
Method:
check
Parameters:
string, int
Returns:
string
Method signature:
string check(string s, int K)
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
K will be between 1 and 50, inclusive.
-
The length of s will be between K and 50, inclusive.
-
Every character in s will be a lowercase letter ('a'-'z').
Examples
0)

    
"snuke"
2
Returns: "Certain"
This is the example from the problem statement. As all characters are unique, you can always determine the indices of the erased ones.
1)

    
"aba"
1
Returns: "Certain"
Snuke will show you one of the strings "ba", "aa", and "ab". In the first case you can be sure that he erased the character at index 0. The second and the third string correspond to indices 1 and 2, respectively.
2)

    
"aba"
2
Returns: "Uncertain"
If Snuke shows you the string "a", there are two possibilities: either he erased the characters at indices 0 and 1, or the characters at indices 1 and 2.
3)

    
"abcdabcd"
3
Returns: "Certain"

4)

    
"koukyoukoukokukikou"
2
Returns: "Uncertain"

5)

    
"wolfsothe"
8
Returns: "Uncertain"

6)

    
"aa"
2
Returns: "Certain"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Decipherability{
public:
	string check(string s, int K){
		unordered_set<string> mark;
		int n = s.size();
		if(n==K||K==0) return "Certain";
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n&&j<=i+K;++j)
				if(s[i]==s[j]) return "Uncertain";
		}
		return "Certain";
	}
};
