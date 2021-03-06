/*
Problem Statement
    
The currency system in Colorland consists of various types of coins. The coin denominations follow these simple rules:
The denominations are distinct positive integers.
There is a coin type with denomination 1.
For each pair of different coin types, the denomination of one coin type divides the denomination of the other one.
You are given a int[] values containing all the available denominations in ascending order.  Coins of different denominations look exactly the same except that they have different colors. Each coin in Colorland has exactly one color. The coin colors follow these even simpler rules:
All coins of the same type are of the same color.
No two coins of different types are of the same color.
You know all coin denominations used in Colorland, but you don't know their colors. You don't even know the set of colors used on the coins.  For each denomination, you'd like to know the color of coins of this denomination. To accomplish this, you've got a credit card with an infinite amount of money. You can perform a single query to an ATM which can also provide you with an infinite amount of money. The query is described by a positive integer X, which means that you want to receive exactly X units of money from the ATM. The ATM will provide you with the requested amount. You also know that the requested amount will be paid using the smallest possible number of coins. (Note that this rule always uniquely determines the set of coins chosen to make the payment.)  Return "Possible" (quotes for clarity) if it's possible to determine the color of coins of each denomination, and return "Impossible" otherwise.
Definition
    
Class:
ColorfulCoinsEasy
Method:
isPossible
Parameters:
vector <int>
Returns:
string
Method signature:
string isPossible(vector <int> values)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
values will contain between 1 and 15 elements, inclusive.
-
Each element of values will be between 1 and 20000, inclusive.
-
values will be sorted in strictly ascending order. Note that this also implies that all the elements of values will be distinct.
-
For each pair of different elements in values, the smaller one will be a divisor of the larger one.
-
values[0] will be 1.
Examples
0)

    
{1}
Returns: "Possible"
For any positive X, you'll get exactly X coins of denomination 1, so you'll easily learn their color.
1)

    
{1, 3}
Returns: "Possible"
X = 5 is one possible solution. As the ATM gives the smallest number of coins, it will give one coin of denomination 3 and two coins of denomination 1. That means, for example, that if you get one red coin and two blue coins, you'll understand that coins of denomination 3 are red, and coins of denomination 1 are blue.
2)

    
{1, 2, 4}
Returns: "Impossible"
It can be proven that for any X, you'll get at most one coin of denomination 1, and at most one coin of denomination 2. If you get no coins of some denomination, clearly you won't be able to determine their color. However, if you get one coin from each of denominations 1 and 2, you won't be able to find out which of the two colors represents which denomination.
3)

    
{1, 5, 15, 90}
Returns: "Possible"
X = 504 is one possible solution. You'll get five coins of denomination 90, three coins of denomination 15, one coin of denomination 5 and four coins of denomination 1.
4)

    
{1, 4, 20, 60, 180, 1440, 5760}
Returns: "Impossible"

5)

    
{1, 7, 21, 105, 630, 3150, 18900}
Returns: "Possible"
X = 137969 is the smallest possible solution.
6)

    
{1, 10, 30, 300, 900, 9000, 18000}
Returns: "Impossible"

7)

    
{1, 2, 10, 40, 200, 1000, 4000, 20000}
Returns: "Impossible"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ColorfulCoinsEasy{
public:
	string isPossible(vector <int> values){
		int n = values.size();
		vector<int> mark(n,0);
		for(int i=0;i+1<n;++i){
			mark[i] = values[i+1]/values[i];
		}
		sort(mark.begin(),mark.end());
		for(int i=1;i<n;++i)
			if(mark[i]<=i) return "Impossible";
		return "Possible";
	}
};
