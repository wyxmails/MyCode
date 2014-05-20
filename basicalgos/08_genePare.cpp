#include <iostream>
#include <vector>
using namespace std;

vector<string> mygen(string prefix,int l,int r){
	vector<string> result;
	result.clear();
	if(l==0){
		for(int i=0;i<r;++i) prefix += ")";
		result.push_back(prefix);
		return result;
	}
	vector<string> r1;
	r1.clear();
	r1 = mygen(prefix+"(",l-1,r);
	result.insert(result.end(),r1.begin(),r1.end());
	if(l<r){
		r1.clear();
		r1 = mygen(prefix+")",l,r-1);
		result.insert(result.end(),r1.begin(),r1.end());
	}
	return result;
}

vector<string> gene(int n){
	return mygen(string(""),n,n);
}
int main(){
	int n;
	cin>>n;
	vector<string> vec;
	vec.clear();
	vec = gene(n);
	for(int i=0;i<vec.size();++i){
		cout << vec[i] << " ";
	}
	cout << endl;
	return 0;
}
