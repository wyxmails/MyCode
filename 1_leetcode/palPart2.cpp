#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 Given a string s, partition s such that every substring of the partition is a palindrome.
 
 Return the minimum cuts needed for a palindrome partitioning of s.
 
 For example, given s = "aab",
 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */
bool isPal(const string &s){
	int l=0;
	int r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			//cout << "s[" << l << "]: " << s[l] << " s[" << r << "]: " << s[r] << endl;
		   	return false;
		}
		l++; r--;
	}
	return true;
}
int minCutTLE(string s) {
	int n=s.size();
	if(n<=1) return 0;
	cout << "before" << endl;
	if(isPal(s)) return 0;
	vector<vector<int> > arr;
	cout << "after n: " << n << endl;
	vector<int> tmp;
	tmp.push_back(0);
	for(int i=0;i<n;++i){
		if(i%100==0) cout << i << endl;
		arr.push_back(tmp);
	}
	cout << "for" << endl;
	for(int len=1;len<n;++len){
		if(len%100==0)
			cout << "len: " << len << endl;
		for(int i=0;i<n-len;++i){
			string s1 = s.substr(i,len+1);
			if(isPal(s1)) arr[i].push_back(0);
			else{
				int tmp = n;
				for(int j=i;j<i+len;++j){
					if(arr[i][j]+arr[j+1][i+len]+1<tmp) 
					tmp = arr[i][j]+arr[j+1][i+len]+1;
					if(tmp==1) break;
				}
				arr[i].push_back(tmp);
			}
		}
	}
	//cout << arr[0][n-2] << " " << arr[0][n-1] << endl;
	int res = arr[0][n-1];
	//cout << "res: " << res << endl;
	return res;
}

int minCut(string s) {
	int n = s.size();
	if(n<=1) return 0;
	bool pal[n][n];
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			pal[i][j] = false;
		}
	}
	int cut[n+1];
	for(int i=0;i<=n;++i){
		cut[i] = n-i-1;
	} 
	for(int i=n-1;i>=0;--i){
		for(int j=i;j<n;++j){
			if(s[i]==s[j]&&(j-i<2||pal[i+1][j-1])){
				pal[i][j] = true;
				cut[i] = min(cut[i],cut[j+1]+1);
			}
		}
	}
	return cut[0];
}

int main(int argc,char*argv[]){
	//string s = "aaaaaaabbaaa";
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	cout << minCut(s) << endl;
	return 0;
}
