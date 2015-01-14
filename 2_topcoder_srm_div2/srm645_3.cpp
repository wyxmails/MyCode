/*

Problem Statement
    
Janusz is in a casino with some friends. Their group consists of n people. They are all going to play a game.
The game is played on a plan that is divided into m fields. At the beginning of the game, each player gets their own unique token. The game then consists of k rounds. Each round looks as follows:
Each player places their token onto one of the fields.
One of the fields is chosen uniformly at random.
The tokens in the chosen field are removed from the game. The players who placed those tokens are out of the game.
The players who are still in the game after the last round win the game.
Our group of players wants to maximize the probability that at least one of them wins the game. You are given the long long n and the ints m and k. Compute and return the probability that there will be at least one winner if they play the game optimally.
Definition
    
Class:
JanuszInTheCasino
Method:
findProbability
Parameters:
long long, int, int
Returns:
double
Method signature:
double findProbability(long long n, int m, int k)
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
The return value must have an absolute error at most 1e-3.
Constraints
-
n will be between 1 and 10^12, inclusive.
-
m and k will be between 1 and 50, inclusive.
Examples
0)

    
3
2
2
Returns: 0.75
There are 3 players, 2 fields on the plan, and 2 rounds of the game. In the first round the players should place one token onto the first field and two tokens onto the second field.
With probability 0.5 the first field is chosen. If that happens, there will be two players in the second round. Each of them will choose a different field and thus one of them will certainly win the game.
With probability 0.5 the second field is chosen in the first round. If that happens, there will only be a single player in the second round. The probability that this player survives the second round is 0.5.
Hence, the answer is 0.5*1 + 0.5*0.5 = 0.75.
1)

    
1
3
3
Returns: 0.2962962962962962
There is only one player: Janusz. He will survive each round with probability 2/3. Hence, the probability that he will win the entire game is (2/3)^3.
2)

    
4
3
2
Returns: 1.0
One optimal strategy for the first round is to put two tokens onto one field and one token onto each of the other two fields. Even if we lose the two tokens, we will still have two players in the second round and we can make sure that at least one of them will win the game.
3)

    
5
4
5
Returns: 0.87109375

4)

    
1000000000000
2
40
Returns: 0.9094947017729282

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class JanuszInTheCasino{
public:
	double findProbability(long long n, int m, int k){
		if(n==0) return 0;
		if(k==0) return 1.0;
		if(mark.find({n,k})!=mark.end()) return mark[{n,k}];
		long long left = n%m;
		long long cur = n/m;
		double rate = (left*1.0)/(m*1.0);
		double ret = rate*findProbability(n-cur-1,m,k-1);
		ret += (1.0-rate)*findProbability(n-cur,m,k-1);
		mark[{n,k}] = ret;
		return ret;
	}
private:
	map<pair<long long,int>,double> mark;
};
