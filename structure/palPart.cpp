#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
/*
 Given a string s, partition s such that every substring of the partition is a palindrome.
 
 Return all possible palindrome partitioning of s.
 
 For example, given s = "aab",
 Return
 
   [
     ["aa","b"],
     ["a","a","b"]
   ]
 */
bool isPal(const string& s){
	int l=0;
	int r = s.size()-1;
	while(l<r){
		if(s[l]!=s[r]) return false;
		l++; r--;
	}
	return true;
}

vector<vector<string> > partition(string s) {
	set<vector<string> > mid;
	vector<vector<string> > res;
	if(s.size()==0) return res;
	if(s.size()==1){
		vector<string> vec;
		vec.push_back(s);
		res.push_back(vec);
		return res;
	}
	if(isPal(s)){
		vector<string> vec;
		vec.push_back(s);
		mid.insert(vec);
	}
	for(int i=1;i<s.size();++i){
		string s1 = s.substr(0,i);
		if(!isPal(s1)) continue;
		string s2 = s.substr(i);
		vector<vector<string> > left;
		left.clear();
		left = partition(s2);
		for(int k=0;k<left.size();++k){
			vector<string> vectmp;
			vectmp.clear();
			vectmp.push_back(s1);
			vectmp.insert(vectmp.end(),left[k].begin(),left[k].end());
			mid.insert(vectmp);
		}
	}
	set<vector<string> >::iterator it;
	for(it=mid.begin();it!=mid.end();++it){
		res.push_back(*it);
	}
	return res;
}

int main(int argc,char*argv[]){
	//string s = "ababbbabbaba";
	string s = "aba";
	vector<vector<string> > res = partition(s);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
