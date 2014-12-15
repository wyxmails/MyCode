/*
Problem Statement
    
You are playing a game called Slime Tycoon. You will be selling Slimonades in this game, and your goal is to sell as many as you can.  The game will consist of N game days, numbered 0 through N-1 in order. You are given two vector <int>s morning and customers with N elements each, and an int stale_limit. These represent constraints on how many Slimonades you can produce and sell, as explained below.  In each game day, three things happen, in the following order:
Early in the morning of day i: All Slimonades that were produced stale_limit days ago (i.e., on day i-stale_limit) go stale. You cannot sell stale Slimonades, you must throw them away immediately.
During day i: You can produce at most morning[i] new Slimonades. (Formally, you choose an integer X between 0 and morning[i], inclusive, and produce X Slimonades.)
In the evening of day i: You can sell at most customers[i] Slimonades. (That is, if you have at most customers[i] Slimonades, you sell all of them. Otherwise, you sell exactly customers[i] Slimonades. In that case, you get to choose which Slimonades you sell and which ones you keep for later days.)
What is the maximum total number of Slimonades that you can sell during these N days?
Definition
    
Class:
SlimeXSlimonadeTycoon
Method:
sell
Parameters:
vector <int>, vector <int>, int
Returns:
int
Method signature:
int sell(vector <int> morning, vector <int> customers, int stale_limit)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
morning will contain between 2 and 50 elements, inclusive.
-
Each element of morning will be between 0 and 10000, inclusive.
-
customers will contain the same number of elements as morning.
-
Each element of customers will be between 0 and 10000, inclusive.
-
stale_limit will be between 1 and N, inclusive.
Examples
0)

    
{5, 1, 1}
{1, 2, 3}
2
Returns: 5
Here's one optimal solution.
Day 0: We produce 4 Slimonades, then sell 1 of them.
Day 1: We produce 1 Slimonade (so now we have 4). In the evening, we sell two of the Slimonades that were made yesterday.
Day 2: We still have one Slimonade that was made on day 0. It goes stale and we throw it away. We produce one more Slimonade. In the evening, we sell 2 Slimonades (the one made yesterday and the one made today).
1)

    
{10, 20, 30}
{30, 20, 10}
1
Returns: 40
As stale_limit=1, each evening we can only sell Slimonades made during that day. Hence, we can sell at most 10 Slimonades on day 0, 20 on day 1, and 10 on day 2.
2)

    
{1, 2, 3, 4, 5}
{5, 5, 5, 5, 5}
5
Returns: 15

3)

    
{10000, 0, 0, 0, 0, 0, 0}
{1, 2, 4, 8, 16, 32, 64}
4
Returns: 15

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class SlimeXSlimonadeTycoon{
public:
	int sell(vector <int> morning, vector <int> customers, int stale_limit){
		int n = morning.size();
		int res = 0;
		for(int i=0;i<n;++i){
			if(morning[i]<=customers[i]){
				res += morning[i];
				continue;
			}
			res += customers[i];
			morning[i] -= customers[i];
			for(int j=1;j<stale_limit&&i+j<n;++j){
				if(morning[i]>=customers[i+j]){
					res += customers[i+j];
					morning[i] -= customers[i+j];
					customers[i+j] = 0;
				}else{
					res += morning[i];
					customers[i+j] -= morning[i];
					morning[i] = 0;
				}
			}
		}
		return res;
	}
};
