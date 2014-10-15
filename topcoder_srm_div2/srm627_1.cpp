/*
 Problem Statement
     
 You found a box from an old game. The box contains a lot of sticks and a manual. Frustrated by the fact the manual was unreadable, you decided to invent your own game with the sticks. In your game, the goal is to use the sticks to build as many squares as possible. There are only two rules:
 Each stick can only be used in one square.
 Each square must consist of exactly 4 sticks. That is, you cannot combine two or more sticks to create one side of the square.
 You are given a vector <int> sticks. The elements of sticks are the lengths of the sticks you have. Return the maximum number of squares you can make.
 Definition
     
Class:
ManySquares
Method:
howManySquares
Parameters:
vector <int>
Returns:
int
Method signature:
int howManySquares(vector <int> sticks)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
If you can't make any square, return 0.
Constraints
-
sticks will contain between 1 and 50 elements.
-
Each element of sticks will be between 1 and 1000, inclusive.
Examples
0)

    
{1,1,2,2,1,1,2}
Returns: 1
You can build a square with side 1.
1)

    
{3, 1, 4, 4, 4, 10, 10, 10, 10}
Returns: 1
You can build a square with side 10. You cannot build a square with side 4. (Note that you are not allowed to use 3+1 instead of a 4.)
2)

    
{1,2,3,4,1,2,3,4,1,2,3,1,2,3,4,1,2,3,3,3}
Returns: 3

3)

    
{1,1,1,2,2,2,3,3,3,4,4,4}
Returns: 0
Sometimes you can't make any square.
4)

    
{1,1,1,2,1,1,1,3,1,1,1}
Returns: 2

5)

    
{2,2,4,4,8,8}
Returns: 0
You are also not allowed to break the sticks.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class ManySquares{
public:
	int howManySquares(vector <int> sticks);
};

int ManySquares::howManySquares(vector <int> sticks){
	int n = sticks.size();
	if(n<4) return 0;
	unordered_map<int,int> mark;
	for(int i=0;i<n;++i)
		mark[sticks[i]]++;
	int res = 0;
	for(auto it = mark.begin();it!=mark.end();++it){
		res += it->second/4;
	}
	return res;
}
