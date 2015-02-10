/*

Problem Statement
    
You have a sequence that consists of N shopping carts. You want to remove all of them as quickly as possible.  The process of removing the carts will consist of one or more turns. Each turn will take exactly one minute. At the beginning of each turn, you will have some sequences of carts. For each of those sequences you can choose between two options:
split it (in an arbitrary place) into two shorter sequences
remove one shopping cart from the sequence
  There is one additional constraint: during the entire process you can only choose to split a sequence at most K times.  You are given the ints N and K. Compute and return the smallest number of minutes in which it is possible to remove all the carts.
Definition
    
Class:
CartInSupermarketEasy
Method:
calc
Parameters:
int, int
Returns:
int
Method signature:
int calc(int N, int K)
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
N will be between 1 and 100, inclusive.
-
K will be between 0 and 100, inclusive.
Examples
0)

    
5
0
Returns: 5
As K=0, you can never split any sequence. In each turn you have to remove one cart from your sequence. Hence, it will take 5 minutes to remove all 5 carts.
1)

    
5
2
Returns: 4
One optimal solution: {5} -> {2,3} -> {1,2} -> {1,1} -> {}. We used two splits: once when splitting the sequence of 5 carts into 2+3 and the second time when splitting the sequence of 2 carts into 1+1.
2)

    
15
4
Returns: 6

3)

    
7
100
Returns: 4
You don't have to split exactly K times.
4)

    
45
5
Returns: 11

5)

    
100
100
Returns: 8

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class CartInSupermarketEasy{
public:
	int calc(int N, int K){
	  if(N<=1) return N;
		if(K==0) return N;
		int cut=0;
		int lg = log2(N-1)+1;
		for(int i=1;i<=lg;i*=2)
			cut += i;
		if(cut<=K) return lg+1;
		int pa=0;
		for(int i=0;i<=K;++i)
			pa += i;
		int x = (N+pa)/(K+1);
		while((K+1)*x-pa+1<N) x++;
		return x+1;
	}
};
