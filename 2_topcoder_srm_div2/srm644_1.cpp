/*

Problem Statement
    
Cat Snuke and Wolf Sothe came to an okonomiyaki restaurant. (Okonomiyaki is a Japanese pancake.) The restaurant makes several types of okonomiyaki. Each type of okonomiyaki has its specific size. You are given the sizes of all okonomiyaki types as a vector <int> osize.  The restaurant offers a discount if you order a meal for two persons. Each such order must consist of two okonomiyakis of different types. Additionally, the sizes of the two okonomiyakis must differ by K or less.  You are given the vector <int> osize and the int K. Compute and return the number of different two-person meals offered by the restaurant.
Definition
    
Class:
OkonomiyakiShop
Method:
count
Parameters:
vector <int>, int
Returns:
int
Method signature:
int count(vector <int> osize, int K)
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
K will be between 1 and 10,000, inclusive.
Examples
0)

    
{1,4,6,7,9}
3
Returns: 6
There are five types of okonomiyaki. Let's call them types A, B, C, D, and E. (Type A has size 1, type B has size 4, and so on.) There are 6 valid two-person meals: A+B, B+C, B+D, C+D, C+E, and D+E.  Note that B+A is the same order as A+B: you get one pancake of type A and one pancake of type B.
1)

    
{1,1,3,3,3}
2
Returns: 10
Different types of okonomiyaki may have equal sizes. A two-person meal may contain two okonomiyaki of the same size, they are only required to have a different type. Therefore, in this test case each pair of different okonomiyaki can be ordered as a two-person meal.
2)

    
{1,5,9,14,20}
3
Returns: 0
In this test case there is no valid two-person meal: the differences in pancake sizes are all greater than K.
3)

    
{7,2,6,3,4,2,7,8,3,4,9,1,8,4,3,7,5,2,1,9,9,4,5}
6
Returns: 234

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class OkonomiyakiShop{
public:
	int count(vector <int> osize, int K){
		sort(osize.begin(),osize.end());
		int n = osize.size();
		int res = 0;
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				if(osize[j]-osize[i]<=K) res++;
			}
		}
		return res;
	}
};
