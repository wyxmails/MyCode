/*
 Problem Statement
     
 You are given a vector <int> array. At any moment, you may choose a nonempty contiguous subsequence of array. Whenever you do so, you will gain power equal to the sum of all elements in the chosen subsequence.
 You chose each possible contiguous subsequence exactly once, each time gaining some power. Compute and return the total amount of power you gained.
 Definition
     
Class:
SumOfPower
Method:
findSum
Parameters:
vector <int>
Returns:
int
Method signature:
int findSum(vector <int> array)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
array will contain between 1 and 50 elements, inclusive.
-
Each element in array will be between 1 and 100, inclusive.
Examples
0)

    
{1,2}
Returns: 6
We have the following three contiguous subsequences:
{1} => 1
{2} => 2
{1,2} => 3
Thus, the sum of all possible powers is 1+2+3=6.
1)

    
{1,1,1}
Returns: 10
A 3-element sequence has 6 possible nonempty contiguous subsequences. For the sequence {1,1,1} these are the subsequences: {1}, {1}, {1}, {1,1}, {1,1}, and {1,1,1}. Their sums are 1, 1, 1, 2, 2, and 3. If you choose each of them once, the total power you'll gain is 1+1+1+2+2+3 = 10.
2)

    
{3,14,15,92,65}
Returns: 1323

3)

    
{1,2,3,4,5,6,7,8,9,10}
Returns: 1210

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
using namespace std;

class SumOfPower{
public:
	int findSum(vector <int> array);
};

int SumOfPower::findSum(vector <int> array){
	int n = array.size();
	int sum=0;
	int cnt=0;
	for(int i=0;i<n/2;++i){
		cnt += n-2*i;
		sum += cnt*array[i];
		sum += cnt*array[n-i-1];
	}
	if(n%2) sum += (cnt+1)*array[n/2];
	return sum;
}
