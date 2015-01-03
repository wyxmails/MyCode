/*

Problem Statement
    
Some languages allow the use of compound words, words that are the concatenation of words from the language's dictionary.
We have defined a language that consists of a dictionary of distinct words. We want to know whether we should allow the use of compound words constructed by concatenating exactly two distinct dictionary words. The potential problem is that a compound word is ambiguous if either (or both) of the following conditions applies:
the compound word is a dictionary word
the compound word can be formed in more than one way.
For example, if "am","eat","a", "meat", "hook", and "meathook" were all in the dictionary, then "meathook" would be ambiguous according to the first condition, and "ameat" would be ambiguous according to the second condition.
Create a class CmpdWords that contains a method ambiguous that is given a vector <string> dictionary and that returns the number of ambiguous words that would result from allowing the compounding of distinct pairs of dictionary words. An ambiguous word should be counted only once, no matter how many different ways it could be formed.
Note that compound words are NOT added to the dictionary. So the dictionary {"a", "b","c"} does not allow "abc" as a compound word.
Definition
    
Class:
CmpdWords
Method:
ambiguous
Parameters:
vector <string>
Returns:
int
Method signature:
int ambiguous(vector <string> dictionary)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
dictionary will contain between 1 and 50 elements inclusive.
-
The elements of dictionary will be distinct.
-
Each element of dictionary will contain between 1 and 20 characters inclusive.
-
Each character in each element of dictionary will be a lowercase letter 'a'-'z'.
Examples
0)

    
{"am","eat","a", "meat", "hook","meathook"}
Returns: 2
"meathook" and "ameat" are ambiguous as explained above.
1)

    
{"a","b","c"}
Returns: 0
All the compound words are: "ab","ac","bc","ba","ca","cb" and none of these is ambiguous.
2)

    
{"a","aa","aaa"}
Returns: 3
The ambiguous words are "aaa": ("a"+"aa" and "aa"+"a" and "aaa") "aaaa": ("a"+"aaa" and "aaa"+"a") "aaaaa": ("aa"+"aaa" and "aaa"+"aa")
3)

    
{"abc","bca","bab","a"}
Returns: 1
"abc"+"a" = "a"+"bca"
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<string> res;

struct Trie{
	char c;
	int child;
	int words;
	Trie* children[26];
	Trie(char c,int child,int words):c(c),child(child),words(words){
		for(int i=0;i<26;++i)
			children[i] = NULL;
	}
};

class CmpdWords{
public:
	int ambiguous(vector <string> dic){
		int n = dic.size();
		Trie *root = new Trie(' ',0,0);
		for(int i=0;i<n;++i){
			addWord(root,dic[i],0);
			for(int j=i+1;j<n;++j){
				addWord(root,dic[i]+dic[j],0);
				addWord(root,dic[j]+dic[i],0);
			}
		}
		return res.size();
	}
	void addWord(Trie*root,const string &word,int index){
		if(index>=word.size()){
			root->words++;
			if(root->words>1) res.insert(word);
			return;
		}
		char c = word[index];
		if(root->children[c-'a']==NULL){
			root->children[c-'a'] = new Trie(c,0,0);
		}
		addWord(root->children[c-'a'],word,index+1);
	}
};
