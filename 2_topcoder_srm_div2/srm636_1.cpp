/*
 Problem Statement
     
 Limak has found a large field with some piles of stones.
  
 Limak likes perfection. It would make him happy if every pile had the same number of stones. He is now going to move some stones between the piles to make them all equal.
  
 However, there is a catch. Limak's perfectionism does not allow him to carry just one stone at a time. As he has two hands, he must always carry exactly two stones: one in each hand. Thus, he can only make one type of an action: pick up two stones from one of the piles and carry both of them to some other pile. He is not allowed to remove a pile completely. Therefore, he cannot pick up stones from a pile that currently contains fewer than 3 stones.
  
 You are given a vector <int> stones. Each element of stones is the initial number of stones in one of the piles. Compute and return the smallest number of actions Limak has to perform in order to make all piles equal. If it is impossible to make all piles equal using the allowed type of actions, return -1 instead.
 Definition
     
Class:
GameOfStones
Method:
count
Parameters:
vector <int>
Returns:
int
Method signature:
int count(vector <int> stones)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
stones will contain between 1 and 100 elements, inclusive. 
-
Each element in stones will be between 1 and 100, inclusive.
Examples
0)

    
{7, 15, 9, 5}
Returns: 3
There are four piles of stones. There are 7 stones in pile number 0, 15 stones in pile number 1, 9 stones in pile number 2, and 5 stones in pile number 3. One optimal solution looks as follows: First, Limak will move a pair of stones from pile 1 to pile 0. Afterwards, Limak will twice move a pair of stones from pile 1 to pile 3. After these 3 actions, each pile contains exactly 9 stones.
1)

    
{10, 16}
Returns: -1
It can be proven that Limak can't make these two piles equal.
2)

    
{2, 8, 4}
Returns: -1

3)

    
{17}
Returns: 0
Limak doesn't need to perform any actions. There is only one pile and it means that all piles already have the same size.
4)

    
{10, 15, 20, 12, 1, 20}
Returns: -1

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class GameOfStones{
public:
int count(vector <int> stones);
};
int GameOfStones::count(vector <int> stones){
	int sum = 0;
	int n = stones.size();
	if(n==0) return 0;
	for(int i=0;i<n;++i)
		sum += stones[i];
	if(sum%n) return -1;
	int target = sum/n;
	int res = 0;
	for(int i=0;i<n;++i){
		int sub = abs(stones[i]-target);
		if(sub%2) return -1;
		res += sub/2;
	}
	if(res%2) return -1;
	return res/2;
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	vector<int> vec;
	int n = rand()%5;
	cout << "n: " << n << endl;
	for(int i=0;i<n;++i){
		int tmp = rand()%20;
		vec.push_back(tmp);
		cout << tmp << " ";
	}
	cout << endl;
	GameOfStones gs;
	cout << gs.count(vec) << endl;
	return 0;
}
