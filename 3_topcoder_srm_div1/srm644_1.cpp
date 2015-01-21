/*

Problem Statement
    
Wolf Sothe is planning a party for his M friends. He wants to give them some okonomiyaki at the party. (Okonomiyaki is a Japanese pancake.)  Sothe just came to an okonomiyaki restaurant. The restaurant makes several types of okonomiyaki. Each type of okonomiyaki has its specific size. You are given the sizes of all okonomiyaki types as a vector <int> osize.  Sothe would like to buy exactly M okonomiyaki. They must all have different types, so that the people at the party have the most options to choose from. Additionally, they must all have roughly the same sizes, so that nobody feels disappointed. More precisely, the difference between the size of the largest and smallest okonomiyaki ordered by Sothe must be K or less.  You are given the vector <int> osize and the ints M and K. Compute and return the number of different orders Sothe could place at the restaurant, modulo 1,000,000,007.
Definition
    
Class:
OkonomiyakiParty
Method:
count
Parameters:
vector <int>, int, int
Returns:
int
Method signature:
int count(vector <int> osize, int M, int K)
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
osize will contain between 2 and 50 elements, inclusive.
-
Each element in osize will be between 1 and 10,000, inclusive.
-
M will be between 2 and the number of elements in osize, inclusive.
-
K will be between 1 and 10,000, inclusive.
Examples
0)

    
{1,4,6,7,9}
2
3
Returns: 6
There are five types of okonomiyaki. Let's call them types A, B, C, D, and E. (Type A has size 1, type B has size 4, and so on.) Sothe wants to buy M=2 different okonomiyaki and their sizes must differ by K=3 or less. There are 6 valid orders: A+B, B+C, B+D, C+D, C+E, and D+E.  Note that B+A is the same order as A+B: you get one pancake of type A and one pancake of type B.
1)

    
{1,6,2,7,4,2,6,1,5,2,4}
4
3
Returns: 60
Different types of okonomiyaki may have equal sizes. An order may contain multiple okonomiyaki of the same size, they are only required to have different types.
2)

    
{1,4,5,7,10,11,13,16,18}
4
5
Returns: 0
In this test case there is no valid order: regardless of which 4 pancakes Sothe wants, the difference between their sizes will be too large.
3)

    
{55,2,7,232,52,5,5332,623,52,6,532,5147}
6
10000
Returns: 924

4)

    
{5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727,
1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452,
5682,7775,4356,5140,8923,9801,3729}
15
4003
Returns: 114514

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MOD=1000000007;
int mark[55][55];

class OkonomiyakiParty{
public:
	int count(vector <int> osize, int M, int K){
		sort(osize.begin(),osize.end());
		int n = osize.size();
		memset(mark,0,sizeof(mark));
		for(int i=0;i<55;++i){
			mark[i][i] = 1;
			mark[i][0] = 1;
		}
		for(int i=1;i<55;++i){
			for(int j=1;j<M;++j){
				mark[i][j] = (mark[i-1][j-1]+mark[i-1][j])%MOD;
			}
		}
		long long res = 0;
		int pre = M-1;
		for(int i=0;i+M<=n;++i){
			for(;pre<n;++pre){
				if(osize[pre]-osize[i]>K){
					pre--; break;
				}
			}
			if(pre==n) pre--;
			int cur = pre+1-i;
			if(pre+1-i<M) continue;
			cur--;
			res += mark[cur][M-1];
			res %= MOD;
		}
		return res;
	}
};
