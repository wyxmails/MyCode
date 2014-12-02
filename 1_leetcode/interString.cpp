#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 
 For example,
Given:
 s1 = "aabcc",
 s2 = "dbbca",
 
 When s3 = "aadbbcbcac", return true.
 When s3 = "aadbbbaccc", return false.
 */
bool isInterleaveDP(string s1, string s2, string s3) {
	int n1 = s1.size();
	int n2 = s2.size();
	int n3 = s3.size();
	if(n1+n2!=n3) return false;
	if(n3==0) return true;
	vector<vector<bool> > mark(n1+1,vector<bool>(n2+1,false));
	mark[0][0] = true;
	for(int i=0;i<n1;++i){
		if(s1[i]==s3[i])
			mark[i+1][0] = true;
		else break;
	}
	for(int j=0;j<n2;++j){
		if(s2[j]==s3[j])
			mark[0][j+1] = true;
		else break;
	}
	for(int i=1;i<=n1;++i){
		for(int j=1;j<=n2;++j){
			if(s3[i+j-1]==s1[i-1])
				mark[i][j] = mark[i-1][j]||mark[i][j];
			if(s3[i+j-1]==s2[j-1])
				mark[i][j] = mark[i][j-1]||mark[i][j];
		}
	}
	return mark[n1][n2];
}

bool myInter(const string& s1,int i1,int e1,const string& s2,int i2,int e2,const string& s3,int i3,int e3){
	if(i3>e3) return true;
	if(i1>e1){
		while(i3<=e3&&s3[i3]==s2[i2]){
			i2++;i3++;
		}
		if(i3<=e3) return false;
		return true;
	}
	if(i2>e2){
		while(i3<=e3&&s3[i3]==s1[i1]){
			i1++;i3++;
		}
		if(i3<=e3) return false;
		return true;
	}
	if(s1[i1]==s3[i3]){
		if(s1[e1]==s3[e3]&&myInter(s1,i1+1,e1-1,s2,i2,e2,s3,i3+1,e3-1)) return true;
		if(s2[e2]==s3[e3]&&myInter(s1,i1+1,e1,s2,i2,e2-1,s3,i3+1,e3-1)) return true;
	}
	if(s2[i2]==s3[i3]){
		if(s1[e1]==s3[e3]&&myInter(s1,i1,e1-1,s2,i2+1,e2,s3,i3+1,e3-1)) return true;
		if(s2[e2]==s3[e3]&&myInter(s1,i1,e1,s2,i2+1,e2-1,s3,i3+1,e3-1)) return true;
	}
	return false;
}
bool isInterleave(string s1, string s2, string s3) {
	if(s1.size()+s2.size()!=s3.size()) return false;
	if(s3.size()==0) return true;
	return myInter(s1,0,s1.size()-1,s2,0,s2.size()-1,s3,0,s3.size()-1);
}
int main(int argc,char*argv[]){
	string s1 = "ab";
	string s2 = "bc";
	string s3 = "babc";
	if(isInterleave(s1,s2,s3))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	if(isInterleaveDP(s1,s2,s3))
		cout << "DP true" << endl;
	else
		cout << "DP false" << endl;
	return 0;
}
