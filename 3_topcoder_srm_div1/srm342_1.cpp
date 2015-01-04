/*

Problem Statement
    
In the first half of the 20th century, around the time that Tagalog became the national language of the Philippines, a standardized alphabet was introduced to be used in Tagalog school books (since then, the national language has changed to a hybrid "Pilipino" language, as Tagalog is only one of several major languages spoken in the Philippines).
Tagalog's 20-letter alphabet is as follows:
a b k d e g h i l m n ng o p r s t u w y
Note that not all letters used in English are present, 'k' is the third letter, and 'ng' is a single letter that comes between 'n' and 'o'.
You are compiling a Tagalog dictionary, and for people to be able to find words in it, the words need to be sorted in alphabetical order with reference to the Tagalog alphabet. Given a list of Tagalog words as a vector <string>, return the same list in Tagalog alphabetical order.
Definition
    
Class:
TagalogDictionary
Method:
sortWords
Parameters:
vector <string>
Returns:
vector <string>
Method signature:
vector <string> sortWords(vector <string> words)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
Any 'n' followed followed by a 'g' should be considered a single 'ng' letter (the one that comes between 'n' and 'o').
Constraints
-
words will contain between 1 and 50 elements, inclusive.
-
Each element of words will contain between 1 and 50 characters, inclusive.
-
Each character of each element of words will be a valid lowercase letter that appears in the Tagalog alphabet.
-
Each element of words will be distinct.
Examples
0)

    
{"abakada","alpabet","tagalog","ako"}
Returns: {"abakada", "ako", "alpabet", "tagalog" }
The tagalog word for "alphabet", a Tagalogization of the English word "alphabet", the name of the language, and the word for "I".
1)

    
{"ang","ano","anim","alak","alam","alab"}
Returns: {"alab", "alak", "alam", "anim", "ano", "ang" }
A few "A" words that are alphabetically close together.
2)

    
{"siya","niya","kaniya","ikaw","ito","iyon"}
Returns: {"kaniya", "ikaw", "ito", "iyon", "niya", "siya" }
Common Tagalog pronouns.
3)

    
{"kaba","baka","naba","ngipin","nipin"}
Returns: {"baka", "kaba", "naba", "nipin", "ngipin" }

4)

    
{"knilngiggnngginggn","ingkigningg","kingkong","dingdong","dindong","dingdont","ingkblot"}
Returns: 
{"kingkong",
 "knilngiggnngginggn",
 "dindong",
 "dingdont",
 "dingdong",
 "ingkblot",
 "ingkigningg" }

5)

    
{"silangang", "baka", "bada", "silang"}
Returns: {"baka", "bada", "silang", "silangang" }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<string> vec;
bool cmp(int a,int b){
	return vec[a]<vec[b];
}
class TagalogDictionary{
public:
	vector <string> sortWords(vector <string> words){
		char arr[] = {'a','b','k','d','e','g','h','i','l','m','n','o','p','r','s','t','u','w','y'};
		unordered_map<char,char> mark;
		for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i){
			int t = i;
			if(t>=11) t++;
			mark[arr[i]] = char('a'+t);
		}
		vector<int> index;
		for(int i=0;i<words.size();++i){
			string tmp = "";
			for(int j=0;j<words[i].size();++j){
				if(words[i][j]=='n'&&j+1<words[i].size()&&words[i][j+1]=='g'){
					tmp += char('a'+11);
					j++;
				}else
					tmp += mark[words[i][j]];
			}
			vec.push_back(tmp);
			index.push_back(i);
		}
		sort(index.begin(),index.end(),cmp);
		vector<string> res;
		for(int i=0;i<words.size();++i)
			res.push_back(words[index[i]]);
		return res;
	}
};
