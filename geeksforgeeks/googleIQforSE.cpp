/*
 Given an input string S write a function 
 which returns true if it satisfies S = nT. 
 Basically you have to find if a given string can be 
 represented from a substring by iterating it “n” times. n >= 2
 An example would suffice –

 Function should return true if
 1) S = "abab"
 2) S = "abcdabcd"
 3) S = "abcabcabc"
 4) S = "zzxzzxzzx"
 Function should return false if
 1) S = "abac"
 2) S = "abcdabbd"
 3) S = "abcabcefg"
 4) S = "zzxzzyzzx"
 It would be easy to understand if you can give an algo instead of saying use kmp or suffix tree or…
 I came up with O(n*n) solution. Wondered how to do in O(n) 
 */
#include <iostream>
#include <string>
#include <climits>
#include <tr1/unordered_map>
#include <vector>

using namespace std;
using namespace std::tr1;

int LCM(int a,int b){
	int c;
	if(a==b){
		return a;
	}
	if(a<b){
		c=a; a=b; b=c;
	}
	while(a>b){
		if(a%b==0) return b;
		c=a%b; a=b; b=c;
	}
	return 1;
}

bool isPattern(string & S){
	int n = S.size();
	unordered_map<char,int> mark;
	int minN = INT_MAX;
	for(int i=0;i<n;++i){
		mark[S[i]]++;
	}
	unordered_map<char,int>::iterator it;
	for(it=mark.begin();it!=mark.end();++it)
		minN = min(minN, it->second);
	if(minN==n||minN==1) return false;
	if(n%minN) return false;
	int len = n/minN;
	cout << "len: " << len << endl;
	for(int i=1;i<minN;++i){
		for(int j=0,k=len;j<len;++j,++k)
			if(S[j]!=S[k]) return false;
	}
}

//factor 
//for example if n=10!, then we will at most go through S 9times.
bool isPattern2(string &S){
	int n = S.size();
	int len;
	vector<int> steps;
	for(int i=2;i<=n/2;i++){
		if(n%i) continue;
		if(steps.size()>0){
			bool wrong = false;
			for(int j=0;j<steps.size()&&!wrong;++j){
				if(i%steps[j]==0) wrong = true;
			}
			if(wrong) continue;
		}
		len = n/i;
		bool pattern = true;
		for(int j=1;j<i&&pattern;++j){
			for(int k=0;k<len&&pattern;++k){
				if(S[k]!=S[j*len+k])
					pattern = false;
			}
		}
		if(pattern) return true;
		steps.push_back(i);
	}
	return false;
}

bool isPatternKMP(string&S){
	int n = S.size();
	vector<int> maton(n+1,0);
	for(int i=1;i<n;++i){
		int t =i;
		while(t>0){
			t = maton[t];
			if(S[i]==S[t]) {maton[i+1] = t+1; break;}
		}
	}
	int len = n-maton[n];
	if(len<=1||len>n/2) return false;
	int cur = n;
	int next = maton[n];
	while(next>0){
		if(cur-next!=len) return false;
		cur = next;
		next = maton[cur];
	}
	return true;
}

int main(int argc,char*argv[]){
	//cout << LCM(10,15) << endl;
	//cout << LCM(12,16) << endl;
	//cout << LCM(6,9) << endl;
	//cout << LCM(4,9) << endl;
	//cout << LCM(14,9) << endl;
	//cout << LCM(2,8) << endl;
	//return 0;
	cout << "True test cases: " << endl;
	string S = "abab";
	if(isPattern2(S)) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "KMP: ";
	if(isPatternKMP(S)) cout << "true" << endl;
	else cout << "false" << endl;
	
	S = "abcdabcd";
	if(isPattern2(S)) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "KMP: ";
	if(isPatternKMP(S)) cout << "true" << endl;
	else cout << "false" << endl;
	
	S = "abcabcabc";
	if(isPattern2(S)) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "KMP: ";
	if(isPatternKMP(S)) cout << "true" << endl;
	else cout << "false" << endl;
	
	S = "zzxzzxzzx";
	if(isPattern2(S)) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "KMP: ";
	if(isPatternKMP(S)) cout << "true" << endl;
	else cout << "false" << endl;
	
	S = "zzxxzzxxzzxx";
	if(isPattern2(S)) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "KMP: ";
	if(isPatternKMP(S)) cout << "true" << endl;
	else cout << "false" << endl;

	cout << endl << "False test cases: " << endl;
	S = "abac";
	if(isPattern2(S)) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "KMP: ";
	if(isPatternKMP(S)) cout << "true" << endl;
	else cout << "false" << endl;
	
	S = "abcdabbd";
	if(isPattern2(S)) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "KMP: ";
	if(isPatternKMP(S)) cout << "true" << endl;
	else cout << "false" << endl;

	S = "abcabcefg";
	if(isPattern2(S)) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "KMP: ";
	if(isPatternKMP(S)) cout << "true" << endl;
	else cout << "false" << endl;
	
	S = "zzxzzyzzx";
	if(isPattern2(S)) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "KMP: ";
	if(isPatternKMP(S)) cout << "true" << endl;
	else cout << "false" << endl;
	
	return 0;
}
