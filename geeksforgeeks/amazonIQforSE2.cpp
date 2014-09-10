/*
 You have n strings with their lengths. 
 You are given an add(string s1,string s2) 
 which would concatenate the string s2 with s1 and return s3. 
 Optimize the cost of concatenation of all these strings 
 into one big string.
Ex: 1,3,2 are the lengths of given strings.
1+3=4
4+2=6
total cost=10
 */

//implement a heap
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct sPoint{
	string *sp;
	bool operator<(const sPoint&tmp) const{
		return sp->size()>tmp.sp->size();
	}
};

string concatenate(vector<string> &S){
	priority_queue<sPoint> pq;
	for(int i=0;i<S.size();++i){
		sPoint sP;
	   	sP.sp = &S[i];
		pq.push(sP);
	}
	string *res = pq.top().sp;
	pq.pop();
	while(!pq.empty()){
		string *tmp = pq.top().sp;
		pq.pop();
		*res += *tmp;
		sPoint sP;
		sP.sp = res;
		pq.push(sP);
		res = pq.top().sp;
		pq.pop();
	}
	return *res;
}

int main(int argc,char*argv[]){
	vector<string> vec;
	vec.push_back("a");
	vec.push_back("bb");
	vec.push_back("cccc");
	vec.push_back("dddddddd");
	cout << concatenate(vec) << endl;
	return 0;
}
