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
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int ary=3;
	int len,num,tmp;
	map<int,int> mapint;
	vecint.clear();
	for(int i=0;i<L.size();++i){
		len = L[i].size()-1;
		num = 0;
		for(int j=0;j<=len;++j){
			tmp = L[i][j]-'a';
			num += tmp*pow(ary,len-j);
		}
		mapint[num] = 0;
	}
	num = 0;
	for(int i=0;i<S.size()&&i<len;++i){
		num += tmp*pow(ary,len-i);
	}
	map<int,int>::iterator it;
	bool restart=false;
	for(int i=0;i<S.size();++i){
		restart = true;
		for(it = mapint.begin();it!=mapint.end();++it){
			if(num==(*it).first){
				if((*it).second==1) break;
				else{
					(*it).second=1;
					restart = false;
					break;
				} 
			}
		}
		if(restart){
			for(it = mapint.begin();it!=mapint.end();++it)
				(*it).second = 0;
		}else{
		
		}
	}
}
