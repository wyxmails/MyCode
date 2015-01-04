/*

Problem Statement
    
We can think of a cyclic word as a word written in a circle. To represent a cyclic word, we choose an arbitrary starting position and read the characters in clockwise order. So, "picture" and "turepic" are representations for the same cyclic word.  You are given a vector <string> words, each element of which is a representation of a cyclic word. Return the number of different cyclic words that are represented.  
Definition
    
Class:
CyclicWords
Method:
differentCW
Parameters:
vector <string>
Returns:
int
Method signature:
int differentCW(vector <string> words)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
words will contain between 1 and 50 elements, inclusive.
-
Each element of words will contain between 1 and 50 lowercase letters ('a'-'z'), inclusive.
Examples
0)

    
{ "picture", "turepic", "icturep", "word", "ordw" }
Returns: 2
"picture", "turepic" and "iceturep" are representations of the same cyclic word. "word" and "ordw" are representations of a second cyclic word.
1)

    
{ "ast", "ats", "tas", "tsa", "sat", "sta", "ttt" }
Returns: 3

2)

    
{"aaaa", "aaa", "aa", "aaaa", "aaaaa"}
Returns: 4

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class CyclicWords{
public:
	int differentCW(vector <string> words){
		int n = words.size();
		vector<string> res;
		res.push_back(words[0]);
		for(int i=1;i<n;++i){
			bool found = false;
			string tmp = words[i]+words[i];
			for(int j=0;j<res.size();++j){
				if(res[j].size()*2!=tmp.size()) continue;
				if(tmp.find(res[j])!=string::npos){
					found = true;
					break;
				}
			}
			if(!found) res.push_back(words[i]);
		}
		return res.size();
	}
};
