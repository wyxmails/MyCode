/*
 Problem Statement
     
 We have a circular tube. At one point the tube has an entrance.  At time 0, a rat enters the tube via the entrance. The rat can move inside the tube in both directions (clockwise and counterclockwise). The rat can change direction in an instant. Its maximum speed is Vrat.  At time T, the cat will enter the tube via the same entrance. The cat can also move in both directions and change its direction instantly. Its maximum speed is Vcat.  For the purpose of this problem, you should imagine the tube as a circle with radius R, and the rat and the cat as points on said circle.  The cat is trying to catch the rat as quickly as possible. The rat is trying not to be caught, and if that is impossible, to be caught as late as possible. At any time (starting at time 0) the cat and the rat know each other's position. Already at time 0 the rat knows the time T. Assume that both the cat and the rat behave optimally.  You are given the ints R, T, Vrat, and Vcat. If the cat will catch the rat successfully, return how much time it'll take the cat to catch the rat. Otherwise, return -1.0.
 Definition
     
Class:
CatAndRat
Method:
getTime
Parameters:
int, int, int, int
Returns:
double
Method signature:
double getTime(int R, int T, int Vrat, int Vcat)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
The cat and rat cannot leave the tube.
-
Your return value must have a relative or absolute error less than 1e-9.
Constraints
-
R, T, Vrat, and Vcat will each be between 1 and 1000, inclusive.
Examples
0)

    
10
1
1
1
Returns: -1.0
The rat can survive. During the first unit of time it has to run away from the entrance. Then, once the cat enters the tube, the rat can always run in the same direction and with the same speed as the cat.
1)

    
10
1
1
2
Returns: 1.0
The cat is now faster than the rat. The best strategy for the rat is to enter the tube and to start running in either direction at its maximum speed. The cat will then enter the tube, run in the same direction as the rat, and catch it in exactly 1 unit of time.
2)

    
10
1
2
1
Returns: -1.0
The rat is now faster than the cat. It can survive, for example by using the strategy described in Example 0.
3)

    
1000
1000
1
1000
Returns: 1.001001001001001

4)

    
1
1000
1
2
Returns: 3.141592653589793

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */
#include <iostream>
using namespace std;

class CatAndRat{
public:
	double getTime(int R, int T, int Vrat, int Vcat);
};

double CatAndRat::getTime(int R, int T, int Vrat, int Vcat){
	double pi = 3.141592653589793;
	double distance = pi*(double)R;
	if(distance>double(T)*(double)Vrat) distance = double(T)*(double)Vrat;
	if(T<=0) return 0.0;
	if(Vcat<=Vrat) return -1.0;
	return double(distance)/double(Vcat-Vrat);
}
