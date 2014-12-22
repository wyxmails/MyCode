/*

Problem Statement
    
One day, Fox Ciel looked at the words "tokyo" and "kyoto" and noticed an unusual property: We can split "tokyo" into "to"+"kyo", and then swap those two parts to obtain "kyo"+"to" = "kyoto".  Formally, let S and T be two different strings. We call the pair (S,T) interesting if there are two non-empty strings A and B such that S = A+B and T = B+A. For example, according to this definition, if S="tokyo" and T="kyoto", then the pair (S,T) is interesting, because we can find A="to" and B="kyo".  You are given a vector <string> words. Return the number of interesting pairs we can find among the elements of words. Only count each pair once. E.g., ("tokyo","kyoto") and ("kyoto","tokyo") is the same interesting pair.
Definition
    
Class:
FoxAndWord
Method:
howManyPairs
Parameters:
vector <string>
Returns:
int
Method signature:
int howManyPairs(vector <string> words)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
words will contain between 2 and 50 elements, inclusive.
-
Each element of words will contain between 1 and 50 characters, inclusive.
-
Each character in each element of words will be a lowercase letter ('a'-'z').
-
All the elements in words will be pairwise distinct.
Examples
0)

    
{"tokyo", "kyoto"}
Returns: 1
As mentioned in the problem statement, ("tokyo", "kyoto") is an interesting pair.
1)

    
{"aaaaa", "bbbbb"}
Returns: 0
("aaaaa", "bbbbb") is not an interesting pair.
2)

    
{"ababab","bababa","aaabbb"}
Returns: 1
There is one interesting pair: ("ababab","bababa"). Note that for this interesting pair there is more than one way to choose the strings A and B.
3)

    
{"eel", "ele", "lee"}
Returns: 3

4)

    
{"aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"}
Returns: 6

5)

    
{"top","coder"}
Returns: 0
Different elements of words may have different lengths.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class FoxAndWord{
public:
	int howManyPairs(vector <string> words){
		int n = words.size();
		int res = 0;
		for(int i=0;i+1<n;++i)
		for(int j=i+1;j<n;++j)
		if(words[i].size()==words[j].size()){
			int m = words[i].size();
			for(int k=0;k<m;++k){
				if(words[i].substr(0,k)==words[j].substr(m-k)&&
					words[i].substr(k)==words[j].substr(0,m-k)){
					res++;
					break;
				}
			}
		}
		return res;
	}
};
