/*

Problem Statement
    
In this problem we are dealing with strings of lowercase English letters. When comparing our strings, we are using the standard lexicographic order. For example, "cat" < "do" < "dog" < "done". (See Notes for a formal definition.)  Suppose that L is a list of strings and that S is one of those strings. The position of S in L is the 0-based index of the first occurrence of S after L is sorted lexicographically. (Equivalently, the position of S in L can be defined as the number of strings in L that are strictly smaller than S.)  For example, for the list L = {"abc", "bcd", "cde", "cdf", "bbc"}, the corresponding positions would be {0, 2, 3, 4, 1}. For the list L = {"a", "a", "b", "b", "c", "c"} the positions would be {0, 0, 2, 2, 4, 4}.  Wolf Sothe has found an old list of strings. Some characters in the list were damaged beyond recognition. You are given the list as a vector <string> str. In str, the damaged characters are represented by the character '?' (question mark).  Return a vector <int> with as many elements as str. For each valid i, the i-th element of the return value should be the smallest possible position of the i-th element of Sothe's list.
Definition
    
Class:
LostCharacter
Method:
getmins
Parameters:
vector <string>
Returns:
vector <int>
Method signature:
vector <int> getmins(vector <string> str)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Notes
-
Given two strings A and B, we say that A is smaller than B if either A is a proper prefix of B, or there is a non-negative integer i such that A[i]<B[i] and for all j<i we have A[j]=B[j].
Constraints
-
str will contain between 1 and 50 elements, inclusive.
-
Each element in str will contain between 1 and 50 characters, inclusive.
-
Each character in str will be either a lowercase English letter ('a'-'z'), or '?'.
Examples
0)

    
{"abc","bcd","cde","cdf","bbc"}
Returns: {0, 2, 3, 4, 1 }
This is the first example from the problem statement. As there are no damaged letters, there is only one possible lexicographical order and you should return the corresponding positions.
1)

    
{"?ala","ara","baba"}
Returns: {0, 0, 1 }
In this test case we have one damaged character. If the damaged character was an 'a', the positions were {0,1,2}. Otherwise, the positions were {2,0,1}. Hence, the smallest possible position of "?ala" is 0, the smallest possible position of "ara" is 0, and the smallest possible position of "baba" is 1.
2)

    
{"a?","a","a","ab","aa"}
Returns: {2, 0, 0, 3, 2 }
Sothe's list may contain duplicates.
3)

    
{"s?nu?ke","sm??eke","?sna?ke","so?th?e","shake??"}
Returns: {0, 1, 0, 2, 0 }

4)

    
{"?","z?","zz?","zzz?","zzzz?","zzzzz?","zzzzzz?"}
Returns: {0, 1, 2, 3, 4, 5, 6 }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class LostCharacter{
public:
	vector <int> getmins(vector <string> str){
		int n = str.size();
		vector<int> res(n,0);
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(j==i) continue;
				bool less=false;
				int k;
				for(k=0;k<str[i].size();++k){
					if(k>=str[j].size()) {less = true; break;}
					if(str[j][k]=='?'){
						if(str[i][k]=='z') continue;
						break;
					}
					if(str[i][k]=='?'){
						if(str[j][k]=='a') continue;
						break;
					}
					if(str[j][k]<str[i][k]){less = true;break;}
					if(str[i][k]<str[j][k]) break;
				}
				if(less) res[i]++;
			}
		}
		return res;
	}
};
