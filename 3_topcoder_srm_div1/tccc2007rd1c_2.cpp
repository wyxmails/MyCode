/*

Problem Statement
    
A microbiologist wants us to partition a collection of strings into disjoint groups based on common prefixes. The desired partition is formed by the following process:
 
    while there are at least 2 strings that have not been assigned to a group:
        find the longest prefix that appears in at least 2 unassigned strings
        form a new group consisting of all unassigned strings having that prefix
    if there is an unassigned string, assign it to its own group
Note that the "longest prefix" in the algorithm above may have length 0.
We want to produce a listing of the strings organized by group, with a string of '-'s following the members of each group. The '-' string should contain one '-' for each character in the common prefix of the group. So a group whose common prefix has length 0 should be followed by the string "". As a special case, a group that contains just one string is considered to have a common prefix of length 0.
List the groups with the longest common prefix first. Among groups with the same length common prefix, list the groups alphabetically. Among strings within a group, list the strings alphabetically. Given a vector <string> protein, return a vector <string> that is the desired listing.
Definition
    
Class:
Prefixes
Method:
prefixList
Parameters:
vector <string>
Returns:
vector <string>
Method signature:
vector <string> prefixList(vector <string> protein)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
protein will contain between 1 and 50 elements, inclusive.
-
Each element of protein will contain between 1 and 50 characters, inclusive.
-
Each character in each element of protein will be an uppercase letter ('A'-'Z').
Examples
0)

    
{"AAAAA","ABCDE","ABCDE"}
Returns: {"ABCDE", "ABCDE", "-----", "AAAAA", "" }
The 2 identical strings are in a group since they have a common prefix consisting of all 5 letters. "AAAAA" cannot qualify to be in the same group as the other two. Since it is in a group by itself, it is followed by a string with 0 '-'s (an empty string) indicating a common prefix of length 0.
1)

    
{"ABCDE", "ABCDXY", "ABC", "ABD", "ARX"}
Returns: {"ABCDE", "ABCDXY", "----", "ABC", "ABD", "--", "ARX", "" }
The 3 groups have common prefixes "ABCD", "AB", and "". The groups are listed in order of longest prefix first.
2)

    
{"XA","AX","XB","A"}
Returns: {"A", "AX", "-", "XA", "XB", "-" }
The group with common prefix "A" comes before the group with common prefix "X" because it comes first alphabetically. Similarly, within each group, the individual strings are ordered alphabetically.
3)

    
{"XA","AX","YXB","A"}
Returns: {"A", "AX", "-", "XA", "YXB", "" }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

bool used[51];
struct Trie{
	char c;
	int prefix;
	vector<int> words;
	Trie*chi[26];
	Trie(char c,int prefix):c(c),prefix(prefix){
		for(int i=0;i<26;++i)
			chi[i] = NULL;
	}
};
struct key{
	string str;
	int len;
	key(string s,int len):str(s),len(len){}
	friend bool operator<(const key&a,const key&b){
		if(a.len!=b.len) return a.len>b.len;
		return a.str<b.str;
	}
};

class Prefixes{
public:
	vector <string> prefixList(vector <string> protein){
		memset(used,false,sizeof(used));
		int n = protein.size();
		Trie *root = new Trie(' ',0);
		for(int i=0;i<n;++i){
			addWord(root,protein[i],0,i);
		}
		map<key,vector<int> > mark;
		get(root,mark,"");
		vector<string> res;
		vector<string> other;
		for(auto it = mark.begin();it!=mark.end();++it){
			vector<int> tmp;
			if(it->first.len>1&&it->second.size()<=1) continue;
			for(int i=0;i<it->second.size();++i){
				if(!used[it->second[i]]){
					tmp.push_back(it->second[i]);
					used[it->second[i]] = true;
				}
			}
			if(tmp.size()>1){
				string dash = "";
				dash.append(it->first.len,'-');
				vector<string> mid;
				for(int i=0;i<tmp.size();++i)
					mid.push_back(protein[tmp[i]]);
				sort(mid.begin(),mid.end());
				mid.push_back(dash);
				res.insert(res.end(),mid.begin(),mid.end());
			}else{
				if(tmp.size()>0&&it->first.len<=1) 
					other.push_back(protein[tmp[0]]);
				else if(tmp.size()>0) used[tmp[0]] = false;
			}
		}
		if(other.size()>0){
			sort(other.begin(),other.end());
			res.insert(res.end(),other.begin(),other.end());
			res.push_back("");
		}
		return res;
	}
	void get(Trie*root,map<key,vector<int> > &mark,string pre){
		for(int i=0;i<26;++i){
			if(root->chi[i]!=NULL){
				string tmp = pre + root->chi[i]->c;
				mark[key(tmp,tmp.size())] = root->chi[i]->words;
				if(root->chi[i]->prefix>1)
					get(root->chi[i],mark,tmp);
			}
		}
	}
	void addWord(Trie*root,const string&str,int index,int pos){
		if(index>=str.size()) return;
		char c = str[index];
		int ii = int(c-'A');
		if(root->chi[ii]==NULL){
			root->chi[ii] = new Trie(c,0);
		}
		root->chi[ii]->prefix++;
		root->chi[ii]->words.push_back(pos);
		addWord(root->chi[ii],str,index+1,pos);
	}
};
