/*
 Problem Statement
     
 Alice went jogging around the park yesterday. There is a circular track around the park, and Alice's house is right next to the track. Alice ran in the clockwise direction. She both started and ended her run at her house. In other words, she completed some positive number of full laps.
 There are N trees along the track. The trees are numbered 1 through N in the order in which Alice encounters them when running a single lap. You are given the int N.
 Alice remembers some trees she saw during her run. She remembers them in the order in which she encountered them. You are given this information as a vector <int> d.
 For example, d={6,6,1} has the following meaning:
 Alice started running.
 After some time she encountered the tree number 6.
 After some more time she encountered the tree number 6.
 Even later she encountered the tree number 1.
 Compute and return the smallest possible number of laps Alice completed.
 Definition
     
Class:
RunningAroundPark
Method:
numberOfLap
Parameters:
int, vector <int>
Returns:
int
Method signature:
int numberOfLap(int N, vector <int> d)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
N will be between 2 and 50, inclusive.
-
d will contain between 1 and 50 elements.
-
Each element of d will be between 1 and N, inclusive.
Examples
0)

    
3
{1,2,3}
Returns: 1
It is possible that Alice ran just a single lap and remembered all the trees she saw.
1)

    
24
{6,6}
Returns: 2
Alice ran past the tree number 6 at least twice, so there must have been at least two laps.
2)

    
3
{3,2,1}
Returns: 3

3)

    
50
{1,3,5,7,9,2,4,6,8,10}
Returns: 2

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
using namespace std;

class RunningAroundPark{
public:
	int numberOfLap(int N, vector <int> d);
};

int RunningAroundPark::numberOfLap(int N, vector <int> d){
	int n = d.size();
	if(n==0) return 0;
	int round=1;
	for(int i=1;i<n;++i){
		if(d[i]>N) return -1;
		if(d[i]<=d[i-1]) round++;
	}
	return round;
}
