/*
Problem Statement
    
Alice had two positive integers, a and b. She typed the expression "a+b" into her computer, but the '+' key malfunctioned. For example, instead of "128+9" the computer's screen now shows "1289".
Later, Bob saw the string on the screen. He knows that the '+' sign is missing but he does not know where it belongs. He now wonders what is the smallest possible result of Alice's original expression.
For example, if Bob sees the string "1289", Alice's expression is either "128+9" or "12+89" or "1+289". These expressions evaluate to 137, 101, and 290. The smallest of those three results is 101.
You are given a string expression that contains the expression on Alice's screen. Compute and return the smallest possible result after inserting the missing plus sign
Definition
    
Class:
ForgetfulAddition
Method:
minNumber
Parameters:
string
Returns:
int
Method signature:
int minNumber(string expression)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Constraints
-
expression will contain between 2 and 8 characters, inclusive.
-
Each character of expression will be between '1' and '9'.
Examples
0)

    
"22"
Returns: 4
The only possible expression Alice could have typed is "2+2". Thus, Bob knows this evaluates to 4.
1)

    
"123"
Returns: 15
The expression Alice has typed could have been "1+23" or "12+3". Of these two, the second is smaller, thus Bob will get the answer 15.
2)

    
"1289"
Returns: 101
This is the example from the problem statement.
3)

    
"31415926"
Returns: 9067

4)

    
"98765"
Returns: 863

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <sstream>
using namespace std;

class ForgetfulAddition{
public:
	int minNumber(string ex){
		int n = ex.size();
		int res;
		if(n%2){
			stringstream ss1(ex.substr(0,n/2));
			stringstream ss2(ex.substr(n/2));
			stringstream ss3(ex.substr(0,n/2+1));
			stringstream ss4(ex.substr(n/2+1));
			int t1,t2,t3,t4;
			ss1>>t1;
			ss2>>t2;
			ss3>>t3;
			ss4>>t4;
			res = min(t1+t2,t3+t4);
		}else{
			stringstream ss1(ex.substr(0,n/2));
			stringstream ss2(ex.substr(n/2));
			int t1,t2;
			ss1>>t1;
			ss2>>t2;
			res = t1+t2;
		}
		return res;
	}
};
