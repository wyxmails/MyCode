/*
 Problem Statement
     
 One of the modes in the game "osu!" is called "catch the beat". In this mode, you control a character that catches falling fruit.   The game is played in the vertical plane. For simplicity, we will assume that both your character and all pieces of fruit are points in that plane.   You start the game at the coordinates (0, 0). Your character can only move along the x-axis. The maximum speed of your character is 1 unit of distance per second. For example, you need at least 3 seconds to move from (-2, 0) to (1, 0).   You are given vector <int>s x and y that contain initial coordinates of the fruit you should catch: for each valid i, there is one piece of fruit that starts at (x[i], y[i]). All pieces of fruit fall down with constant speed of 1 unit of distance per second. That is, a fruit currently located at (xf, yf) will move to (xf, yf-t) in t seconds.   You will catch a fruit if the character is located at the same point as the fruit at some moment in time. Can you catch all the fruit in the game? Return "Able to catch" (quotes for clarity) if you can, and "Not able to catch" otherwise.
 Definition
     
Class:
CatchTheBeatEasy
Method:
ableToCatchAll
Parameters:
vector <int>, vector <int>
Returns:
string
Method signature:
string ableToCatchAll(vector <int> x, vector <int> y)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
x will contain between 1 and 50 elements, inclusive.
-
x and y will contain the same number of elements.
-
The elements in x will be between -1,000 and 1,000, inclusive.
-
The elements in y will be between 0 and 1,000, inclusive.
Examples
0)

    
{-1, 1, 0}
{1, 3, 4}
Returns: "Able to catch"
In order to catch all three pieces of fruit, you have to follow this schedule (always walking at 1 unit per second):
Walk left for 1 second. When you reach (-1,0), catch the fruit that started at (-1,1).
Walk right for 2 seconds. When you reach (1,0), catch the fruit that started at (1,3).
Walk left for 1 second. When you reach (0,0), catch the fruit that started at (0,4).
1)

    
{-3}
{2}
Returns: "Not able to catch"
The only piece of fruit cannot be caught. Even if you start moving left immediately, you will only reach (-2,0) by the time the fruit crosses the y axis.
2)

    
{-1, 1, 0}
{1, 2, 4}
Returns: "Not able to catch"

3)

    
{0, -1, 1}
{9, 1, 3}
Returns: "Able to catch"
You can catch the pieces of fruit in any order. Also note that sometimes you'll want to move slower or wait at some location. For example, after catching the pieces of fruit that started at (-1,1) and (1,3), you can walk to (0,0) and wait there for the third piece.
4)

    
{70,-108,52,-70,84,-29,66,-33}
{141,299,402,280,28,363,427,232}
Returns: "Not able to catch"

5)

    
{-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66}
{320,107,379,72,126,445,318,255,445,62,52,184,247,245,185}
Returns: "Able to catch"

6)

    
{0,0,0,0}
{0,0,0,0}
Returns: "Able to catch"
Different pieces of fruit may share the same position. You can catch all the pieces at the same time.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class CatchTheBeatEasy{
public:
	string ableToCatchAll(vector <int> x, vector <int> y);
};

string CatchTheBeatEasy::ableToCatchAll(vector <int> x, vector <int> y){
	string not_able = "Not able to catch";
	string able = "Able to catch";
	int n = x.size();
	map<int,int> mark;
	mark[0] = 0;
	for(int i=0;i<n;++i){
		auto it = mark.find(y[i]);
		if(it!=mark.end()){
			if(it->second!=x[i]) return not_able;
		}
		mark[y[i]] = x[i];
	}
	auto it = mark.begin();it++;
	auto it1 = mark.begin();
	for(;it!=mark.end();++it,++it1){
		int X = abs(it->second-it1->second);
		int Y = abs(it->first-it1->first);
		if(Y<X) return not_able;
	}
	return able;
}
