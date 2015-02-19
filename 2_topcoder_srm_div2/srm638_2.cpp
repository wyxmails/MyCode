/*

Problem Statement
    
There is a narrow passage. Inside the passage there are some wolves. You are given a vector <int> size that contains the sizes of those wolves, from left to right.   The passage is so narrow that some pairs of wolves cannot pass by each other. More precisely, two adjacent wolves may swap places if and only if the sum of their sizes is maxSizeSum or less. Assuming that no wolves leave the passage, what is the number of different permutations of wolves in the passage? Note that two wolves are considered different even if they have the same size.   Compute and return the number of permutations of wolves that can be obtained from their initial order by swapping a pair of wolves zero or more times.
Definition
    
Class:
NarrowPassage2Easy
Method:
count
Parameters:
vector <int>, int
Returns:
int
Method signature:
int count(vector <int> size, int maxSizeSum)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
size will contain between 1 and 6 elements, inclusive.
-
Each element in size will be between 1 and 1,000, inclusive.
-
maxSizeSum will be between 1 and 1,000, inclusive.
Examples
0)

    
{1, 2, 3}
3
Returns: 2
From {1, 2, 3}, you can swap 1 and 2 to get {2, 1, 3}. But you can't get other permutations.
1)

    
{1, 2, 3}
1000
Returns: 6
Here you can swap any two adjacent wolves. Thus, all 3! = 6 permutations are possible.
2)

    
{1, 2, 3}
4
Returns: 3
You can get {1, 2, 3}, {2, 1, 3} and {2, 3, 1}.
3)

    
{1,1,1,1,1,1}
2
Returns: 720
All of these wolves are different, even though their sizes are the same. Thus, there are 6! different permutations possible.
4)

    
{2,4,6,1,3,5}
8
Returns: 60

5)

    
{1000}
1000
Returns: 1

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class NarrowPassage2Easy{
public:
	vector<int> b;
	map<vector<int>,int> mark;
	int n;
	int count(vector <int> size, int maxSizeSum){
		n = size.size();
		b.resize(n);
		for(int i=0;i<n;++i) b[i] = i;
		dfs(size,maxSizeSum);
		return mark.size();
	}
	void dfs(vector<int> size,int mx){
		mark[b] = 1;
		for(int i=0;i+1<size.size();++i){
			if(size[i]+size[i+1]>mx) continue;
			swap(size[i],size[i+1]);
			swap(b[i],b[i+1]);
			if(!mark[b]) dfs(size,mx);
			swap(size[i],size[i+1]);
			swap(b[i],b[i+1]);
		}
	}
};
