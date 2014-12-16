/*
Problem Statement
    
Cat Taro has a string S. He wants to obtain the string "CAT" from the string S. In a single turn he can choose any character and erase all occurrences of this character in S. He can do as many turns as he wants (possibly zero).

You are given the string S. Return "Possible" (quotes for clarity) if it is possible to obtain the string "CAT" and "Impossible" otherwise.
Definition
    
Class:
TaroString
Method:
getAnswer
Parameters:
string
Returns:
string
Method signature:
string getAnswer(string S)
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
S will contain only uppercase English letters ('A'-'Z').
Examples
0)

    
"XCYAZTX"
Returns: "Possible"
It is possible to obtain string "CAT" in three turns, as follows:
Erase all characters 'X' (and obtain the string "CYAZT")
Erase all characters 'Y' (and obtain the string "CAZT")
Erase all characters 'Z' (and obtain the string "CAT")
1)

    
"CTA"
Returns: "Impossible"

2)

    
"ACBBAT"
Returns: "Impossible"
Note that whenever you are erasing a character, you must erase all its occurrences. In this case, it is not possible to erase the first 'A' and keep the second one.
3)

    
"SGHDJHFIOPUFUHCHIOJBHAUINUIT"
Returns: "Possible"

4)

    
"CCCATT"
Returns: "Impossible"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

class TaroString{
public:
	string getAnswer(string S){
		string res = "";
		for(int i=0;i<S.size();++i){
			if(S[i]=='A'||S[i]=='C'||S[i]=='T')
				res += S[i];
		}
		if(res.size()>3||res!="CAT") return "Impossible";
		return "Possible";
	}
};
