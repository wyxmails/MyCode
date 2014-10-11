/*
 Problem Statement
     
 There are some cats sitting on a straight line that goes from the left to the right. You are given two vector <int>s position and count. For each valid i, there are count[i] cats initially sitting at the point position[i].

 During each minute, each cat chooses and performs one of three possible actions: it may stay in its place, move one unit to the left (i.e., from x to x-1), or move one unit to the right (i.e., from x to x+1). (Note that there are no restrictions. In particular, different cats that are currently at the same point may make different choices.)

 You are also given an int time. The goal is to rearrange the cats in such a way that each point contains at most one cat. Return "Possible" if it's possible to achive the goal in time minutes, and "Impossible" otherwise (quotes for clarity).
 Definition
     
Class:
CatsOnTheLineDiv2
Method:
getAnswer
Parameters:
vector <int>, vector <int>, int
Returns:
string
Method signature:
string getAnswer(vector <int> position, vector <int> count, int time)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
position will contain between 1 and 50 elements, inclusive.
-
position and count will contain the same number of elements.
-
Each element of position will be between -1000 and 1000, inclusive.
-
All elements of position will be distinct.
-
Each element of count will be between 1 and 1000, inclusive.
-
time will be between 0 and 1000, inclusive.
Examples
0)

    
{0}
{7}
3
Returns: "Possible"
There are 7 cats sitting at the origin in this case. There are also 7 different points that cats can reach in 3 minutes, so each cat can occupy a unique point. Thus, the answer is "Possible".
1)

    
{0}
{8}
2
Returns: "Impossible"
Unlike the first test case, in this case there are 8 cats for 7 available points. Thus, the answer is "Impossible".
2)

    
{0, 1}
{3, 1}
0
Returns: "Impossible"

3)

    
{5, 0, 2}
{2, 3, 5}
2
Returns: "Impossible"

4)

    
{5, 1, -10, 7, 12, 2, 10, 20}
{3, 4, 2, 7, 1, 4, 3, 4}
6
Returns: "Possible"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
 using namespace std;

class CatsOnTheLineDiv2{
public:
	string getAnswer(vector <int> position, vector <int> count, int time);
};

string CatsOnTheLineDiv2::getAnswer(vector <int> position, vector <int> count, int time){
	string pos="Possible";
	string impos="Impossible";
	int n = position.size();
	map<int,int> pos_count;
	for(int i=0;i<n;++i){
		pos_count[position[i]] = count[i];
	}
	unordered_map<int,bool> mark;
	map<int,int>::iterator it=pos_count.begin();
	while(it!=pos_count.end()){
		if(it->second/2>time) return impos;
		//if(mark.find(it->first)!=mark.end()) return impos;
		int start = it->first-time;
		while(mark.find(start)!=mark.end()) start++;
		if(start+it->second-1-it->first>time) return impos;
		for(int i=start;i<start+it->second;++i){
			mark[i] = true;
		}
		it++;
	}
	return pos;
}
