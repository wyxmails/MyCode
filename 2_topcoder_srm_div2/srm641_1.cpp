/*
Problem Statement
    
A local store is selling T-shirts with the face of Fox Ciel printed on them. Each such T-shirt costs T pesos. Quimey and Pablo love those T-shirts. They each buy a new T-shirt whenever they have the money to do so. Currently, Quimey and Pablo have no money at all. During the following N days they are going to earn some money and they will use it to buy the T-shirts. The days are numbered from 0 (today) to N-1 (the day N-1 days in the future). For each valid i, Q[i] and P[i] are the amounts in pesos Quimey and Pablo will earn on day i. (Note that each of those amounts is at most T. Therefore, Quimey and Pablo will be able to buy at most one T-shirt each day.) For example, suppose that a T-shirt costs T=10 pesos. If Q={2,3,5,10}, the following will happen to Quimey:
On day 0, he earns 2 pesos. He now has 2 pesos.
On day 1, he earns 3 pesos. He now has 5 pesos.
On day 2, he earns 5 pesos. He now has 10 pesos, which is enough to buy a T-shirt. He goes to the store and buys one. Afterwards, he has 0 pesos left.
On day 3, he earns 10 pesos. He then goes to buy a second T-shirt. Afterwards, he again has 0 pesos left.
If P={10,8,6,4}, Pablo would buy one T-shirt on day 0, and then another T-shirt on day 2. After buying the T-shirt on day 2 he would have 4 pesos left. After day 3 he would then have a total of 8 pesos, which is still not enough for a T-shirt. Note that in this example Quimey and Pablo would go to the store together on day 2. You are given the int T: the price of a single T-shirt. You are also given the vector <int>s Q and P with N elements each: the amounts Quimey and Pablo earn each day. Compute and return the number of days on which Quimey and Pablo both go to the store
Definition
    
Class:
BuyingTshirts
Method:
meet
Parameters:
int, vector <int>, vector <int>
Returns:
int
Method signature:
int meet(int T, vector <int> Q, vector <int> P)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Notes
-
If you need the number N in your solution, you can determine it as the number of elements in Q.
Constraints
-
T will be between 1 and 100.
-
Q will contain between 1 and 100 elements.
-
Q and P will contain the same number of elements.
-
Each element of Q will be between 1 and T.
-
Each element of P will be between 1 and T.
Examples
0)

    
5
{1,2,3,4,5}
{5,4,3,2,1}
Returns: 2
Quimey will buy his T-shirts on days 2, 3, and 4. Pablo will buy his on days 0, 2, and 4. They will go to the store together twice: first on day 2 and then on day 4.
1)

    
10
{10,10,10}
{10,10,10}
Returns: 3

2)

    
2
{1,2,1,2,1,2,1,2}
{1,1,1,1,2,2,2,2}
Returns: 5
They will both go to the store on the following days: 1, 3, 5, 6, and 7.
3)

    
100
{1,2,3}
{4,5,6}
Returns: 0
In this test case they do not buy any T-shirts at all.
4)

    
10
{10,1,10,1}
{1,10,1,10}
Returns: 0

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class BuyingTshirts{
public:
	int meet(int T, vector <int> Q, vector <int> P){
		int res=0;
		int curQ,curP;
		curQ=0; curP=0;
		int n = Q.size();
		for(int i=0;i<n;++i){
			curQ += Q[i];
			curP += P[i];
			if(curQ>=T&&curP>=T){
				res++;
				curQ -= T;
				curP -= T;
			}else{
				if(curQ>=T) curQ -= T;
				else if(curP>=T) curP -= T;
			}
		}
		return res;
	}
};
