/*
 How to encode and decode 2 strings? 
 The strings might contain non-alpha numeric characters. 
 The interviewer asked me how can I store the length of one string in the combined string. Not sure how to do this.
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Codec {
public:
	string encode(string s1, string s2) {
		int n = s1.size();
		stringstream ss;
		ss.clear();
		ss<<n;
		string res;
	   	ss>>res;
		res += "L";
		res += s1;
		res += s2;
		return res;
	}

	vector<string> decode(string s) {
		int i = s.find_first_of('L');
		int n = atoi(s.substr(0,i).c_str());
		s = s.substr(i+1);
		vector<string> res;
		res.push_back(s.substr(0,n));
		res.push_back(s.substr(n));
		return res;
	}
};

int main(int argc,char*argv[]) {
	Codec *c = new Codec();
	string s1 = "123";
	string s2 = "abc";
	string s = c->encode(s1,s2);
	vector<string> a = c->decode(s);
	for(int i=0;i<a.size();++i)
		cout << a[i] << endl;
	return 0;
}

