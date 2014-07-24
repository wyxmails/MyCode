#include <iostream>
#include <string>
using namespace std;
/*
 Given a string S and a string T, count the number of distinct subsequences of T in S.
 
 A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 
 Here is an example:
 S = "rabbbit", T = "rabbit"
 
 Return 3.
 */
int numDistinct(string S, string T) {
	int n = S.size();
	int m = T.size();
	int arr[m+1][n+1];
	for(int i=0;i<=m;++i){
		for(int j=0;j<=n;++j)
			if(i==0) arr[i][j] = 1;
			else arr[i][j] = 0;
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			if(S[j]==T[i]){
				arr[i+1][j+1] = arr[i][j]+arr[i+1][j];
			}else arr[i+1][j+1] = arr[i+1][j];
		}
	}
	return arr[m][n];
}
int numDistinct2(string S, string T) {
        int m = T.size();
        int n = S.size();
        vector<vector<int> > mark(m+1,vector<int>(n+1,0));
        for(int i=0;i<n;++i) mark[0][i] = 1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(T[i]==S[j]) mark[i+1][j+1] = mark[i][j]+mark[i+1][j];
                else mark[i+1][j+1] = mark[i+1][j];
            }
        }
        return mark[m][n];
}
int main(int argc,char*argv[]){
	string s = "ccc";
	string t = "c";
	cout << numDistinct(s,t) << endl;
	return 0;
}
