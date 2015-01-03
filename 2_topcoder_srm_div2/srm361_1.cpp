/*

Problem Statement
    
You are writing a simple text editor, and one of the features you need to implement is a text search. Given a pattern, the search mechanism should return the position of its first occurrence, starting from the current position, or indicate that the pattern cannot be found. Searches are case sensitive, and do not wrap. The search dialog contains a text box and a checkbox labeled "Whole Word". When the "Whole Word" option is selected, the matched sequence must either be preceded by a space to its left or be at the very beginning of the text. Similarly, it must also either be followed by a space to its right or be at the very end of the text.
You are given a string text consisting of letters and spaces. You are also given a string search, a sequence of letters representing the search pattern, and a string wholeWord, which is either "Y" or "N", indicating whether or not the "Whole Word" option is checked. An int start represents the current position in the text from where you start searching. Return the index of the first match, or -1 if there is none. The index of the match here means the index of its first character. Both the starting index and the return index are zero based.
Definition
    
Class:
SearchBox
Method:
find
Parameters:
string, string, string, int
Returns:
int
Method signature:
int find(string text, string search, string wholeWord, int start)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
text will contain between 1 and 50 characters, inclusive.
-
text will contain only letters ('a'-'z', 'A'-'Z') and spaces.
-
search will contain between 1 and 50 characters, inclusive.
-
search will contain only letters ('a'-'z', 'A'-'Z').
-
wholeWord will contain a single letter 'Y' or 'N'.
-
start will be between 0 and N-1, inclusive, where N is the number of characters in text.
Examples
0)

    
"We dont need no education"
"ed"
"N"
13
Returns: 16
The whole text has two occurrences of "ed", but since we start the search at the 13th character we find the second one.
1)

    
"We dont need no thought control"
"We"
"Y"
0
Returns: 0
"We" is exactly at the beginning of the text.
2)

    
"No dark sarcasm in the classroom"
"The"
"Y"
5
Returns: -1
Remember that the search is case sensitive.
3)

    
"Teachers leave them kids alone"
"kid"
"Y"
1
Returns: -1
With the "Whole Word" option selected the "kid" won't be matched even though it's present in "kids".
4)

    
"All in all its just another brick in the wall"
"all"
"Y"
9
Returns: -1

5)

    
"All in all youre just another brick in the wall"
"just"
"Y"
17
Returns: 17

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

class SearchBox{
public:
	int find(string text, string search, string wholeWord, int start){
		int n = text.size();
		int m = search.size();
		for(int i=start;i<n;++i){
			if(wholeWord=="Y"){
				if(text[i]==search[0]&&(i==0||text[i-1]==' ')){
					int j=0;
					while(j<m&&i+j<n){
						if(text[i+j]!=search[j]) break;
						j++;
					}
					if(j==m&&(i+j==n||text[i+j]==' ')) return i;
				}
			}else{
				if(text[i]==search[0]){
					int j=0;
					while(j<m&&i+j<n){
						if(text[i+j]!=search[j]) break;
						j++;
					}
					if(j==m) return i;
				}
			}
		}
		return -1;
	}
};
