/*
 Problem Statement
     
 Fox Ciel likes all the words that have the following properties:
 Each letter of the word is an uppercase English letter.
 Equal letters are never consecutive.
 There is no subsequence of the form xyxy, where x and y are (not necessarily distinct) letters. Note that a subsequence doesn't have to be contiguous.
Examples:
Ciel does not like "ABBA" because there are two consecutive 'B's.
Ciel does not like "THETOPCODER" because it contains the subsequence "TETE".
Ciel does not like "ABACADA" because it contains the subsequence "AAAA". (Note that here x=y='A'.)
Ciel likes "A", "ABA", and also "ABCBA".
Given a string word, return "Likes" (quotes for clarity) if Ciel likes word and "Dislikes" if she does not.
Definition
    
Class:
LongWordsDiv2
Method:
find
Parameters:
string
Returns:
string
Method signature:
string find(string word)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
word will contain between 1 and 100 characters, inclusive.
-
Each character of word will be an uppercase English letter ('A'-'Z').
Examples
0)

    
"AAA"
Returns: "Dislikes"

1)

    
"ABCBA"
Returns: "Likes"

2)

    
"ABCBAC"
Returns: "Dislikes"

3)

    
"TOPCODER"
Returns: "Likes"

4)

    
"VAMOSGIMNASIA"
Returns: "Dislikes"

5)

    
"SINGLEROUNDMATCH"
Returns: "Likes"

6)

    
"DALELOBO"
Returns: "Likes"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
using namespace std;

class LongWordsDiv2{
public:
	string find(string word);
	string find2(string word);
};

string LongWordsDiv2::find(string word){
	vector<vector<int> > mark(26);
	string like = "Likes";
	string dislike = "Dislikes";
	int n = word.size();
	for(int i=0;i<n;++i){
		if(i+1<n&&word[i]==word[i+1]) return dislike;
		for(int j=i+1;j<n-2;++j){
			for(int k=j+1;k<n-1;++k){
				for(int m = k+1;m<n;++m){
					if(word[m]==word[m-1]) return dislike;
					if(word[i]==word[k]&&word[j]==word[m])
						return dislike;
				}
			}
		}
	}
	return like;
}

string LongWordsDiv2::find2(string word){
	vector<vector<int> > mark(26);
	string like = "Likes";
	string dislike = "Dislikes";
	int n = word.size();
	for(int i=0;i<n;++i){
		if(i+1<n&&word[i]==word[i+1]) return dislike;
		for(int j=i+1;j<n-1;++j){
			bool a_found = false;
			for(int k=j+1;k<n;++k){
				if(!a_found){
					if(word[k]==word[i]) a_found = true;
				}else{
					if(word[k]==word[j]) return dislike;
				}
			}
		}
	}
	return like;
}
