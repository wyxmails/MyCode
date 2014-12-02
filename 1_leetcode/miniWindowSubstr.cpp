#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 
 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".
 
Note:
 If there is no such window in S that covers all characters in T, return the emtpy string "".
 
 If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */
string minWindow(string S, string T) {
	vector<int> expect(256,0);
	vector<int> appear(256,0);
	for(int i=0;i<T.size();++i){
		expect[T[i]]++;
	}
	int s=0;
	int cnt = 0;
	int mW = S.size()+1;
	int ms = -1;
	for(int i=0;i<S.size();++i){
		if(expect[S[i]]>0){
			if(appear[S[i]]<expect[S[i]])
			cnt++;
			appear[S[i]]++;
		}
		if(cnt==T.size()){
			while(s<i&&(appear[S[s]]>expect[S[s]]||expect[S[s]]==0)){
				appear[S[s]]--;
				s++;
			}
			if(i-s+1<mW){
				mW = i-s+1;
				ms = s;
			}
		}
	}
	return ms==-1 ? "" : S.substr(ms,mW);
}

int main(int argc,char*argv[]){
	string s = "abc";
	string t = "bc";
	cout << minWindow(s,t) << endl;
	return 0;
}
