/*

Problem Statement
    
A well-known riddle goes like this: Four people are crossing an old bridge. The bridge cannot hold more than two people at once. It is dark, so they can't walk without a flashlight, and they only have one flashlight! Furthermore, the time needed to cross the bridge varies among the people in the group. For instance, let's say that the people take 1, 2, 5 and 10 minutes to cross the bridge. When people walk together, they always walk at the speed of the slowest person. It is impossible to toss the flashlight across the bridge, so one person always has to go back with the flashlight to the others. What is the minimum amount of time needed to get all the people across the bridge?
In this instance, the answer is 17. Person number 1 and 2 cross the bridge together, spending 2 minutes. Then person 1 goes back with the flashlight, spending an additional one minute. Then person 3 and 4 cross the bridge together, spending 10 minutes. Person 2 goes back with the flashlight (2 min), and person 1 and 2 cross the bridge together (2 min). This yields a total of 2+1+10+2+2 = 17 minutes spent.
You want to create a computer program to help you solve new instances of this problem. Given an vector <int> times, where the elements represent the time each person spends on a crossing, your program should return the minimum possible amount of time spent crossing the bridge.
Definition
    
Class:
BridgeCrossing
Method:
minTime
Parameters:
vector <int>
Returns:
int
Method signature:
int minTime(vector <int> times)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
In an optimal solution, exactly two people will be sent across the bridge with the flashlight each time (if possible), and exactly one person will be sent back with the flashlight each time. In other words, in an optimal solution, you will never send more than one person back from the far side at a time, and you will never send less than two people across to the far side each time (when possible).
Constraints
-
times will have between 1 and 6 elements, inclusive.
-
Each element of times will be between 1 and 100, inclusive.
Examples
0)

    
{ 1, 2, 5, 10 }
Returns: 17
The example from the text.
1)

    
{ 1, 2, 3, 4, 5 }
Returns: 16
One solution is: 1 and 2 cross together (2min), 1 goes back (1min), 4 and 5 cross together (5min), 2 goes back (2min), 1 and 3 cross together (3min), 1 goes back (1min), 1 and 2 cross together (2min). This yields a total of 2 + 1 + 5 + 2 + 3 + 1 + 2 = 16 minutes spent.
2)

    
{ 100 }
Returns: 100
Only one person crosses the bridge once.
3)

    
{ 1, 2, 3, 50, 99, 100 }
Returns: 162

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <climits>

using namespace std;
class BridgeCrossing {
public:
    int minTime(vector<int> times) {
    	vector<int> right;
        return myMin(times,right);
    }
    int myMin(vector<int> left,vector<int> right){
    	int n = left.size();
        if(n==2) return max(left[0],left[1]);
        if(n==1) return left[0];
        if(n<=0) return 0;
        int res = INT_MAX;
        for(int i=0;i<n;++i){
        	for(int j=i+1;j<n;++j){
        		vector<int> curL = left;
        		curL.erase(curL.begin()+i);
        		curL.erase(curL.begin()+j-1);
        		vector<int> curR = right;
        		curR.push_back(left[i]);
        		curR.push_back(left[j]);
        		for(int k=0;k<curR.size();k++){
        			int cur = max(left[i],left[j]);
        			cur += curR[k];
        			vector<int> tmp = curR;
        			tmp.erase(tmp.begin()+k);
        			curL.push_back(curR[k]);
        			cur += myMin(curL,tmp);
        			curL.pop_back();
        			res = min(cur,res);
        		}
        	}
        }
        return res;
    }
};
