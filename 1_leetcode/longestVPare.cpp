#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestValidParentheses(string s) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	vector<int> vec;
	vec.clear();
	vec.push_back(-1);
	int n,tmp,M = 0;
	for(int i=0;i<s.size();++i){
		n=vec.size();
		if(s[i]=='('){
			tmp = i-vec[n-1]-1;
			if(tmp>M) M = tmp;
		   	vec.push_back(i);
		}else{
			if(n>1&&s[vec[n-1]]=='('){
				vec.pop_back();
			}else{
				tmp = i-vec[n-1]-1;
				if(tmp>M) M = tmp;
				vec.push_back(i);
				cout << "M " << M << endl;
			}
		}
	}
	tmp = s.size()-vec[vec.size()-1]-1;
	if(M<tmp) M = tmp;
	cout << "tmp: " << tmp << " M: " << M << endl;
	return M;
}
int main(){
	string s = ")(((((()())()()))()(()))(";
	cout << longestValidParentheses(s) << endl;
	return 0;
}
