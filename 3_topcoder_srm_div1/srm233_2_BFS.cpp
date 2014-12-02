/*
 Problem Statement
     
 The toy company "I Can't Believe It Works!" has hired you to help develop educational toys. The current project is a word toy that displays four letters at all times. Below each letter are two buttons that cause the letter above to change to the previous or next letter in alphabetical order. So, with one click of a button the letter 'c' can be changed to a 'b' or a 'd'. The alphabet is circular, so for example an 'a' can become a 'z' or a 'b' with one click.  In order to test the toy, you would like to know if a word can be reached from some starting word, given one or more constraints. A constraint defines a set of forbidden words that can never be displayed by the toy. Each constraint is formatted like "X X X X", where each X is a string of lowercase letters. A word is defined by a constraint if the ith letter of the word is contained in the ith X of the contraint. For example, the constraint "lf a tc e" defines the words "late", "fate", "lace" and "face".  You will be given a String start, a String finish, and a String[] forbid. Calculate and return the minimum number of button presses required for the toy to show the word finish if the toy was originally showing the word start. Remember, the toy must never show a forbidden word. If it is impossible for the toy to ever show the desired word, return -1.
 Definition
     
Class:
SmartWordToy
Method:
minPresses
Parameters:
string, string, vector <string>
Returns:
int
Method signature:
int minPresses(string start, string finish, vector <string> forbid)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
start and finish will contain exactly four characters.
-
start and finish will contain only lowercase letters.
-
forbid will contain between 0 and 50 elements, inclusive.
-
Each element of forbid will contain between 1 and 50 characters.
-
Each element of forbid will contain lowercase letters and exactly three spaces.
-
Each element of forbid will not contain leading, trailing or double spaces.
-
Each letter within a group of letters in each element of forbid will be distinct. Thus "aa a a a" is not allowed.
-
start will not be a forbidden word.
Examples
0)

    
"aaaa"
"zzzz"
{"a a a z", "a a z a", "a z a a", "z a a a", "a z z z", "z a z z", "z z a z", "z z z a"}
Returns: 8

1)

    
"aaaa"
"bbbb"
{}
Returns: 4
Simply change each letter one by one to the following letter in the alphabet.
2)

    
"aaaa"
"mmnn"
{}
Returns: 50
Just as in the previous example, we have no forbidden words. Simply apply the correct number of button presses for each letter and you're there.
3)

    
"aaaa"
"zzzz"
{"bz a a a", "a bz a a", "a a bz a", "a a a bz"}
Returns: -1
Here is an example where it is impossible to go to any word from "aaaa".
4)

    
"aaaa"
"zzzz"
{"cdefghijklmnopqrstuvwxyz a a a", 
"a cdefghijklmnopqrstuvwxyz a a", 
"a a cdefghijklmnopqrstuvwxyz a", 
"a a a cdefghijklmnopqrstuvwxyz"}
Returns: 6

5)

    
"aaaa"
"bbbb"
{"b b b b"}
Returns: -1

6)

    
"zzzz"
"aaaa"
{"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk"}
Returns: -1

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
bool dict[26][26][26][26];

class SmartWordToy{
public:
	int minPresses(string start, string finish, vector <string> forbid);
private:
	void InitialDict(vector<string>&forbid);
};

void SmartWordToy::InitialDict(vector<string>&forbid){
	int n = forbid.size();
	for(int i=0;i<n;++i){
		stringstream ss(forbid[i]);
		string a,b,c,d;
		ss>>a>>b>>c>>d;
		for(int i1=0;i1<a.size();++i1)
		for(int i2=0;i2<b.size();++i2)
		for(int i3=0;i3<c.size();++i3)
		for(int i4=0;i4<d.size();++i4){
			dict[a[i1]-'a'][b[i2]-'a'][c[i3]-'a'][d[i4]-'a'] = true;
		}
	}
}
int SmartWordToy::minPresses(string start, string finish, vector <string> forbid){
	if(start==finish) return 0;
	if(forbid.size()==0){
		int res = 0;
		for(int i=0;i<4;++i){
			int tmp = abs(start[i]-finish[i]);
			res += min(tmp,26-tmp);
		}
		return res;
	}
	InitialDict(forbid);
	if(dict[finish[0]-'a'][finish[1]-'a'][finish[2]-'a'][finish[3]-'a']) return -1;
	dict[start[0]-'a'][start[1]-'a'][start[2]-'a'][start[3]-'a'] = true;
	vector<set<string> > layer(2);
	int steps=0,cur=0,pre=1;
	layer[cur].insert(start);
	while(!layer[cur].empty()){
		steps++;
		cur = !cur; pre = !pre;
		layer[cur].clear();
		for(auto it=layer[pre].begin();it!=layer[pre].end();++it){
			string word;
			for(int i=0;i<4;++i)
			for(int j=-1;j<=1;j+=2){
				word = *it;
				word[i] = char((26+word[i]-'a'+j)%26+'a');
				if(word==finish) return steps;
				if(!dict[word[0]-'a'][word[1]-'a'][word[2]-'a'][word[3]-'a']){
					layer[cur].insert(word);
					dict[word[0]-'a'][word[1]-'a'][word[2]-'a'][word[3]-'a'] = true;
				}
			}
		}
	}
	return -1;
}
