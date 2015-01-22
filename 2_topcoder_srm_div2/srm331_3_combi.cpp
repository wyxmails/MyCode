/*

Problem Statement
    
You are decorating your Christmas tree. The tree has N levels, numbered 1 through N from top to bottom. You have a number of red, green and blue baubles, and you've decided to hang them in the following manner: On each level k, you will hang a row of exactly k baubles. Within each row, you will select the colors of the baubles such that there is an equal number of baubles of each color used in that level. For example, consider the following two trees:
      R                 R
    B   G             B   G 
  R   R   R         R   B   R
The tree on the left is correctly decorated. Each row contains an equal number of baubles for each color used. The tree on the right, however, is not correctly decorated because the third level contains an unequal number of red and blue baubles.
You are given an int N, the number of levels in the tree, and ints red, green and blue, representing the number of available baubles in each color. Return the number of distinct correct ways to decorate the tree. Two decorated trees are different if there is at least one position at which the two trees have a different colored bauble. If it is impossible to decorate the tree with the given baubles, return 0.
Definition
    
Class:
ChristmasTree
Method:
decorationWays
Parameters:
int, int, int, int
Returns:
long long
Method signature:
long long decorationWays(int N, int red, int green, int blue)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
N will be between 1 and 10, inclusive.
-
red will be between 0 and 50, inclusive.
-
green will be between 0 and 50, inclusive.
-
blue will be between 0 and 50, inclusive.
Examples
0)

    
2
1
1
1
Returns: 6
You can use any of the three colors for the top bauble, which always leaves you with two choices for the second level. Hence, there is a total of six different ways to decorate the tree:
  R        R  
B   G    G   B

  B        B  
R   G    G   R

  G        G
B   R    R   B
1)

    
2
2
1
0
Returns: 3
If you put the green bauble on the top level, you must put both reds on the second level. On the other hand, if you put the red bauble on the top level, you have two different ways to decorate the second level (red-green or green-red). That makes a total of three ways.
2)

    
3
2
2
1
Returns: 0
You have only five baubles, while six are needed to cover three levels.
3)

    
3
2
2
2
Returns: 36
The third level must either have three baubles of the same color or three baubles with different colors. Since you don't have three baubles of the same color, you must use three different colors for that level.
4)

    
8
1
15
20
Returns: 197121

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
#include <tuple>
#include <map>
#include <cstring>
using namespace std;

int mark[11][51][51][51];

class ChristmasTree{
public:
	ChristmasTree(){
		memset(mark,-1,sizeof(mark));
	}
	long long decorationWays(int N, int red, int green, int blue){
		long long res = 0;
		if(N<1||red<0||green<0||blue<0||red+green+blue<N) return 0;
		if(N==1){
			if(red>=1) res++;
			if(green>=1) res++;
			if(blue>=1) res++;
			return res;
		}
		if(mark[N][red][green][blue]!=-1) return mark[N][red][green][blue];
		if(red>=N) res += decorationWays(N-1,red-N,green,blue);
		if(green>=N) res += decorationWays(N-1,red,green-N,blue);
		if(blue>=N) res += decorationWays(N-1,red,green,blue-N);
		long long fn = fac(N);
		long long fn2 = fac(N/2);
		long long fn3 = fac(N/3);
		if(N%2==0){
			long long coe = fn/fn2/fn2;
			res += coe*decorationWays(N-1,red-N/2,green-N/2,blue);
			res += coe*decorationWays(N-1,red-N/2,green,blue-N/2);
			res += coe*decorationWays(N-1,red,green-N/2,blue-N/2);
		}
		if(N%3==0){
			long long coe = fn/fn3/fn3/fn3;
			res += coe*decorationWays(N-1,red-N/3,green-N/3,blue-N/3);
		}
		mark[N][red][green][blue] = res;
		return res;
	}
	long long fac(int n){
		if(n<=1) return 1;
		return n*fac(n-1);
	}
};
