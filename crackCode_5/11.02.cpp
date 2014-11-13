/*
 Write a method to sort an array of strings so that all the anagrams are next to each other.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

struct Node{
	string alph;
	string orig;
	Node(){}
	Node(string a,string o):alph(a),orig(o){}
};

bool cmp(const Node&n1,const Node&n2){
	return n1.alph<n2.alph;
}

vector<string> SortAnagrams(vector<string> &vec){
	int n = vec.size();
	vector<Node> mark(n);
	for(int i=0;i<n;++i){
		string alph = vec[i];
		sort(alph.begin(),alph.end());
		mark[i] = Node(alph,vec[i]);
	}
	sort(mark.begin(),mark.end(),cmp);
	vector<string> res(n);
	for(int i=0;i<n;++i)
		res[i] = mark[i].orig;
	return res;
}

vector<string> SortAnagramsHash(vector<string>&vec){
	unordered_map<string,vector<string> > mark;
	int n = vec.size();
	for(int i=0;i<n;++i){
		string tmp = vec[i];
		sort(tmp.begin(),tmp.end());
		mark[tmp].push_back(vec[i]);
	}
	vector<string> res;
	unordered_map<string,vector<string> >::iterator it = mark.begin();
	for(;it!=mark.end();++it){
		for(int j=0;j<it->second.size();++j)
			res.push_back(it->second[j]);
	}
	return res;
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	int n = rand()%10+1;
	int len = rand()%5+1;
	cout << n << " " << len << endl;
	string s(len,' ');
	string s2(len,' ');
	vector<string> vec(n);
	for(int i=0,k=n-1;i<=k;++i,--k){
		for(int l=0,r=len-1;l<len;l++,r--){
			int tmp = rand()%26;
			s[l] = 'a'+tmp;
			s2[r] = 'a'+tmp;
		}
		vec[i] = s;
		vec[k] = s2;
	}
	for(int i=0;i<n;++i)
		cout << vec[i] << " ";
	cout << endl;
	vector<string> res = SortAnagrams(vec);
	for(int i=0;i<n;++i)
		cout << res[i] << " ";
	cout << endl;
	res = SortAnagramsHash(vec);
	cout << "hash result: " << endl;
	for(int i=0;i<n;++i)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}
