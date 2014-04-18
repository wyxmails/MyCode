/*Anagrams
 Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.
 */
vector<string> anagrams(vector<string> &strs) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(strs.size()<1) return strs;
	int i;
	map<string,vector<string> > dict;
	dict.clear();
	for(i=0;i<strs.size();++i){
		string key = strs[i];
		sort(key.begin(),key.end());
		dict[key].push_back(strs[i]);
	}
	vector<string> res;
	res.clear();
	map<string,vector<string> >::iterator it;
	for(it=dict.begin();it!=dict.end();++it){
		if((*it).second.size()>1){
			for(i=0;i<(*it).second.size();++i){
				res.push_back((*it).second[i]);
			}
		}
	}
	return res;
}
