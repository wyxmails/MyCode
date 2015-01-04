/*
Problem Statement
    
Christmas is just around the corner, and Alice just decorated her Christmas tree. There are N stars and N-1 ribbons on the tree. Each ribbon connects two of the stars in such a way that all stars and ribbons hold together. (In other words, the stars and ribbons are the vertices and edges of a tree.)
The stars are numbered 1 through N. Additionally, each star has some color. You are given the colors of stars as a vector <int> col with N elements. For each i, col[i] is the color of star i+1. (Different integers represent different colors.)
You are also given a description of the ribbons: two vector <int>s x and y with N-1 elements each. For each i, there is a ribbon that connects the stars with numbers x[i] and y[i].
According to Alice, a ribbon that connects two stars with different colors is beautiful, while a ribbon that connects two same-colored stars is not. Compute and return the number of beautiful ribbons in Alice's tree.
Definition
    
Class:
ChristmasTreeDecorationDiv2
Method:
solve
Parameters:
vector <int>, vector <int>, vector <int>
Returns:
int
Method signature:
int solve(vector <int> col, vector <int> x, vector <int> y)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Constraints
-
N will be between 2 and 50, inclusive.
-
The number of elements in col will be exactly N.
-
The number of elements in x will be exactly N - 1.
-
The number of elements in y will be the same as the number of elements in x.
-
All elements of x and y will be between 1 and N, inclusive.
-
For each i, the numbers x[i] and y[i] will be different.
-
The graph formed by the N-1 ribbons will be connected.
Examples
0)

    
{1,2,3,3}
{1,2,3}
{2,3,4}
Returns: 2
There are two beautiful ribbons: the one that connects stars 1 and 2, and the one that connects stars 2 and 3. The other ribbon is not beautiful because stars 3 and 4 have the same color.
1)

    
{1,3,5}
{1,3}
{2,2}
Returns: 2

2)

    
{1,1,3,3}
{1,3,2}
{2,1,4}
Returns: 2

3)

    
{5,5,5,5}
{1,2,3}
{2,3,4}
Returns: 0

4)

    
{9,1,1}
{3,2}
{2,1}
Returns: 1

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ChristmasTreeDecorationDiv2{
public:
	int solve(vector <int> col, vector <int> x, vector <int> y){
		int n = x.size();
		int res=0;
		for(int i=0;i<n;++i){
			if(col[x[i]-1]!=col[y[i]-1]) res++;
		}
		return res;
	}
};
