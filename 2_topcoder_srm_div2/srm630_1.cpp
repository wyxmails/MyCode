/*
 Problem Statement
     
 You are given a string S. You can modify this string by repeating the following process:
 Find the leftmost occurrence of two consecutive letters in S that are the same.
 If you found a pair of identical letters in the first step, delete those two letters from S.
 For example, if S="aabccb", you can proceed as follows:
 Find and erase "aa", producing the string "bccb".
 Find and erase "cc", producing the string "bb".
 Find and erase "bb", producing the empty string.
 For S="axxyybac" you can do at most two steps, erasing "xx" first and "yy" next. Once you obtain the string "abac", you are done. Note that you cannot erase the two "a"s because they are not consecutive. You want to change S into an empty string by repeating the operation described above. Return "Possible" if you can do that, and "Impossible" otherwise.
 Definition
     
Class:
DoubleLetter
Method:
ableToSolve
Parameters:
string
Returns:
string
Method signature:
string ableToSolve(string S)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
S will contain between 1 and 50 characters.
-
Each character in S will be a lowercase English letter ('a'-'z').
Examples
0)

    
"aabccb"
Returns: "Possible"

1)

    
"aabccbb"
Returns: "Impossible"
The process will terminate with a single 'b'.
2)

    
"abcddcba"
Returns: "Possible"
"abcddcba" -> "abccba" -> "abba" -> "aa" -> "".
3)

    
"abab"
Returns: "Impossible"
No two successive letters are the same, so we can't do any operation.
4)

    
"aaaaaaaaaa"
Returns: "Possible"

5)

    
"aababbabbaba"
Returns: "Impossible"

6)

    
"zzxzxxzxxzzx"
Returns: "Possible"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <stack>
using namespace std;

class DoubleLetter{
public:
	string ableToSolve(string S);
};
string DoubleLetter::ableToSolve(string S){
	string res_pos = "Possible";
	string res_impos = "Impossible";
	int n = S.size();
	if(n%2) return res_impos;
	stack<char> mark;
	for(int i=0;i<n;i++){
		if(mark.empty()||S[i]!=mark.top()) mark.push(S[i]);
		else mark.pop();
	}
	if(mark.empty()) return res_pos;
	else return res_impos;
}
