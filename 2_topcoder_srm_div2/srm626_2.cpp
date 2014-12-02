/*
 Problem Statement
     
 Alice and Bob are playing a game. Alice has an a-sided die. Bob has a b-sided die. (The faces of an n-sided die have numbers 1 through n written on them.)
 The game is simple: Each player rolls their die, and the player who rolls a strictly larger number wins. (It is possible that neither player wins.)
 You are given the ints a and b. The players already rolled their dice. You do not know what numbers they rolled, but you know that Alice won the game. Compute and return the expected value of the number Alice rolled.
 Definition
     
Class:
FixedDiceGameDiv2
Method:
getExpectation
Parameters:
int, int
Returns:
double
Method signature:
double getExpectation(int a, int b)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
Your return value must have absolute or relative error smaller than 1e-9.
-
The expected value can be seen as the average of many experiments. In our case, suppose that you folow a lot of games, and each time Alice wins, you write down her score. As you watch more and more games, the average of all numbers you have written down will converge to the expected value you should return.
Constraints
-
a and b will each be between 2 and 1000, inclusive.
Examples
0)

    
2
2
Returns: 2.0
Alice can only win if she rolls a 2 and Bob rolls a 1. Thus, if we know Alice wins, we know she rolled a 2.
1)

    
4
2
Returns: 3.2

2)

    
3
3
Returns: 2.6666666666666665

3)

    
11
13
Returns: 7.999999999999999

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
using namespace std;

class FixedDiceGameDiv2{
public:
	double getExpectation(int a, int b);
};
double FixedDiceGameDiv2::getExpectation(int a, int b){
	int cnt = 0;
	double res = 0.0;
	for(int i=1;i<=b;++i){
		for(int j=i+1;j<=a;++j){
			cnt++;
			res += j;
		}
	}
	return res/(double)cnt;
}
