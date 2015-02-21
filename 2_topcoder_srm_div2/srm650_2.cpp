/*

Problem Statement
    
Cat Taro likes strings. You are given a string S. Each character of S is 'A', 'B', or '?'.

To Taro, the ugliness of a string is the number of pairs of equal consecutive characters. For example, the ugliness of "ABABAABBB" is 3: there is one pair "AA" and two (overlapping) pairs "BB".

Taro now wants to change each question mark in S either to 'A' or to 'B'. His goal is to minimize the ugliness of the resulting string. Return the smallest ugliness that can be achieved.
Definition
    
Class:
TaroFillingAStringDiv2
Method:
getNumber
Parameters:
string
Returns:
int
Method signature:
int getNumber(string S)
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
S will contain between 1 and 50 characters, inclusive.
-
S will consist only of characters 'A', 'B' and '?'.
Examples
0)

    
"ABAA"
Returns: 1
There is initially one pair of consecutive digits that are equal in this case. There is no characters that Taro has to replace, hence the answer is 1.
1)

    
"??"
Returns: 0

2)

    
"A?A"
Returns: 0

3)

    
"A??B???AAB?A???A"
Returns: 3

4)

    
"?BB?BAAB???BAB?B?AAAA?ABBA????A?AAB?BBA?A?"
Returns: 10

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class TaroFillingAStringDiv2{
public:
	int getNumber(string S){
		string str = "";
		int n = S.size();
		for(int i=0;i<n;){
			if(S[i]=='?'){
				int j = i;
				while(S[j]=='?') j++;
				if((j-i)%2) str += "?";
				else str += "??";
				i = j;
			}else str += S[i++];
		}
		n = str.size();
		if(n<=1) return 0;
		int res = 0;
		for(int i=0;i<n;++i){
			if(str[i]=='?'){
				if(i>0){
					if(str[i-1]=='A') str[i] = 'B';
					if(str[i-1]=='B') str[i] = 'A';
				}else{
					if(str[i+1]=='A') str[i] = 'B';
					else if(str[i+1]=='B') str[i] = 'A';
					else{
						if(i+2<n) str[i] = str[i+2];
						else str[i] = 'A';
					}
				}
			}
		}
		for(int i=1;i<n;++i)
			if(str[i]==str[i-1]) res++;
		return res;
	}
};
