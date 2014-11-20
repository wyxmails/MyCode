/*
Problem Statement
    
Elly and Kris play the following game. In the beginning there are several boxes aligned in a row. The boxes may or may not contain candy. As a matter of fact, the girls know exactly how many candies each of them contains. This information is given to you in the vector <int> sweets.  Starting with Elly, the girls make moves in alternating order. A single move looks as follows: the player whose turn it is chooses one of the non-empty boxes and takes all the sweets from it. After that the amount of candy in the neighboring boxes is doubled. For example, suppose that there were five boxes with {20, 50, 70, 0, 30} sweets, respectively. If the girl whose turn it was chose box 0, then in the next turn the number of sweets in the boxes would be {0, 100, 70, 0, 30}. If she chose box 1, then it would be {40, 0, 140, 0, 30}. If she chose box 2, it would be {20, 100, 0, 0, 30}. If she chose box 4, it would be {20, 50, 70, 0, 0}. Note that the girl cannot choose box 3, because it is empty. The game ends when all boxes are empty. The winner of the game is the girl who has more candies at the end of the game.  Return the name of the girl that will win the game if both girls play optimally, or "Draw" if they end up with the same number of candies.
Definition
    
Class:
EllysCandyGame
Method:
getWinner
Parameters:
vector <int>
Returns:
string
Method signature:
string getWinner(vector <int> sweets)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
Playing optimally means that if there is a move, which guarantees that the girl whose turn it is will win no matter what the other girl does, she will play it. If there is no such move, but there is one, which would guarantee a draw, she will use it instead.
-
The game always ends after a finite number of moves, because the number of empty boxes increases in each step.
Constraints
-
sweets will contain between 1 and 10 elements, inclusive.
-
Each element of sweets will be between 0 and 1000, inclusive.
Examples
0)

    
{20, 50, 70, 0, 30}
Returns: "Kris"
If Elly takes the 20, then Kris can take the 30, leaving Elly the choice between 100 and 70. Elly should take the 100, but then Kris will take 140 and win. If Elly takes the 30, then Kris can take the 20, leaving Elly the same choice. If Elly takes the 50, then Kris can take the 140, leaving Elly the choice between a 40 and a 30. If Elly takes the 70, then Kris can take the 100, leaving Elly the same choice. In any case, Kris will take more than Elly and win.
1)

    
{42, 13, 7}
Returns: "Elly"
Here Elly can take the 42 in her first move and win, no matter whether Kris chooses the 26 or 7.
2)

    
{10, 20}
Returns: "Draw"
Elly cannot win, but she can force a draw by taking the 20 (and leaving 20 to her opponent).
3)

    
{3, 1, 7, 11, 1, 1}
Returns: "Kris"

4)

    
{41, 449, 328, 474, 150, 501, 467, 329, 536, 440}
Returns: "Kris"

5)

    
{177, 131, 142, 171, 411, 391, 17, 222, 100, 298}
Returns: "Elly"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

map<vector<int>,long long> mark;

class EllysCandyGame{
public:
	string getWinner(vector <int> sweets){
		long long res;
		res = solve(sweets);
		if(res>0) return "Elly";
		else if(res==0) return "Draw";
		else return "Kris";
	}
	long long solve(vector<int> sweets){
		if(mark.find(sweets)==mark.end()){
			int n = sweets.size();
			if(count(sweets.begin(),sweets.end(),0)==n) return 0;
			long long Max = INT_MIN;
			for(int i=0;i<n;++i){
				if(sweets[i]==0) continue;
				long long cur = sweets[i];
				vector<int> tmp = sweets;
				tmp[i] = 0;
				tmp[max(i-1,0)] = 2*tmp[max(i-1,0)];
				tmp[min(n-1,i+1)] = 2*tmp[min(n-1,i+1)];
				cur -= solve(tmp);
				Max = max(cur,Max);
			}
			mark[sweets] = Max;
			return Max;
		}else return mark[sweets];
	}
};
