/*

Problem Statement
    
This problem statement contains superscripts that may not display properly outside the applet.

Kitayuta Mart is the largest supermarket in Shuseki Kingdom, offering a great variety of food and household products. The main products are fruits, especially apples. The price system is a little special: the original price of an apple is K yen (the currency of the kingdom). However, if a customer wants to buy more than one apple, the second apple will cost 2*K yen, the third apple will cost 22*K yen, and so on. In general, if a customer is buying n apples, the actual price of the i-th (1 <= i <= n) apple will be 2i-1*K yen.

Lun the dog loves apples. She has just bought some number of apples at Kitayuta Mart. The prices of those apples were calculated using the above formula. The total she paid for her apples was T yen. You are given two ints: K and T. Find and return the number of the apples that Lun has bought. It is guaranteed that K and T are such that the answer exists and is unique.
Definition
    
Class:
KitayutaMart2
Method:
numBought
Parameters:
int, int
Returns:
int
Method signature:
int numBought(int K, int T)
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
K will be between 80 and 160, inclusive.
-
T will be between 80 and 163,680, inclusive.
-
The input will be such that the answer exists and is unique.
Examples
0)

    
100
100
Returns: 1
If she buys only one apple, the price will just be K yen.
1)

    
100
300
Returns: 2
The second apple will cost 2*100 = 200 yen, for the total price of 100 + 200 = 300 yen.
2)

    
150
1050
Returns: 3
150 + 2*150 + 22*150 = 150 + 300 + 600 = 1050.
3)

    
160
163680
Returns: 10

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/

#include <iostream>
#include <algorithm>
using namespace std;

class KitayutaMart2{
public:
	int numBought(int K, int T){
		int total=0;
		int res=0;
		while(total<T){
			total += pow(2,res)*K;
			res++;
		}
		return res;
	}
};
