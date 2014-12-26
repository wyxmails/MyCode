/*

Problem Statement
    
The bus station in Joseph's town operates randomly. Before the bus station opens, there are N buses at the station. The buses are numbered 0 through N-1. Whenever a bus has to depart the station, one of these buses is chosen at random. Different buses may be chosen with different probabilities. More precisely, for each i, the probability that bus i will be chosen is prob[i]/100. After bus i departs the station, it follows its specific route. The time the bus needs to complete its route is time[i].
The bus station opens at time 0. At that time, the first random bus will depart. During the day, as soon as a bus returns from its route, a new bus is randomly chosen to depart in that same moment. (The probability distribution is the same for each random choice, and the random choices are mutually independent. It is possible that the bus chosen to depart will again be the bus that just arrived.)
Joseph just arrived to the bus station. The current time is s. He is going to wait for the next bus. (If there is a bus departing precisely at the time s, Joseph can still catch it. In this case, his waiting time is zero.)
You are given the vector <int>s time and prob, and the int s. Return Joseph's expected waiting time.
Definition
    
Class:
WaitingForBus
Method:
whenWillBusArrive
Parameters:
vector <int>, vector <int>, int
Returns:
double
Method signature:
double whenWillBusArrive(vector <int> time, vector <int> prob, int s)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Notes
-
Your return value must have an absolute or relative error smaller than 1e-6
Constraints
-
time will contain between 1 and 100 elements, inclusive.
-
prob will contain the same number of elements as time
-
Each element of time will be between 1 and 10^5, inclusive.
-
Each element of prob will be between 1 and 100, inclusive.
-
The sum of all elements of prob will be exactly 100.
-
s will be between 0 and 10^5, inclusive.
Examples
0)

    
{5,100}
{90,10}
5
Returns: 9.5
Joseph will arrive to the bus station at time 5. At time 0, one of the two buses was chosen. With probability 90% it was bus 0. This bus will return to the station at time 5. Therefore, a new bus will be chosen to depart at time 5 and Joseph can board it immediately. With probability 10% the bus that departed the station at time 0 was bus 1. If this was the case, the next bus will depart the station at time 100, which means that Joseph's waiting time will be 95. Thus, the expected waiting time is 0.9 * 0 + 0.1 * 95 = 9.5.
1)

    
{5}
{100}
101
Returns: 4.0

2)

    
{5,10}
{50,50}
88888
Returns: 3.666666666666667

3)

    
{1,2,3,4}
{10,20,30,40}
1000
Returns: 1.166666666666667

4)

    
{10,100,1000,10000,100000}
{90,4,3,2,1}
100000
Returns: 21148.147303578935

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXI = 200005;
double dp[MAXI];

class WaitingForBus{
public:
	double whenWillBusArrive(vector <int> time, vector <int> prob, int s){
		int n = time.size();
		vector<double> pb;
		for(int i=0;i<n;++i)
			pb.push_back(1.0*prob[i]/100.0);
		memset(dp,sizeof(dp),0);
		dp[0] = 1.0;
		for(int i=0;i<s;++i)
		for(int j=0;j<n;++j)
			dp[i+time[j]] += dp[i]*pb[j];
		double res = 0;
		for(int i=s;i<MAXI;++i)
			res += dp[i]*(i-s);
		return res;
	}
};
