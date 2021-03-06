/*
Problem Statement
    
Alex is sleeping soundly. At any moment, his sleepiness can be characterized by an integer. You are given an int S that represents Alex's initial sleepiness.  Unfortunately, several alarms are going to disturb him. These alarms will be ringing in a cyclic order. Each alarm is characterized by its volume.  You are given a list of alarm volumes in a vector <int> volume in the order in which the alarms are going to ring. Every minute the first alarm on the list rings, and Alex's sleepiness instantly decreases by its volume. The alarm is then moved to the end of the alarm list.  While Alex's sleepiness is positive, he's still sleeping. Once it becomes less than or equal to zero, Alex immediately wakes up.  Return the number of alarms after which Alex will wake up.
Definition
    
Class:
WakingUpEasy
Method:
countAlarms
Parameters:
vector <int>, int
Returns:
int
Method signature:
int countAlarms(vector <int> volume, int S)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
volume will contain between 1 and 50 elements, inclusive.
-
Each element of volume will be between 1 and 100, inclusive.
-
S will be between 1 and 10000, inclusive.
Examples
0)

    
{5, 2, 4}
13
Returns: 4
Initially, Alex's sleepiness is 13, and the list of alarms is {5, 2, 4}.
After the first alarm, Alex's sleepiness is 8. The list of alarms becomes {2, 4, 5}.
After the second alarm, Alex's sleepiness is 6. The list of alarms becomes {4, 5, 2}.
After the third alarm, Alex's sleepiness is 2. The list of alarms becomes {5, 2, 4}.
After the fourth alarm, Alex's sleepiness is -3, so Alex wakes up.
1)

    
{5, 2, 4}
3
Returns: 1
The first alarm is enough here.
2)

    
{1}
10000
Returns: 10000
The only alarm has to ring 10000 times before Alex finally wakes up.
3)

    
{42, 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37,
  92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36,
  95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69}
9999
Returns: 203

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
#include <vector>
using namespace std;

class WakingUpEasy{
public:
	int countAlarms(vector <int> volume, int S){
		if(S<=0) return 0;
		int n = volume.size();
		int cnt = 0;
		for(int i=0;S>0;i=(i+1)%n){
			cnt++;
			S -= volume[i];
		}
		return cnt;
	}
};
