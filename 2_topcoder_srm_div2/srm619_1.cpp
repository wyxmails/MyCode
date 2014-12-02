/*
 Problem Statement
     
 Shiny has a company. There are N employees in her company. The employees are numbered 0 through N-1 in order in which they joined the company.
  
 Employee 0 is the only employee with no boss. Every other employee has precisely one direct boss in the company. You are given a vector <int> superior with N elements. Element 0 of superior will be -1 to denote that employee 0 has no boss. For each i between 1 and N-1, inclusive, element i of superior will be the number of the boss of employee i.
  
 For each employee, their boss joined the company before them. Formally, for each i between 1 and N-1, inclusive, superior[i] will be between 0 and i-1, inclusive.
  
 Each employee only does one type of work. You are given a vector <int> workType with N elements. (Different integers represent different types of work.)
  
 Each employee of the company has their own department. The department of employee x is formed by employee x and all the employees such that x is their boss. Formally, for any y different from x, employee y belongs into the department of employee x if and only if superior[y]=x. Note that if superior[z]=y and superior[y]=x, employee z does not belong into the department of employee x.
  
 A department is called diverse if no two employees in the department do the same type of work. Compute and return the number of diverse departments in Shiny's company.
 Definition
     
Class:
GoodCompanyDivTwo
Method:
countGood
Parameters:
vector <int>, vector <int>
Returns:
int
Method signature:
int countGood(vector <int> superior, vector <int> workType)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
superior will contain between 1 and 100 elements, inclusive.
-
workType will contain the same number of elements as superior.
-
Each element of workType will be between 1 and 100, inclusive.
-
superior[0] will be -1.
-
For each valid i>0, superior[i] will be between 0 and i-1, inclusive.
Examples
0)

    
{-1, 0}
{1, 2}
Returns: 2
The department of employee 0 contains employees 0 and 1. The department of employee 1 contains employee 1 only. Both departments are diverse.
1)

    
{-1, 0}
{1, 1}
Returns: 1
The departments are the same as in Example 0. However, now the department of employee 0 is not diverse: it contains two employees who do the same type of work. Only the department of employee 1 is now diverse.
2)

    
{-1, 0, 1, 1}
{1, 4, 3, 2}
Returns: 4
Note that in this test case the department of employee 0 contains only employees 0 and 1. Employees 2 and 3 do not belong into the department of employee 0.
3)

    
{-1, 0, 1, 0, 0}
{3, 3, 5, 2, 2}
Returns: 4

4)

    
{-1, 0, 1, 1, 1, 0, 2, 5}
{1, 1, 2, 3, 4, 5, 3, 3}
Returns: 7

5)

    
{-1, 0, 0, 1, 1, 3, 0, 2, 0, 5, 2, 5, 5, 6, 1, 2, 11, 12, 10, 4, 7, 16, 10, 9, 12, 18, 15, 23, 20, 7, 4}
{4, 6, 4, 7, 7, 1, 2, 8, 1, 7, 2, 4, 2, 9, 11, 1, 10, 11, 4, 6, 11, 7, 2, 8, 9, 9, 10, 10, 9, 8, 8}
Returns: 27

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class GoodCompanyDivTwo{
public:
	int countGood(vector <int> superior, vector <int> workType);
};

int GoodCompanyDivTwo::countGood(vector <int> superior, vector <int> workType){
	int n = superior.size();
	vector<unordered_set<int> > mark(n);
	vector<bool> res(n,false);
	for(int i=0;i<n;++i){
		if(superior[i]>=0){
			if(mark[superior[i]].find(workType[i])!=mark[superior[i]].end())
			   	res[superior[i]] = true;
			else mark[superior[i]].insert(workType[i]);
		}
		mark[i].insert(workType[i]);
	}
	int diverse = n;
	for(int i=0;i<n;++i)
		if(res[i]) diverse--;
	return diverse;
}
