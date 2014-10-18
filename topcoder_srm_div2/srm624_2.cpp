/*
 Problem Statement
     
 Byteland is a city with many skyscrapers, so it's a perfect venue for BASE jumping. Danilo is an enthusiastic BASE jumper. He plans to come to Byteland and to jump off some of its buildings.
  
 Danilo wants to make M jumps in Byteland. However, he has some rules. First, he never jumps off the same building twice. Second, all buildings he selects for his jumps must have the same number of floors. (This is for safety reasons: It is hard to get the timing right if each jump starts at a different height.)
  
 Philipe is the mayor of Byteland. He welcomes Danilo's visit as he would like to use it as a publicity stunt. However, Philipe knows that Danilo will only come to Byteland if there are at least M buildings that each have the same number of floors. To ensure that, the mayor is willing to build additional floors on some of the skyscrapers in Byteland.
  
 You are given the int M and a vector <int> heights. Each element of heights is the number of floors in one of Byteland's skyscrapers. Compute and return the smallest number of additional floors the mayor has to build so that there will be at least M buildings with the same number of floors.
 Definition
     
Class:
BuildingHeightsEasy
Method:
minimum
Parameters:
int, vector <int>
Returns:
int
Method signature:
int minimum(int M, vector <int> heights)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
heights will contain between 1 and 50 elements, inclusive.
-
M will be between 1 and the number of elements in heights, inclusive.
-
Each element in heights will be between 1 and 50, inclusive.
Examples
0)

    
2
{1, 2, 1, 4, 3}
Returns: 0
Note that we already have two buildings that have the same number of floors. Hence, no additional floors need to be built.
1)

    
3
{1, 3, 5, 2, 1}
Returns: 2
We want to have at least three buildings with the same number of floors. The best way to reach this goal is to build one floor on building #0 and one floor on building #4 (0-based indices). After these changes, buildings #0, #3, and #4 will have two floors each.
2)

    
1
{43, 19, 15}
Returns: 0

3)

    
3
{19, 23, 9, 12}
Returns: 15

4)

    
12
{25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4}
Returns: 47

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class BuildingHeightsEasy{
public:
	int minimum(int M, vector <int> heights);
};

int BuildingHeightsEasy::minimum(int M, vector <int> heights){
	int n = heights.size();
	sort(heights.begin(),heights.end());
	int mini = INT_MAX;
	int sum = 0;
	for(int i=0;i+1<M&&i<n;++i) sum += heights[i]; 
	for(int i=M-1;i<n;++i){
		int expect = heights[i]*M;
		sum += heights[i];
		if(i-M>=0) sum -= heights[i-M];
		if(expect==sum) return 0;
		else if(expect-sum<mini) mini = expect-sum;
	}
	return mini;
}
