/*

Problem Statement
    
The King of Byteland has an army. The army consists of 2N soldiers. The King has arranged the soldiers into 2 rows by N columns. Two soldiers are neighbors if they are located next to each other in a row or in a column.

Currently, some of the soldiers are happy and some are sad. You are given the current states of all soldiers in a vector <string> state. For each i and j, state[i][j] is 'H' if soldier in row i, column j is happy, or 'S' if that soldier is sad. (All indices are 0-based.)

The King knows that a happy army is a strong army, therefore he wants all his soldiers to be happy. The soldiers can talk to other soldiers. Whenever soldier X talks to soldier Y, soldier Y changes his state to the state of soldier X. For example, if X is currently sad, Y becomes sad as well. The state of soldier X does not change when X talks to Y.

You can now give some soldiers orders to talk to other soldiers. There are three types of valid orders:
Choose a single soldier and call him X. Choose a single neighbor of X and call him Y. X will talk to Y.
Choose any contiguous group of soldiers in one of the rows. Each of these soldiers will talk to their neighbor in the other row.
Choose any column A. Choose any column B adjacent to column A. Each soldier in column A will talk to their neighbor in column B.

You are given the vector <string> state. Return the smallest non-negative integer X such that there is a sequence of X valid orders such that after the orders are executed, one after another, all the soldiers will be happy. If there is no such sequence of orders, return -1 instead.
Definition
    
Class:
TheKingsArmyDiv1
Method:
getNumber
Parameters:
vector <string>
Returns:
int
Method signature:
int getNumber(vector <string> state)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
N will be between 1 and 200, inclusive.
-
state will contain exactly 2 elements.
-
Each element of state will contain exactly N characters.
-
Each element of state will consist of characters 'H' and 'S'.
Examples
0)

    
{"HSH", 
 "SHS"}
Returns: 2
Here is one optimal solution: First, give an order of the first type, choosing the soldier in row 1, column 1 (0-based indices) as X and the soldier in row 0, column 1 as Y. Next, give an order of the second type, choosing the entire row 0.
1)

    
{"HH", 
 "HH"}
Returns: 0
All soldiers are already happy, hence the answer is 0.
2)

    
{"HHHHH", 
 "HSHSH"}
Returns: 1
One optimal solution is to give an order of the second type, choosing soldiers in columns 1 through 3 in row 0.
3)

    
{"S", 
 "S"}
Returns: -1
It is impossible to achieve the goal in this case.
4)

    
{"HSHHSHSHSHHHSHSHSH", 
 "SSSSHSSHSHSHHSSSSH"}
Returns: 8

5)

    
{"HS",
 "HS"}
Returns: 1

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/

#include <iostream>
#include <vector>
using namespace std;

class TheKingsArmyDiv1{
public:
	int getNumber(vector <string> s){
		int n = s[0].size();
		vector<vector<pair<int,int> > > mark(n,vector<pair<int,int> >(n,pair<int,int>(0,0)));
		int ss=0;
		for(int i=0;i<n;++i){
			if(s[0][i]=='S'&&s[1][i]=='S') ss++;
		}
		for(int step=1;step<=n;++step){
			for(int i=0,j=step-1;j<n;++i,++j){
				int zero=0,one=0;
				for(int k=i;k<=j;++k){
					if(s[0][k]=='S') zero++;
					if(s[1][k]=='S') one++;
				}
				mark[i][j].first = zero;
				mark[i][j].second = one;
				for(int k=i;k<j;++k){
					int tmp = min(mark[i][k].first+mark[k+1][j].second+1,mark[i][k].second+mark[k+1][j].first+1);
					int tmp1 = min(mark[i][k].first+mark[k+1][j].first,mark[i][k].second+mark[k+1][j].second+1);
					int tmp2 = min(mark[i][k].first+mark[k+1][j].first+1,mark[i][k].second+mark[k+1][j].second);
					mark[i][j].first = min(mark[i][j].first, min(tmp,tmp1));
					mark[i][j].second = min(mark[i][j].second,min(tmp,tmp2));
				}
			}
		}
		if(mark[0][n-1].first>=n&&mark[0][n-1].second>=n) return -1;
		if(mark[0][n-1].first==0&&mark[0][n-1].second==0) return 0;
		if(ss==mark[0][n-1].first&&ss==mark[0][n-1].second) return ss;
		return min(mark[0][n-1].first,mark[0][n-1].second)+1;
	}
};
