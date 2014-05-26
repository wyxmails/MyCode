#include <iostream>
#include <string>
using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	if(start.compare(end)==0) return 0;
	int lev,len,dis;
	queue<string> myq;
	set<string> mark;
	myq.push(start);
	mark.insert(start);
	lev=1;
	len=dis=0;
	while(!myq.empty()){
		string s = myq.front();
		myq.pop();
		lev--;
		
		for(int i=0;i<s.size();++i){
			for(int j=0;j<26;++j){
				string tmp = s;
				tmp[i] = char('a'+j);
				if(tmp==end) return dis+2;
				if(dict.find(tmp)!=dict.end()&&mark.find(tmp)==mark.end()){
					len++;
					mark.insert(tmp);
					myq.push(tmp);
				}
			}
		}
		if(lev==0){
			dis++;
			lev=len;
			len=0;
		}
	}
	return 0;
}
