/*

Problem Statement
    
Frog Suwako lives on a two-dimensional plane. Currently, she is located in the point (0, 0). She would like to reach the point (x, 0).   Suwako jumps in a peculiar way: her jump lengths repeat in a periodic fashion. The vector <int> jumpLengths contains one period of her jump lengths, starting with the length of the first jump she will make. For example, if jumpLengths = { 2, 5 }, Suwako's jump lengths will be 2, 5, 2, 5, 2, 5, ... Note that Suwako can jump onto arbitrary points in the plane, they are not required to have integer coordinates.   You are given the int x and the vector <int> jumpLengths. Return the smallest non-negative integer j such that Suwako can reach the desired destination after j jumps. If there is no such j, return -1 instead.
Definition
    
Class:
PeriodicJumping
Method:
minimalTime
Parameters:
int, vector <int>
Returns:
int
Method signature:
int minimalTime(int x, vector <int> jumpLengths)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-
jumpLengths will contain between 1 and 50 elements, inclusive.
-
Each element in len will be between 1 and 1,000,000,000, inclusive.
Examples
0)

    
15
{1,2,3,4,5,6,7,8,9,10}
Returns: 5
In 4 jumps Suwako cannot get far enough. In 5 jumps she can reach the destination as follows: (0,0) -> (1,0) -> (3,0) -> (6,0) -> (10,0) -> (15,0).
1)

    
5
{5}
Returns: 1
One jump is enough, since the distance between (0,0) and (5,0) is exactly 5.
2)

    
1
{10}
Returns: 2
Here Suwako needs two jumps. One possible solution is to land at (0.5, sqrt(10*10-0.5*0.5)) after the first jump.
3)

    
-10
{2,3,4,500,6,7,8}
Returns: 11

4)

    
-1000000000
{1}
Returns: 1000000000

5)

    
0
{19911120}
Returns: 0

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class PeriodicJumping{
public:
	int minimalTime(int x, vector <int> jump){
		if(x==0) return 0;
		if(x<0) x = -x;
		int n = jump.size();
		long long sum = 0;
		for(int i=0;i<n;++i) sum += jump[i];
		if(sum==0) return -1;
		if(x%sum==0) return (x/sum)*n;
		int cur;
		if(sum>x){
			cur=0;sum=0;
		}else{
			cur = (x/sum)*n;
			sum = sum*(x/sum);
		}
		while(sum<x){
			sum += jump[cur%n];
			cur++;
			if(sum==x) return cur;
		}
		sum += x;
		bool reach = true;
		do{
			reach = true;
			for(int i=0;i<min(n,cur);++i){
				if((long long)jump[i]*2>sum){
					reach = false;
					break;
				}
			}
			if(!reach){
				sum += jump[cur%n];
				cur++;
			}
		}while(!reach);
		return cur;
	}
};
