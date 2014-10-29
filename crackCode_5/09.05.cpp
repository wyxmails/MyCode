/*
 Write a method to compute all permutations of a string
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> AllPermutation(string S){
	vector<string> res;
	if(S.size()==0){
		res.push_back("");
		return res;
	}
	char c = S[0];
	string remainder = S.substr(1);
	vector<string> words = AllPermutation(remainder);
	for(int i=0;i<words.size();++i){
		int n = words[i].size();
		for(int j=0;j<=n;++j){
			string tmp;
			if(j==0) tmp = c+words[i];
			else if(j==n) tmp = words[i]+c;
			else tmp = words[i].substr(0,j)+c+words[i].substr(j);
			res.push_back(tmp);
		}
	}
	return res;
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	int n = rand()%5;
	cout << "n: " << n << endl;
	int tmp = -1;
	string S = "";
	for(int i=0;i<n;++i){
		tmp = rand()%5+tmp+1;
		char c = 'a'+tmp;
		cout << c;
		S += c;
	}
	cout << endl;
	vector<string> res = AllPermutation(S);
	for(int i=0;i<res.size();++i)
		cout << res[i] << endl;
	return 0;
}
