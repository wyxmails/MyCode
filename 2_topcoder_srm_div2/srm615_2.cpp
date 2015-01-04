/*
Problem Statement
    
Limit is a flea. He can do two types of jumps: small jumps that have length 1 millimeter, and big jumps that have length B millimeters.  Limit is going to make exactly T jumps, all of them in the same direction. He would like to travel exactly D millimeters in those jumps. Is this possible?  You are given a long long D, and ints T and B. Return "Possible" (quotes for clarity) if there is a combination of T jumps forward that has a total length of exactly D millimeters. Otherwise, return "Impossible".
Definition
    
Class:
LongLongTripDiv2
Method:
isAble
Parameters:
long long, int, int
Returns:
string
Method signature:
string isAble(long long D, int T, int B)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
D will be between 1 and 10^18, inclusive.
-
T will be between 1 and 1,000,000,000, inclusive.
-
B will be between 2 and 1,000,000,000, inclusive.
Examples
0)

    
10
6
3
Returns: "Possible"
Limit must make 6 jumps that have a total length of 10 millimeters. This is possible: two of the jumps must be long and the other four must be short.
1)

    
10
5
3
Returns: "Impossible"

2)

    
50
100
2
Returns: "Impossible"

3)

    
120
10
11
Returns: "Impossible"

4)

    
10
10
9999
Returns: "Possible"

5)

    
1000
100
10
Returns: "Possible"

6)

    
1000010000100001
1100011
1000000000
Returns: "Possible"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

class LongLongTripDiv2{
public:
	string isAble(long long D, int T, int B){
		long long t = T;
		long long b = B;
		if(b*t<D||T>D) return "Impossible";
		for(long long i=D/b;i>=0;--i){
			long long steps = D-i*b+i;
			if(steps==T) return "Possible";
			if(steps>T) return "Impossible";
		}
		return "Impossible";
	}
};
