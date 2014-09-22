#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string s1,string s2){
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	return s1<s2;
}

void sortArraysStr(vector<string>&vec){
	sort(vec.begin(),vec.end(),cmp);
}

int main(int argc,char*argv[]){
	vector<string> vec;
	vec.push_back("abc");
	vec.push_back("bac");
	vec.push_back("aa");
	vec.push_back("dba");
	vec.push_back("abd");
	vec.push_back("bb");
	sortArraysStr(vec);
	for(int i=0;i<vec.size();++i)
		cout << vec[i] << endl;
	return 0;
}
