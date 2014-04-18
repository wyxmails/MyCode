/*Longest Palindromic Substring
   Given a string S, find the longest palindromic substring in S. 
  You may assume that the maximum length of S is 1000, i
  and there exists one unique longest palindromic substring.*/
string longestPalindrome(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int b=0;
	int e=s.size();
	int i,j;
	string res;
	int MAX = 0;
	for(int b=0;b<s.size();++b){
		for(int e=s.size()-1;e>=b+MAX;--e){
			i=b;
			j=e;
			while(i<j){
				if(s[i]!=s[j])
					break;
				i++;
				j--;
			}
			if(i>=j&&(e-b+1)>MAX){
				res = s.substr(b,e-b+1);
				MAX = res.size();
			}
		}
	}
	return res;
}
