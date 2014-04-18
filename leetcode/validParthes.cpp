/*Valid Parentheses
   Given a string containing just the characters '(', ')', 
   '{', '}', '[' and ']', determine if the input string is valid.
 
 The brackets must close in the correct order, "()" and "()[]{}" 
 are all valid but "(]" and "([)]" are not.
 */
bool isValid(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int num = 7,len,top;
	len = s.size();
	map<char,int> mapbrackets;
	mapbrackets['{'] = 1;
	mapbrackets['['] = 2;
	mapbrackets['('] = 3;
	mapbrackets[')'] = 4;
	mapbrackets[']'] = 5;
	mapbrackets['}'] = 6;
	stack<int> mystack;
	for(int i=0;i<len;++i){
		if(mystack.empty())
			mystack.push(mapbrackets[s[i]]);
		else{
			top = mystack.top();
			if(top+mapbrackets[s[i]]==num){
				if(top<mapbrackets[s[i]])
					mystack.pop();
				else return false;
			}else{
				mystack.push(mapbrackets[s[i]]);
			}
		}
	}
	if(mystack.empty()) return true;
	else return false;
}
