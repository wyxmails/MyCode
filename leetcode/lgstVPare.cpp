/*Longest Valid Parentheses
 Given a string containing just the characters '(' and ')', 
 find the length of the longest valid (well-formed) parentheses substring.
 For "(()", the longest valid parentheses substring is "()", 
 which has length = 2.
 Another example is ")()())", 
 where the longest valid parentheses substring is "()()", 
 which has length = 4.
 */
int longestValidParentheses(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> myvec;
	myvec.clear();
	int M,start;
	M=0;
	start=-1;
	for(int i=0;i<s.size();++i){
		if(s[i]=='(') myvec.push_back(i);
		else{
			if(!myvec.empty()&&s[myvec.back()]=='('){
				myvec.pop_back();
				start = myvec.empty()?-1:myvec.back();
				M = max(M,i-start);
			}else myvec.push_back(i);
		}
	}
	return M;
}
