/*

Problem Statement
    
John and Brus are the managers of your football team. The team is taking part in a tournament. The tournament is almost over: each team still has exactly two matches to play (possibly both against the same opponent). Note that two different teams play in each match.  There are no ties in this tournament. Each match is played until one of the two teams wins. The winner of a match gets 3 points, the loser gets 0 points.  You are given an int yourScore: the number of points your team has scored so far. You are also given two vector <int>s scores and numberOfTeams that describe the other teams. For each valid i, there are numberOfTeams[i] other teams that each have scored scores[i] points so far. Note that the total number of teams in the tournament is 1 + sum(numberOfTeams).  At the end of the tournament, teams will be ranked by the total number of points. Teams with the same number of points will be ranked according to their total score.  Given the above information, you are interested in the best possible (1-based) final rank of your team. Note that you do not know which matches are still to be played, so you assume the best possible combination of matches that is consistent with the given information.  In other words, you want to find the smallest X such that there exists a valid set of future match results that causes your team to end in X-th place. Note that your team's score can be arbitrarily good, so you may always assume that your team is placed above all other teams that have the same score as you.  Compute and return the X defined above.
Definition
    
Class:
TheFootballDivTwo
Method:
find
Parameters:
int, vector <int>, vector <int>
Returns:
int
Method signature:
int find(int yourScore, vector <int> scores, vector <int> numberOfTeams)
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
The current scores given in yourScore and scores do not necessarily correspond to a valid game history. In particular, they do not have to be divisible by 3.
Constraints
-
yourScore will be between 0 and 100,000, inclusive.
-
scores will contain between 1 and 47 elements, inclusive.
-
scores and numberOfTeams will contain the same number of elements.
-
Each element of scores will be between 0 and 100,000, inclusive.
-
Each element of numberOfTeams will be between 1 and 100,000, inclusive.
Examples
0)

    
4
{7}
{1}
Returns: 1
There are two teams in the tournament. They play two games against each other. If your team wins both games it will be on the top of the scoreboard with 10 points.
1)

    
1
{7}
{2}
Returns: 2
There are three teams. Your team has 1 point and each of the other two teams has 7 points. With three teams, the remaining matches are determined uniquely: each pair of teams must play a single match against each other. The best possible final result for your team is to place second with 7 points.
2)

    
1
{7, 1}
{2, 1}
Returns: 1
There are four teams - two with 1 point each and two with 7 points each. If each 1-point team plays against each 7-point team and wins, each team will have 7 points in the end.
3)

    
11
{5, 12, 17, 19, 99, 13, 15, 14}
{2, 4, 8, 2, 1, 3, 25, 3}
Returns: 18

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TheFootballDivTwo{
public:
	int find(int yourScore, vector <int> sc, vector <int> num){
		int n = sc.size();
		vector<pair<int,int> > mark(n);
		int total=0;
		for(int i=0;i<n;++i){
			total += num[i];
			mark[i] = {sc[i],num[i]};
		}
		sort(mark.begin(),mark.end());
		int less=0;
		int i=0;
		for(;i<n;++i){
			if(mark[i].first>yourScore) break;
			less += mark[i].second;
		}
		//if(mark[i].first-yourScore>6) return total-less+1;
		//if(mark[i].second*2>(total+1)) return total-less+1;
		int left = total+1;
		while(i<n&&mark[i].first-yourScore<=6){
			if(mark[i].first-yourScore<=3&&mark[i].second>1){ 
				less += mark[i].second; 
				left -= mark[i].second;
				i++;
				continue;}
			if(mark[i].second*2>=left){
				less += (left/2);
				break;
			}
			less += mark[i].second;
			left -= mark[i].second*2;
			i++;
		}
		return (total-less+1);
	}
};
