#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

void GetRes(string &name,int index,int target,unordered_map<char,int> &mark,string &res,set<string>&res_final){
	if(target==0) return;
	if(index>=name.size()) return;
	if(mark[name[index]]==target){
		res += name[index];
		res_final.insert(res);
		res.resize(res.size()-1);
		return;
	}
	if(mark[name[index]]>target) 
		return GetRes(name,index+1,target,mark,res,res_final);	
	res += name[index];
	int n = res.size();
	GetRes(name,index+1,target-mark[name[index]],mark,res,res_final);
	if(res.size()>n) return ;
	res.resize(n-1);
	GetRes(name,index+1,target,mark,res,res_final);
}

//time complexity: 2^n
string DinnerPrepare(vector<int> ingredient,string name,int target){
	unordered_map<char,int> mark;
	int n = ingredient.size();
	for(int i=0;i<n;++i){
		char c = 'a'+i;
		mark[c] = ingredient[i];
	}
	string res="";
	set<string> res_final;
	GetRes(name,0,target,mark,res,res_final);
	if(res_final.size()>0){
		set<string>::iterator it = res_final.begin();
		return *it;
	}
	return "IMPOSSIBLE";
}

//time complexity: n^2
string DinnerPrepare2(vector<int> ingredient, string name, int target){
	vector<string> result(501,"");
	int n = name.size();
	for(int i=0;i<n;++i){
		int val = ingredient[name[i]-'a'];
		for(int j=target-val;j>=0;--j){
			if(result[j]!=""||j==0){
				string tmp = result[j]+name[i];
				if(result[j+val]==""||tmp<result[j+val])
					result[j+val] = tmp;
			}
		}
	}
	if(result[target].size()==0) return "IMPOSSIBLE";
	return result[target];
}

int main(int argc,char*argv[]){
	int t,n;
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;++i)
			cin>>vec[i];
		string name;
		cin>>name;
		int target;
		cin>>target;
		cout << DinnerPrepare(vec,name,target) << endl;
		cout << DinnerPrepare2(vec,name,target) << endl;
	}
	return 0;
}
