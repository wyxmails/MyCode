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
bool isValid2(string s) {
        int n = s.size();
        if(n==0) return true;
        stack<char> myStack;
        for(int i=0;i<n;++i){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                myStack.push(s[i]);
            }else{
                if(myStack.empty()) return false;
                if(s[i]==')'&&myStack.top()!='(') return false;
                if(s[i]==']'&&myStack.top()!='[') return false;
                if(s[i]=='{'&&myStack.top()!='{') return false;
                myStack.pop();
            }
        }
        return myStack.empty();
}
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> mark;
        mark['('] = -1; mark[')'] = 1;
        mark['['] = -2; mark[']'] = 2;
        mark['{'] = -3; mark['}'] =3;
        int n = s.size();
        stack<int> ms;
        for(int i=0;i<n;++i){
            if(ms.empty()||mark[s[i]]<0) ms.push(i);
            else{
                int t = ms.top();
                ms.pop();
                if(mark[s[t]]+mark[s[i]]!=0) return false;
            }
        }
        return ms.empty();
    }
};
