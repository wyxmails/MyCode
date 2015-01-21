/*

Problem Statement
    
Janusz owns a hotel. He has already received some reservations for the upcoming year. The days in the year are numbered 1 through 365. For each valid i, there is a guest who will arrive on day arrivals[i] and depart on day departures[i].
Janusz can give some guests a special promotion. Any guest that gets the special promotion will leave a good review. Additionally, all guests that meet a guest with promotion will also leave a good review. (Here we assume that two guests meet if and only if they are in the hotel on the same day, including the situation when one of them departs on the same day the other one arrives.)
Janusz wants to make sure that all his guests leave good reviews. You are given the vector <int>s arrivals and departures. Return the smallest possible number of special promotions sufficient to make sure that all guests leave good reviews.
Definition
    
Class:
JanuszTheBusinessman
Method:
makeGuestsReturn
Parameters:
vector <int>, vector <int>
Returns:
int
Method signature:
int makeGuestsReturn(vector <int> arrivals, vector <int> departures)
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
arrivals and departures will have the same number of elements.
-
arrivals will have between 2 and 50 elements, inclusive.
-
Each element of arrivals and departures will be between 1 and 365, inclusive.
-
For each valid i arrivals[i] will be less than departures[i].
Examples
0)

    
{2, 10, 6}	
{6, 11, 9}
Returns: 2
One promotion is not enough. One optimal solution is to give promotions to the guest who arrives on day 2 and to the guest who arrives on day 10. The third guest will meet the first guest on day 6.
1)

    
{2, 10, 23, 34, 45, 123, 1}
{25, 12, 40, 50, 48, 187, 365}
Returns: 1
One guest is going to stay for the whole season so Janusz can give the promotion only to him.
2)

    
{8, 12, 20, 30, 54, 54, 68, 75}
{13, 31, 30, 53, 55, 70, 80, 76}
Returns: 3

3)

    
{124, 328, 135, 234, 347, 124, 39, 99, 116, 148}
{237, 335, 146, 246, 353, 213, 197, 215, 334, 223}
Returns: 2

4)

    
{154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6}
{159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13}
Returns: 14

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct N{
	int start,end;
	N(int s,int e):start(s),end(e){}
	friend bool operator<(const N&a,const N&b){
		if(a.end!=b.end) return a.end<b.end;
		return a.start>b.start;
	}
};

class JanuszTheBusinessman{
public:
	int makeGuestsReturn(vector <int> arrivals, vector <int> departures){
		int n = arrivals.size();
		vector<N> mark;
		for(int i=0;i<n;++i)
			mark.push_back(N(arrivals[i],departures[i]));
		sort(mark.begin(),mark.end());
		int i=0,j;
		int res=0;
		while(i<n){
			j = n-1;
			while(j>i&&mark[j].start>mark[i].end) j--;
			i = j+1;
			while(i<n&&mark[i].start<=mark[j].end) i++;
			res++;
		}
		return res;
	}
};
