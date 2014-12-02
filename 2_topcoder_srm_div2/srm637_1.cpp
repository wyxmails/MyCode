/*
 Problem Statement
     
 Cat Snuke and wolf Sothe are playing the Greater Game. The game is played with cards. Each card has a number written on it. There are 2N cards. The numbers on the cards are the integers between 1 and 2N, inclusive.
  
 At the beginning of the game, each player gets N of the cards and chooses the order in which he wants to play them. The game then consists of N turns. In each turn, both players play one of their cards simultaneously. The player who revealed the card with the larger number gets a point.
  
 You are given two vector <int>s: snuke and sothe. The elements of snuke are the numbers on the cards Snuke is going to play, in order. Similarly, the elements of sothe are the numbers on the cards Sothe is going to play, in order. Compute and return the number of points Snuke will have at the end of the game.
 Definition
     
Class:
GreaterGameDiv2
Method:
calc
Parameters:
vector <int>, vector <int>
Returns:
int
Method signature:
int calc(vector <int> snuke, vector <int> sothe)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
N will be between 1 and 50, inclusive.
-
snuke and sothe will contain exactly N elements each.
-
Each integer in snuke and sothe will be between 1 and 2N, inclusive.
-
The integers in snuke and sothe will be distinct.
Examples
0)

    
{1,3}
{4,2}
Returns: 1
Snuke loses the first round because 1 is less than 4. Snuke then wins the second round because 3 is greater than 2.
1)

    
{1,3,5,7,9}
{2,4,6,8,10}
Returns: 0

2)

    
{2}
{1}
Returns: 1

3)

    
{3,5,9,16,14,20,15,17,13,2}
{6,18,1,8,7,10,11,19,12,4}
Returns: 6

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GreaterGameDiv2{
public:
	int calc(vector <int> snuke, vector <int> sothe);
};

int GreaterGameDiv2::calc(vector <int> snuke, vector <int> sothe){
	int n = snuke.size();
	int points=0;
	for(int i=0;i<n;++i){
		if(snuke[i]>sothe[i]) points++;
	}
	return points;
}
