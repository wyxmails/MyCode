#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permute(string s,vector<string> &res){
	if(s.size()<=1){
	   	res.push_back(s);
		return;
	}
	string tmp = s.substr(1,s.size()-1);
	vector<string> cur;
	cur.clear();
	permute(tmp,cur);
	for(int i=0;i<cur.size();++i){
		string tmp1;
		for(int j=0;j<=cur[i].size();++j){
			tmp1 = cur[i].substr(0,j) + s[0] + cur[i].substr(j);
			res.push_back(tmp1);
		}
	}
}

int main(int argc,char*argv[]){
	string s = "abc";
	vector<string> res;
	res.clear();
	permute(s,res);
	for(int i=0;i<res.size();++i){
		cout << res[i] << endl;
	}
	return 0;
}
