/*
 Problem Statement
     
 Shiny wants to give an award to one of the employees in her company. However, all her employees are doing perfect work, so it's hard to pick the one that gets the award. Therefore Shiny organized a game they will play to determine the winner.
  
 At the beginning of the game, all N employees form a circle. Then, they receive t-shirts with numbers 1 through N in clockwise order along the circle. These numbers are never used in the game, we will just use them to identify the winner.
  
 The game is played in turns. The turns are numbered starting from 1. In each turn, Shiny starts by standing in front of some employee (as specified below) and saying "one". Then she moves clockwise along the circle to the next employee and says "two". And so on, until the number she says reaches the threshold for that particular turn. The threshold for turn number t is t^3. (That is, the threshold is 1 for turn 1, 8 for turn 2, 27 for turn 3, and so on.)
  
 At the end of each turn, the employee currently standing in front of Shiny (i.e., the one that received the number t^3) is eliminated. In the very first round Shiny starts in front of the employee with the number 1 on their t-shirt. In each of the following rounds, Shiny starts in front of the next employee clockwise from the one who just got eliminated.
  
 When there is only one employee left in the game, the game ends and the employee wins the award.
  
 You are given the int N. Return the t-shirt number of the employee who gets the award.
 Definition
     
Class:
ChooseTheBestOne
Method:
countNumber
Parameters:
int
Returns:
int
Method signature:
int countNumber(int N)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
N will between 1 and 5000, inclusive.
Examples
0)

    
3
Returns: 2
In the first round, Shiny stands in front of employee 1, says "one" and eliminates him. In the second round, Shiny starts in front of employee 2. She says "one" to employee 2, "two" to employee 3, "three" to employee 2 again, ..., and "eight" to employee 3. Thus, employee 3 gets eliminated and employee 2 wins the award.
1)

    
6
Returns: 6

2)

    
10
Returns: 8

3)

    
1234
Returns: 341

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
using namespace std;

class ChooseTheBestOne{
public:
	int countNumber(int N);
};

int ChooseTheBestOne::countNumber(int N){
	vector<int> vec(N);
	for(int i=0;i<N;++i)
		vec[i] = i+1;
	int pre = 0;
	for(int i=1;i<N;++i){
		int j = (i*i)%(N-i+1);
		j = (j*i)%(N-i+1);
		j = (j+pre-1+N-i+1)%(N-i+1);
		vec.erase(vec.begin()+j);
		pre = j%(N-i);
	}
	return vec[0];
}
