/*Longest Substring Without Repeating Characters
   Given a string, find the length of the longest substring 
   without repeating characters. For example, 
   the longest substring without repeating letters for "abcabcbb" 
   is "abc", which the length is 3. 
   For "bbbbb" the longest substring is "b", with the length of 1.
 */
int lengthOfLongestSubstring(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int MAX=0;
	int cnt=0;
	set<char> setres;
	for(int i=0;i<=s.size()-MAX;++i){
		setres.clear();
		for(int j=i;j<s.size();++j){
			setres.insert(s[j]);
			if(setres.size()==cnt) break;
			cnt = setres.size();
		}
		if(cnt>MAX) MAX = cnt;
		cnt = 0;
	}
	return MAX;
}
