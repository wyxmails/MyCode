/*

Problem Statement
    
Janusz works in roller coaster maintenance. The station of the roller coaster is a long straight segment of railroad tracks. There are some cars on those tracks. The cars are currently not attached to each other, and there may be gaps between some of them. Janusz has to push them all together and connect them into a train.
You are given the vector <int>s positions and lengths. For each valid i, there is a car that is lengths[i] meters long and starts positions[i] meters from the beginning of the station. (In other words, the coordinates currently occupied by this car are in the interval from positions[i] to positions[i]+lengths[i].)
Moving a single car one meter in either direction costs Janusz one unit of energy. Compute the smallest total amount of energy sufficient to push all cars together. In the final configuration the cars must be located one after another with no gaps between them.
(Note that there is no restriction on the movement of cars or on the final position of the train. Janusz may push the cars in any order, and he may even push some cars by a non-integer number of meters if he wants to.)
Definition
    
Class:
ConnectingCars
Method:
minimizeCost
Parameters:
vector <int>, vector <int>
Returns:
long long
Method signature:
long long minimizeCost(vector <int> positions, vector <int> lengths)
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
You may assume that the optimal answer is always an integer that fits into a signed 64-bit integer data type.
Constraints
-
lengths and positions will have the same number of elements.
-
lengths will have between 2 and 50 elements, inclusive.
-
Each element of lengths and positions will be between 1 and 10^9, inclusive.
-
The segments occupied by the cars may touch but they will not overlap.
Examples
0)

    
{1, 3, 10, 20}
{2, 2, 5, 3}
Returns: 15
There are four cars. The intervals currently occupied by the cars are (1,3), (3,5), (10,15), and (20,23). In one optimal solution Janusz would move each of the first two cars three meters to the right, the third car two meters to the left, and the fourth car seven meters to the left. At the end, the cars occupy the intervals (4,6), (6,8), (8,13), and (13,16). Total energy spent: 3+3+2+7 = 15.
1)

    
{100, 50, 1}
{10, 2, 1}
Returns: 96
There are three cars. The gaps between consecutive cars have 48 meters each. The best solution is to keep the middle car in place and to push the other two towards it. This requires 48+48 = 96 units of energy.
2)

    
{4, 10, 100, 13, 80}
{5, 3, 42, 40, 9}
Returns: 66

3)

    
{5606451, 63581020, 81615191, 190991272, 352848147, 413795385, 468408016, 615921162, 760622952, 791438427}
{42643329, 9909484, 58137134, 99547272, 39849232, 15146704, 144630245, 604149, 15591965, 107856540}
Returns: 1009957100

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ConnectingCars{
public:
	long long minimizeCost(vector <int> positions, vector <int> lengths){
		int n = positions.size();
		vector<pair<int,int> > mark(n);
		for(int i=0;i<n;++i)
			mark[i] = make_pair(positions[i],positions[i]+lengths[i]);
		sort(mark.begin(),mark.end());
		long long res = 0;
		for(int i=0;i<n;++i){
			long long mid = 0;
			long long left=mark[i].first,right=mark[i].second;
			for(int j=i-1;j>=0;--j){
				if(mark[j].second<left)
					mid += (left-mark[j].second);
				left = mark[j].first+(left-mark[j].second);
			}
			for(int j=i+1;j<n;++j){
				if(mark[j].first>right)
					mid += (mark[j].first-right);
				right = mark[j].second-(mark[j].first-right);
			}
			if(i==0) res = mid;
			else res = min(res,mid);
		}
		return res;
	}
};
