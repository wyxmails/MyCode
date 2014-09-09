/*
 Given a set S, find all the maximal subsets whose sum <= k. For example, if S = {1, 2, 3, 4, 5} and k = 7

 Output is: {1, 2, 3} {1, 2, 4} {1, 5} {2, 5} {3, 4}

Hint:

- Output doesn’t contain any set which is a subset of other.

- If X = {1, 2, 3} is one of the solution then all the subsets of X {1} {2} {3} {1, 2} {1, 3} {2, 3} are omitted.

- Lexicographic ordering may be used to solve it
 */
#include <iostream>
#include <vector>
#include <tr1/unordered_set>
using namespace std;
using namespace std::tr1;

vector<vector<int> > sumSets(vector<int> &dic,int K){
	vector<vector<int> > res;
	int n = dic.size();
	if(n==0) return res;
	vector<int> mid;
	int i=0,v=0;
	for(;i<n;++i){
		if(v+dic[i]>K) break;
		v += dic[i];
		mid.push_back(dic[i]);
	}
	if(mid.size()==0) return res;
	res.push_back(mid);
	for(;i<n;++i){
		if(dic[i]>K) break;
		int s=0,e=0,r;
		while(e<i){
			r=s;
			mid.clear();
			v = dic[i];
			while(r<i&&dic[r]+v<=K){
				v += dic[r++];
			}
			s++;
			if(r<=e) continue;
			e = r;
			for(int j=s-1;j<r;++j) mid.push_back(dic[j]);
			mid.push_back(dic[i]);
			res.push_back(mid);
			if(s-1==r) break;
		}
	}
	return res;
}

int main(int argc,char*argv[]){
	vector<int> vec;
	for(int i=0;i<10;++i){
		vec.push_back(i+1);
	}
	vector<vector<int> > res = sumSets(vec,10);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
