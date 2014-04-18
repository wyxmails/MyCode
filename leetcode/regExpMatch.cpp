/*Regular Expression Matching
   Implement regular expression matching 
   with support for '.' and '*'.
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 The matching should cover the entire input string (not partial).
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 Some examples:
 isMatch("aa","a") ? false
 isMatch("aa","aa") ? true
 isMatch("aaa","aa") ? false
 isMatch("aa", "a*") ? true
 isMatch("aa", ".*") ? true
 isMatch("ab", ".*") ? true
 isMatch("aab", "c*a*b") ? true
 */
bool isMatch(const char *s, const char *p) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function    
	char c;
	int i=0,j=0,t1,t2;
	if(s[i]=='\0'){
		while(p[j]!='\0'&&(p[j]=='*'||p[j+1]=='*'))  // judge *,.*,a*
			j++;
		if(p[j]=='\0') return true;
		else return false;
	}
	if(p[j]=='\0'&&s[i]!='\0') return false;  //judge 
	if(s[i]==p[j]){  //equal
		if(p[j+1]=='*'){  //next is *
			t1 = i;
			t2 = 0;
			while(s[i]==p[j]) i++;
			c = p[j];
			while(p[j]==c||p[j]=='*'){
				j++;
				if(p[j]==c&&p[j+1]!='*') t2++;
			}
			if(t2>(i-t1)) return false; //if p contains more c than s
			else{
				for(;t1<=i;++t1)  //c* replace 0~n of c in string s
				if(isMatch(&s[t1],&p[j])) return true;
				return false;
			} 
		}else return isMatch(&s[i+1],&p[j+1]); // go on
	}else{ // not equal
		if(p[j]=='*') return isMatch(&s[i],&p[j+1]);  // ignore *
		else if(p[j]=='.'){
			if(p[j+1]=='*'){ // process .*
				if(isMatch(&s[i+1],&p[j])  //.* replace n>1 char in s
					||isMatch(&s[i+1],&p[j+2]) //.* replace 1 char in s
					||isMatch(&s[i],&p[j+2]))  //.* replace 0 char in s
					return true;
				else return false;
			}else   //. replace 1 char
				return isMatch(&s[i+1],&p[j+1]);
		}else if(p[j+1]=='*'){  // process c*
			return isMatch(&s[i],&p[j+2]);
		}else return false;  // cx not match cy, return false
	}
}
