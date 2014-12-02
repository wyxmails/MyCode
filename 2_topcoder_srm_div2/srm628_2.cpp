/*
 Problem Statement
     
 We have three types of brackets: "()", "[]", and "{}". We are now interested in some special strings. A string is special if all the following conditions hold:
 Each character of the string is one of the six bracket characters mentioned above.
 The characters of the string can be divided into disjoint pairs such that in each pair we have an opening bracket and a closing bracket of the same type.
 For each pair, the opening bracket must occur to the left of the corresponding closing bracket.
 For each pair, the substring strictly between the opening and the closing bracket must be a special string (again, according to this definition).
 For example, the empty string is a special string: there are 0 pairs of brackets. The string "[]" is also a special string: there is one pair of matching brackets, they are in the proper order, and the string between them (which is the empty string) is a special string.
 The character 'X' (uppercase x) occurs in expression at most five times; all other characters in expression are brackets of the types mentioned above. We want to change expression into a special string by changing each 'X' into one of the brackets. (Different occurrences of 'X' may be changed into different brackets.) Return "possible" (quotes for clarity) if we can do that, and "impossible" otherwise.
 Definition
     
Class:
BracketExpressions
Method:
ifPossible
Parameters:
string
Returns:
string
Method signature:
string ifPossible(string expression)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
expression will have between 1 and 50 characters, inclusive.
-
Each character in expression will be '(', ')', '[', ']', '{', '}' or 'X'.
-
There will be at most 5 occurences of 'X' in expression.
Examples
0)

    
"([]{})"
Returns: "possible"
This is already a special string. As there are no 'X's, we do not get to change anything.
1)

    
"(())[]"
Returns: "possible"

2)

    
"({])"
Returns: "impossible"

3)

    
"[]X"
Returns: "impossible"
Regardless of bracket type you put instead of 'X', you cannot create a special string.
4)

    
"([]X()[()]XX}[])X{{}}]"
Returns: "possible"
You can replace 'X's respectively with '{', '(', ')' and '['.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <stack>
#include <map>
using namespace std;

class BracketExpressions{
public:
string ifPossible(string expression);
private:
bool MyCheck(stack<char>,stack<char>,map<char,int>);
};

string BracketExpressions::ifPossible(string expression){
	string pos = "possible";
	string impos = "impossible";
	int n = expression.size();
	if(n%2) return impos;
	stack<char> my_stack;
	map<char,int> mark;
	mark['('] = -1; mark[')'] = 1;
	mark['['] = -2; mark[']'] = 2;
	mark['{'] = -3; mark['}'] = 3;
	mark['X'] = 0;
	for(int i=0;i<n;++i){
		if(my_stack.empty()||mark[expression[i]]+mark[my_stack.top()]!=0)
			my_stack.push(expression[i]);
		else{
			if(mark[expression[i]]>0) my_stack.pop();
			else my_stack.push(expression[i]);
		}
	}
	stack<char> my_pair;
	if(MyCheck(my_stack,my_pair,mark)) return pos;
	return impos;
}

bool BracketExpressions::MyCheck(stack<char> my_stack,stack<char> my_pair,map<char,int> mark){
	if(my_stack.empty()&&my_pair.empty()) return true;
	if(my_stack.empty()) return false;
	if(my_pair.empty()){
		my_pair.push(my_stack.top());
		my_stack.pop();
		if(MyCheck(my_stack,my_pair,mark)) return true;
	}else if((mark[my_pair.top()]+mark[my_stack.top()]==0
				&&mark[my_pair.top()]>=0)||
				(my_pair.top()=='X'&&mark[my_stack.top()]<0)||
				(mark[my_pair.top()]>0&&my_stack.top()=='X')){
		char c1 = my_stack.top();
		char c2 = my_pair.top();
		my_stack.pop();my_pair.pop();
		if(MyCheck(my_stack,my_pair,mark)) return true;
		my_pair.push(c2);my_pair.push(c1);
		if(MyCheck(my_stack,my_pair,mark)) return true;
	}else{
		char c1 = my_stack.top();
		my_pair.push(c1);
		my_stack.pop();
		if(MyCheck(my_stack,my_pair,mark)) return true;
	}
	return false;
}
