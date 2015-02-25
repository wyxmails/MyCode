/*

Problem Statement
    
Fox Ciel received a string as a birthday present. However, the string was too long for her, so she decided to make it shorter by erasing some characters.  The erasing process will look as follows:
Find the smallest i such that the i-th character and the (i+1)-th character of the string are same.
If there is no such i, end the process.
Remove the i-th and the (i+1)-th character of the string, and repeat from 1.
  For example, if she receives "cieeilll", she will change the string as follows: "cieeilll" -> "ciilll" -> "clll" -> "cl". You are given a string s. Return the string she will get after she erases characters as described above.
Definition
    
Class:
ErasingCharacters
Method:
simulate
Parameters:
string
Returns:
string
Method signature:
string simulate(string s)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
s will contain between 1 and 50 characters, inclusive.
-
Each character in s will be a lowercase letter ('a'-'z').
Examples
0)

    
"cieeilll"
Returns: "cl"
This is the example from the statement.
1)

    
"topcoder"
Returns: "topcoder"
She won't erase any characters at all.
2)

    
"abcdefghijklmnopqrstuvwxyyxwvutsrqponmlkjihgfedcba"
Returns: ""

3)

    
"bacaabaccbaaccabbcabbacabcbba"
Returns: "bacbaca"

4)

    
"eel"
Returns: "l"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class ErasingCharacters{
public:
/*	string simulate(string s){
		bool found = true;
		string res = s;
		while(found&&res.size()>1){
			int n = res.size();
			found = false;
			int i=0;
			for(;i+1<n;++i)
				if(res[i]==res[i+1]){
					found = true;
					break;
				}
			if(found)
				res = res.substr(0,i)+res.substr(i+2);
		}
		return res;
	}*/
	string simulate(string s){
		stack<int> ms;
		int n = s.size();
		if(n<=1) return s;
		for(int i=0;i<n;++i){
			if(ms.empty()||s[i]!=s[ms.top()]) ms.push(i);
			else ms.pop();
		}
		string res = "";
		while(!ms.empty()){
			res = s[ms.top()]+res;
			ms.pop();
		}
		return res;
	}
};
