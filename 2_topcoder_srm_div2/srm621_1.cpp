/*
 Problem Statement
     
 Sasha has a vector <string> stringList. No two elements of stringList have the same length.
  
 So far, Sasha has learned two ways of sorting strings:
 He can sort strings lexicographically. For example, "car" < "carriage" < "cats" < "doggies". (See Notes for a definition of the lexicographic order.)
 He can also sort strings according to their lengths in ascending order. For example, "car" < "cats" < "doggies" < "carriage".
 Sasha now wonders whether stringList is sorted in either of these two ways. Return "lexicographically" (quotes for clarity) if stringList is sorted lexicographically but not according to the string lengths. Return "lengths" if stringList is sorted according to the string lengths but not lexicographically. Return "both" if it is sorted in both ways. Otherwise, return "none".
 Definition
     
Class:
TwoWaysSorting
Method:
sortingMethod
Parameters:
vector <string>
Returns:
string
Method signature:
string sortingMethod(vector <string> stringList)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
String A is lexicographically smaller than string B if A contains a character with a smaller ASCII value in the first position where they differ. In case one of the strings ends before they have a different character, the shorter one is considered smaller.
Constraints
-
stringList will contain between 1 and 50 elements, inclusive.
-
Each element of stringList will contain between 1 and 50 characters, inclusive.
-
Each character of each element of stringList will be a lowercase English letter ('a'-'z').
-
Every two elements of stringList will have different lengths.
Examples
0)

    
{"a", "aa", "bbb"}
Returns: "both"
These strings are sorted both lexicographically and according to their lengths.
1)

    
{"c", "bb", "aaa"}
Returns: "lengths"
The lengths of these strings are in ascending order. However, they are not sorted lexicographically as, for instance, "aaa" is lexicographically smaller than "c".
2)

    
{"etdfgfh", "aio"}
Returns: "none"
Here the first string is longer than the second one, so they are not sorted according to length. (Note that we require the lengths to be in ascending order.) Similarly, they are not sorted lexicographically: "aio" should come before "etdfgfh".
3)

    
{"aaa", "z"}
Returns: "lexicographically"
The input strings are sorted lexicographically only.
4)

    
{"z"}
Returns: "both"

5)

    
{"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"}
Returns: "lexicographically"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
using namespace std;

class TwoWaysSorting{
public:
	string sortingMethod(vector <string> stringList);
};

string TwoWaysSorting::sortingMethod(vector <string> stringList){
	bool lex=true,len=true;
	int n = stringList.size();
	for(int i=1;i<n;++i){
		if(len&&stringList[i].size()<stringList[i-1].size()) len = false;
		if(lex&&stringList[i]<stringList[i-1]) lex = false;
	}
	if(len&&lex) return "both";
	if(len) return "lengths";
	if(lex) return "lexicographically";
	return "none";
}
