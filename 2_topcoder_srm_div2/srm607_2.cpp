/*

Problem Statement
    
Marco recently learned about palindromic strings. A palindromic string is a string that reads the same forwards and backwards. For example, "radar" and "racecar" are palindromic strings.
 
Now Marco is excited about palindromic strings. In particular, he likes strings that have a lot of palindromic substrings. For example, he really likes the string "aaa" because it has 6 palindromic substrings: "a" occurs three times, "aa" occurs twice, and "aaa" occurs once.
 
Right now, Marco has a string S composed of lowercase letters. You are to reconstruct S from the given vector <string>s S1 and S2 as follows:
Concatenate in order all elements of S1 to make a string A.
Concatenate in order all elements of S2 to make a string B.
Finally, concatenate A and B to get S.
 
Return the number of palindromic substrings in S.
Definition
    
Class:
PalindromicSubstringsDiv2
Method:
count
Parameters:
vector <string>, vector <string>
Returns:
int
Method signature:
int count(vector <string> S1, vector <string> S2)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
S1 and S2 will each contain no more than 50 elements.
-
Each element of S1 and S2 will contain no more than 50 characters.
-
S will contain at least 1 character.
-
S will contain only lowercase letters ('a' - 'z').
Examples
0)

    
{"a","a",""}
{"a"}
Returns: 6
This is the example given in the statement, "aaa".
1)

    
{"zaz"}
{}
Returns: 4

2)

    
{"top"}
{"coder"}
Returns: 8

3)

    
{}
{"daata"}
Returns: 7
There are five palindromic substrings of length 1, one of length 2 ("aa" starting at index 1), and one of length 3 ("ata" starting at index 2).
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class PalindromicSubstringsDiv2{
public:
	int count(vector <string> S1, vector <string> S2){
		string str = "";
		for(int i=0;i<S1.size();++i) str += S1[i];
		for(int i=0;i<S2.size();++i) str += S2[i];
		int n = str.size();
		vector<vector<bool> > mark(n,vector<bool>(n,false));
		for(int i=n-1;i>=0;--i){
			for(int j=n-1;j>=i;--j){
				if(str[i]==str[j]&&(j-i<=2||mark[i+1][j-1])){
					mark[i][j] = true;
				}
			}
		}
		int res = 0;
		for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		if(mark[i][j]) res++;
		return res;
	}
};
