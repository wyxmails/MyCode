/*
Problem Statement
    
In most programming languages variable names cannot contain spaces. If we want a variable name that consists of two or more words, we have to encode the spaces somehow. In this problem, we will look at two ways of doing so: Snake Case and Camel Case. When using Snake Case, we just replace each space by an underscore ('_'). When using Camel Case, we capitalize the first letter of each word except for the first one, and then we remove all spaces.   For example, suppose that we want to declare a variable called "good morning world" (quotes for clarity). In Snake Case, we would write this variable as "good_morning_world", while in Camel Case it would be "goodMorningWorld".   You are given a string variableName. This string contains a valid variable name written in Snake Case. Return the same variable name in Camel Case.
Definition
    
Class:
NamingConvention
Method:
toCamelCase
Parameters:
string
Returns:
string
Method signature:
string toCamelCase(string variableName)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
variableName will contain between 1 and 50 characters.
-
Each character of variableName will be 'a'-'z' or '_'.
-
The first and last character of variableName will not be '_'.
-
variableName will not contain two consecutive underscores ('_').
Examples
0)

    
"sum_of_two_numbers"
Returns: "sumOfTwoNumbers"
We have 4 words: "sum", "of", "two", "numbers". So the answer is "sum" + "Of" + "Two" + "Numbers".
1)

    
"variable"
Returns: "variable"
Note that if we have only 1 word, then the varaible name will remain same.
2)

    
"t_o_p_c_o_d_e_r"
Returns: "tOPCODER"

3)

    
"the_variable_name_can_be_very_long_like_this"
Returns: "theVariableNameCanBeVeryLongLikeThis"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

class NamingConvention{
public:
	string toCamelCase(string variableName){
		int n = variableName.size();
		string res = "";
		res.append(n,' ');
		int c=0;
		for(int i=0;i<n;++i){
			if(i==0||variableName[i]!='_') res[c++] = variableName[i];
			else{
				i++;
				res[c++] = toupper(variableName[i]);
			}
		}
		res.resize(c);
		return res;
	}
};
