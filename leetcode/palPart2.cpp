#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
int minCut(string s) {
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
int main(int argc,char*argv[]){
	//string s = "aaaaaaabbaaa";
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	cout << minCut(s) << endl;
	return 0;
}
