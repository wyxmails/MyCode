/*
 Problem Statement
     
 We call a pair of strings (s, t) "wood" if t is contained in s as a subsequence. (See Notes for a formal definition.)
  
 Given strings s and t, return the string "Yep, it's wood." (quotes for clarity) if the pair (s, t) is wood and "Nope." otherwise.
 Definition
     
Class:
IdentifyingWood
Method:
check
Parameters:
string, string
Returns:
string
Method signature:
string check(string s, string t)
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
String t is contained in string s as a subsequence if we can obtain t by removing zero or more (not necessarily consecutive) characters from s.
Constraints
-
s and t will consist only of lowercase English letters.
-
s and t will each be between 1 and 10 characters long, inclusive.
Examples
0)

    
"absdefgh"
"asdf"
Returns: "Yep, it's wood."

1)

    
"oxoxoxox"
"ooxxoo"
Returns: "Nope."

2)

    
"oxoxoxox"
"xxx"
Returns: "Yep, it's wood."

3)

    
"qwerty"
"qwerty"
Returns: "Yep, it's wood."

4)

    
"string"
"longstring"
Returns: "Nope."

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */
#include <iostream>
#include <vector>
using namespace std;

class IdentifyingWood{
	public:
		string check(string s,string t);
};

string IdentifyingWood::check(string s,string t){
	int m = t.size();
	int n = s.size();
	string resT = "Yep, it's wood.";
	string resF = "Nope.";
	if(m>n) return resF;
	if(m==0) return resT;
	vector<vector<bool> > mark(m,vector<bool>(n,false));
	for(int i=0;i<m;++i){
		for(int j=i;j<n;++j){
			if(t[i]==s[j]){
				if(i==0||j==0||mark[i-1][j-1]){
					mark[i][j] = true;
					continue;
				}
			}
			else if(j>0&&mark[i][j-1])
				mark[i][j] = true;
		}
	}
	if(mark[m-1][n-1]) return resT;
	else return resF;
}

int main(){
	IdentifyingWood iw;
	string s = "absdefgh";
	string t = "asdf";
	cout << "0: " << iw.check(s,t) << endl;
	s = "oxoxoxox";
	t = "ooxxoo";
	cout << "1: " << iw.check(s,t) << endl;
	s = "oxoxoxox";
	t = "xxx";
	cout << "2: " << iw.check(s,t) << endl;
	s = "qwerty";
	t = "qwerty";
	cout << "3: " << iw.check(s,t) << endl;
	s = "string";
	t = "longstring";
	cout << "4: " << iw.check(s,t) << endl;
	s = "aaaaaaabc";
	t = "aabc";
	cout << "5: " << iw.check(s,t) << endl;
	return 0;
}
