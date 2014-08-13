/*Longest Common Prefix
   Write a function to find 
   the longest common prefix string amongst an array of strings.
 */
string longestCommonPrefix(vector<string> &strs) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	string res = "";
	if(strs.size()<1) return res;
	char c;
	int cnt = 0;
	bool com = true;
	while(com){
		if(cnt<strs[0].size())
			c = strs[0][cnt];
		else
			com = false;
		for(int i=1;com&&i<strs.size();++i){
			if(cnt>=strs[i].size()||strs[i][cnt]!=c)
				com = false;
		}
		cnt++;
		if(com) res += c;
	}
	return res;
}

string longestCommonPrefix2(vector<string> &strs) {
        string res = "";
        int m =strs.size();
        if(m<=0) return res;
        int n = strs[0].size();
        if(n<=0) return res;
        for(int i=0;i<n;++i){
            char c = strs[0][i];
            for(int j=0;j<m;++j){
                if(strs[j][i]!=c) return res;
            }
            res += c;
        }
        return res;
}
