/*
 Problem Statement
     
 You have an ordered pair of integers. You can now make zero or more steps. In each step, you can change your pair into a new pair of integers by adding one of them to the other. That is, if your current pair is (x, y), then your next pair will be either (x+y, y), or (x, x+y).   For example, you can start with (1, 2), change it to (3, 2), change that to (3, 5), and then change that again to (3, 8).   You are given four ints: a, b, c, and d. Return "Able to generate" (quotes for clarity) if it is possible to start with the pair (a, b) and end with the pair (c, d). Otherwise, return "Not able to generate".
 Definition
     
Class:
PairGameEasy
Method:
able
Parameters:
int, int, int, int
Returns:
string
Method signature:
string able(int a, int b, int c, int d)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
a will be between 1 and 1,000, inclusive.
-
b will be between 1 and 1,000, inclusive.
-
c will be between 1 and 1,000, inclusive.
-
d will be between 1 and 1,000, inclusive.
Examples
0)

    
1
2
3
5
Returns: "Able to generate"
(1, 2) -> (3, 2) -> (3, 5).
1)

    
1
2
2
1
Returns: "Not able to generate"
Note that order matters: (1, 2) and (2, 1) are two different pairs.
2)

    
2
2
2
999
Returns: "Not able to generate"

3)

    
2
2
2
1000
Returns: "Able to generate"

4)

    
47
58
384
221
Returns: "Able to generate"

5)

    
1000
1000
1000
1000
Returns: "Able to generate"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
using namespace std;

class PairGameEasy{
public:
	string able(int a, int b, int c, int d);
};
bool MyPair(int a,int b,int c,int d){
	if(a>c||b>d) return false;
	if(a==c&&b==d) return true;
	if(MyPair(a+b,b,c,d)) return true;
	if(MyPair(a,a+b,c,d)) return true;
	return false;
}

string PairGameEasy::able(int a, int b, int c, int d){
	string res_able = "Able to generate";
	string res_notable = "Not able to generate";
	if(MyPair(a,b,c,d)) return res_able;
	return res_notable;
}
