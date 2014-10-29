/*
 Implement an algorithm to print all valid (i.e., properly opened and closed) combinations of n-pairs of parentheses.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void GenerateParentheses(int l,int r,int n,string &pare,vector<string>&res){
	if(l==n){
		pare.append(n-r,')');
		res.push_back(pare);
		pare.resize(pare.size()-n+r);
		return;
	}
	pare.append(1,'(');
	GenerateParentheses(l+1,r,n,pare,res);
	pare.resize(pare.size()-1);
	if(r<l){
		pare.append(1,')');
		GenerateParentheses(l,r+1,n,pare,res);
		pare.resize(pare.size()-1);
	}
}

vector<string> GenerateParentheses(int n){
	vector<string> res;
	string pare = "";
	if(n==0) return res;
	GenerateParentheses(0,0,n,pare,res);
	return res;
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	int n = rand()%5;
	cout << "n: " << n << endl;
	vector<string> res = GenerateParentheses(n);
	for(int i=0;i<res.size();++i)
		cout << res[i] << endl;
	return 0;
}
