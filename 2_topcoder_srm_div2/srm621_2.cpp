/*
 Problem Statement
     
 Your friend Lucas gave you a sequence S of positive integers.
  
 For a while, you two played a simple game with S: Lucas would pick a number, and you had to select some elements of S such that the sum of all numbers you selected is the number chosen by Lucas. For example, if S={2,1,2,7} and Lucas chose the number 11, you would answer that 2+2+7 = 11.
  
 Lucas now wants to trick you by choosing a number X such that there will be no valid answer. For example, if S={2,1,2,7}, it is not possible to select elements of S that sum up to 6.
  
 You are given the vector <int> S. Find the smallest positive integer X that cannot be obtained as the sum of some (possibly all) elements of S.
  
 Definition
     
Class:
NumbersChallenge
Method:
MinNumber
Parameters:
vector <int>
Returns:
int
Method signature:
int MinNumber(vector <int> S)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
S will contain between 1 and 20 elements, inclusive.
-
Each element of S will be between 1 and 100,000, inclusive.
Examples
0)

    
{5, 1, 2}
Returns: 4
These are all the positive integers that can be obtained: 1, 2, 3, 5, 6, 7, and 8. (We can obtain 3 as 1+2, 6 as 1+5, 7 as 2+5, and 8 as 1+2+5.) The smallest positive integer not present in the above list is 4.
1)

    
{2, 1, 4}
Returns: 8
We can obtain each of the sums from 1 to 7, inclusive. The smallest impossible sum is 8.
2)

    
{2, 1, 2, 7}
Returns: 6
The example given in the problem statement.
3)

    
{94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1}
Returns: 1092

4)

    
{883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13}
Returns: 56523

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NumbersChallenge{
public:
	int MinNumber(vector <int> S);
};

int NumbersChallenge::MinNumber(vector <int> S){
	int n = S.size();
	sort(S.begin(),S.end());
	vector<int> mark;
	mark.push_back(0);
	for(int i=0;i<n;++i){
		int m = mark.size();
		if(S[i]-mark.back()>1) return mark.back()+1;
		if(S[i]-1==mark.back()) mark.push_back(S[i]);
		for(int j=0;j<m;++j){
			if(S[i]+mark[j]-mark.back()>1) return mark.back()+1;
			if(S[i]+mark[j]-1==mark.back()) mark.push_back(S[i]+mark[j]);
		}
	}
	return mark.back()+1;
}
