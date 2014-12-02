/*
Problem Statement
    
Suffix number i of a string S is the suffix that starts with the character S[i]. For example, for S="abcde" suffix 0 is "abcde" and suffix 3 is "de".  The suffix array of a string S is defined as the permutation of suffix numbers that corresponds to their lexicographic order. For example, suppose that S="abca". If we order all suffixes of S lexicographically, we get the following: "a" < "abca" < "bca" < "ca". The corresponding suffix numbers are 3, 0, 1, and 2, in this order. Thus, for this string S the suffix array would be {3, 0, 1, 2}. Note that the length of a suffix array is the same as the length of the original string.  In this problem, we will only consider strings of lowercase English letters ('a'-'z'). You are given a string s. We are interested in a string t that is lexicographically smaller than s but has exactly the same suffix array. Return "Exists" if at least one such string t exists, and "Does not exist" otherwise.
Definition
    
Class:
SuffixArrayDiv2
Method:
smallerOne
Parameters:
string
Returns:
string
Method signature:
string smallerOne(string s)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
Given two different strings A and B of the same length, A is lexicographically smaller than B if we have A[i] < B[i] for the smallest i such that A[i] and B[i] differ.
Constraints
-
s will contain between 1 and 50 elements, inclusive.
-
Each element in s will be a lowercase letter ('a'-'z').
Examples
0)

    
"abca"
Returns: "Exists"
For example, "aaqa" < "abca" but their suffix arrays are the same.
1)

    
"bbbb"
Returns: "Exists"
Obviously, one of the strings smaller than "bbbb" with the same suffix array is "aaaa".
2)

    
"aaaa"
Returns: "Does not exist"
The string "aaaa" is already the lexicographically smallest 4-letter string.
3)

    
"examplesareveryweakthinktwicebeforesubmit"
Returns: "Exists"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class SuffixArrayDiv2{
public:
	string smallerOne(string s){
		vector<int> vec = count(s);
		for(int i=0;i<s.size();++i){
			if(s[i]=='a') continue;
			string tmp = s;
			tmp[i] -=1;
			vector<int> vec1 = count(tmp);
			if(vec==vec1) return "Exists";
		}
		return "Does not exist";
	}
	vector<int> count(const string&s){
		map<string,int> mark;
		int n = s.size();
		for(int i=0;i<n;++i){
			mark[s.substr(i)] = i;
		}
		vector<int> res;
		for(auto it = mark.begin();it!=mark.end();++it)
			res.push_back(it->second);
		return res;
	}
};
