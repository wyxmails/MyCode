#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
/*Substring with Concatenation of All Words
   You are given a string, S, and a list of words, L, 
   that are all of the same length. 
   Find all starting indices of substring(s) in S 
   that is a concatenation of each word in L exactly once and 
   without any intervening characters.
 For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]
 You should return the indices: [0,9].
 (order does not matter).
 */
vector<int> findSubstring(string S, vector<string> &L) {
	vector<int> res;
	if(L.size()<=0) return res;
	if(L.size()*L[0].size()>S.size()) return res;
	map<string,int> mark;
	map<string,int> appear;
	for(int i=0;i<L.size();++i)
		mark[L[i]]++;
	int len = L[0].size();
	int b1,e1;
	int i=0;
	while(i<=(S.size()-L.size()*len)){
		bool find = true;
		appear.clear();
		for(b1=i,e1=i;e1<=i+(L.size()-1)*len;e1+=len){
			string s = S.substr(e1,len);
			if(mark.find(s)!=mark.end()){
				appear[s]++;
				if(appear[s]>mark[s]){
					find = false;
					break;
				}
			}else{
				find = false;
				break;
			}
		}
		if(find)
			res.push_back(b1);
		i++;	
	}
	return res;
}
int main(int argc,char*argv[]){
	string s1 = "barfoothefoobarman";
	vector<string> t1;
	t1.push_back("foo");
	t1.push_back("bar");
	vector<int> res = findSubstring(s1,t1);
	for(int i=0;i<res.size();++i) cout << res[i] << endl;
	return 0;
}
