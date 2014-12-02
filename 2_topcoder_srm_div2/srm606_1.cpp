/*
Problem Statement
    
Elly has a string S of uppercase letters and a magic device that can modify the string. The strength of the device is an int L.  The device does the following: The user enters a 0-based index i such that 0 <= i <= length(S)-L. The device then takes L letters of S, starting at index i, and puts these letters into alphabetical order. Formally, the letters that get reordered are the letters S[i], S[i+1], and so on, until and including S[i+L-1].  For example, let S="TOPCODER" and let L=4. If the user chooses i=0, the selected substring will be "TOPC". These letters are rearranged into alphabetical order ("COPT") while the rest of the string remains unchanged ("....ODER"). Thus, the result would be the string "COPTODER". If the user were to choose i=2 instead, the resulting string would be "TOCDOPER". Here, "TO....ER" was left unchanged, and "PCOD" was changed into "CDOP".  Elly's magic device has a flaw: it can only be used once and then it self-destructs. You are given the string S and the int L described above. Return the lexicographically smallest string Elly can create by using the device exactly once.
Definition
    
Class:
EllysSubstringSorter
Method:
getMin
Parameters:
string, int
Returns:
string
Method signature:
string getMin(string S, int L)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
A string S1 is lexicographically smaller than a string S2 if S1 contains a smaller character than S2 at the first index where they differ.
Constraints
-
L will be between 2 and 50, inclusive.
-
S will contain between L and 50 characters, inclusive.
-
Each character of S will be an uppercase letter of the English alphabet ('A'-'Z').
Examples
0)

    
"TOPCODER"
4
Returns: "COPTODER"
The best we can do here is to sort the first 4 characters of the string.
1)

    
"ESPRIT"
3
Returns: "EPRSIT"
The best solution is obtained by choosing i=1, i.e., by sorting the letters in the substring "SPR".
2)

    
"AAAAAAAAA"
2
Returns: "AAAAAAAAA"
Sometimes sorting doesn't do anything.
3)

    
"ABRACADABRA"
5
Returns: "AAABCRDABRA"

4)

    
"BAZINGA"
6
Returns: "ABGINZA"

5)

    
"AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
21
Returns: "AAAAAABDDDEEIIIJOOSUWWWWDBPOAWDUISAWDOOPAWD"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class EllysSubstringSorter{
public:
	string getMin(string S, int L){
		int n = S.size();
		if(n<=L){
			string res = S;
			sort(res.begin(),res.end());
			return res;
		}
		vector<string> result;
		for(int i=0;i<=(n-L);++i){
			string res = S;
			sort(res.begin()+i,res.begin()+i+L);
			result.push_back(res);
		}
		sort(result.begin(),result.end());
		return result[0];
	}
};
