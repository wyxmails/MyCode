/*
 if EVER + SINCE = DARWIN , then what is D+A+R+W+I+N?
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

char One;

void Judge(map<char,int>&val,const string&a,const string&b,const string&c){
	int an=0,bn=0,cn=0,res=0;
	for(int i=0;i<a.size();++i)
		an = an*10 + val[a[i]];
	for(int i=0;i<b.size();++i)
		bn = bn*10 + val[b[i]];
	for(int i=0;i<c.size();++i){
		cn = cn*10 + val[c[i]];
		res += val[c[i]];
	}
	if(an+bn==cn)
		cout << res << endl;
}

void Compute(map<char,int>&val,vector<char>&dic,vector<bool>&used,int cur,int n,const string&a,const string&b,const string&c){
	if(cur>=n){
		if(One!=' '&&val[One]!=1) return;
		Judge(val,a,b,c);
		return;
	}
	for(int i=0;i<n;++i){
		if(!used[i]){
			used[i] = true;
			val[dic[cur]] = i;
			Compute(val,dic,used,cur+1,n,a,b,c);
			used[i] = false;
		}
	}
}

void decode(string a,string b,string c){
	set<char> ddic;
	for(int i=0;i<a.size();++i)
		ddic.insert(a[i]);
	for(int i=0;i<b.size();++i)
		ddic.insert(b[i]);
	for(int i=0;i<c.size();++i)
		ddic.insert(c[i]);
	int n = ddic.size();
	if(c.size()>a.size()&&c.size()>b.size()) One = c[0]; 
	else One = ' ';
	vector<char> dic(ddic.begin(),ddic.end());
	vector<bool> used(n,false);
	map<char,int> val;
	Compute(val,dic,used,0,n,a,b,c);
}
void decode2(string a,string b,string c){
	set<char> ddic;
	for(int i=0;i<a.size();++i)
		ddic.insert(a[i]);
	for(int i=0;i<b.size();++i)
		ddic.insert(b[i]);
	for(int i=0;i<c.size();++i)
		ddic.insert(c[i]);
	int n = ddic.size();
	if(c.size()>a.size()&&c.size()>b.size()) One = c[0]; 
	else One = ' ';
	vector<char> dic(ddic.begin(),ddic.end());
	vector<int> vec(n);
	map<char,int> mark;
	for(int i=0;i<n;++i) vec[i] = i;
	do{
		mark.clear();
		for(int i=0;i<n;++i)
			mark[dic[i]] = vec[i];
		if(One!=' '&&mark[One]!=1) continue;
		Judge(mark,a,b,c);
	}while(next_permutation(vec.begin(),vec.end()));
}

int main(int argc,char*argv[]){
	string a = "EVER";
	string b = "SINCE";
	string c = "DARWIN";
	cout << "decode with recursion: " << endl;
	decode(a,b,c);
	cout << "iterate with algorithm: " << endl;
	decode2(a,b,c);
	return 0;
}
