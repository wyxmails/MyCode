/*
 he Chef is having a dinner party and invited over all his friends. His guests
 being fairly health conscious have exact protein requirements, and The Chef wishes to oblige them all.
 The Chef will cook dishes for each individual guest using the ingredients in his kitchen. Each ingredient has a specific amount of protein. The complete dish will have a protein content value equal to the sum of the protein
 contents of the individual ingredients. To cook a dish, The Chef can use any of the ingredients which appear on his shelf, but only in the order which they appear on the shelf. The same ingredient may appear multiple times, and can also be used as many times as it appears.
 There are multiple ways to choose ingredients following the rules given above. However, The Chef is only interested in choosing the set of ingredients that appear first in a lexicographically ordered list of ingredients which satisfy the protein constraints. Your job is to write a program that helps The Chef figure out which dish to serve!
 Input

 The first line of input contains t, the number of guests invited by The Chef (about 200).
 Each test consists of three lines:
 The first line consists of one integer 1 <= k <= 26 (the number of unique ingredients on the shelf) and than k
 space-separated positive integers from the set {1, 2, ... ,15} describing the protein content for each ingredient in an alphabetically sorted list of unique ingredients. (the first protein value corresponds with ingredient a, the second corresponds with the protein value for ingredient b, and so on).
 The second line contains L - a sequence of lower-case letters of the Latin alphabet (at most 1000) which signify the name of the ingredient.
 The third line contains one positive integer S which specifies the exact protein requirement of this guest (1 < S < 500).
 Output

 For each testcase either output the sequence of ingredients as described above, or the word 'IMPOSSIBLE' if no such subsequence exists.
 Example

Input:
3
5 12 1 12 4 4
acccdadceb
2
3 5 4 6
abcbacbabcc
15
2 3 4
baba
7

Output:
IMPOSSIBLE
aaa
ab
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

void GetRes(string &name,int index,int target,unordered_map<char,int> &mark,string &res,set<string>&res_final){
	if(target==0) return;
	if(index>=name.size()) return;
	if(mark[name[index]]==target){
		res += name[index];
		res_final.insert(res);
		res.resize(res.size()-1);
		return;
	}
	if(mark[name[index]]>target) 
		return GetRes(name,index+1,target,mark,res,res_final);	
	res += name[index];
	int n = res.size();
	GetRes(name,index+1,target-mark[name[index]],mark,res,res_final);
	if(res.size()>n) return ;
	res.resize(n-1);
	GetRes(name,index+1,target,mark,res,res_final);
}

//time complexity: 2^n
string DinnerPrepare(vector<int> ingredient,string name,int target){
	unordered_map<char,int> mark;
	int n = ingredient.size();
	for(int i=0;i<n;++i){
		char c = 'a'+i;
		mark[c] = ingredient[i];
	}
	string res="";
	set<string> res_final;
	GetRes(name,0,target,mark,res,res_final);
	if(res_final.size()>0){
		set<string>::iterator it = res_final.begin();
		return *it;
	}
	return "IMPOSSIBLE";
}

//time complexity: n^2
string DinnerPrepare2(vector<int> ingredient, string name, int target){
	vector<string> result(501,"");
	int n = name.size();
	for(int i=0;i<n;++i){
		int val = ingredient[name[i]-'a'];
		for(int j=target-val;j>=0;--j){
			if(result[j]!=""||j==0){
				string tmp = result[j]+name[i];
				if(result[j+val]==""||tmp<result[j+val])
					result[j+val] = tmp;
			}
		}
	}
	if(result[target].size()==0) return "IMPOSSIBLE";
	return result[target];
}

int main(int argc,char*argv[]){
	int t,n;
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;++i)
			cin>>vec[i];
		string name;
		cin>>name;
		int target;
		cin>>target;
		cout << DinnerPrepare(vec,name,target) << endl;
		cout << DinnerPrepare2(vec,name,target) << endl;
	}
	return 0;
}
