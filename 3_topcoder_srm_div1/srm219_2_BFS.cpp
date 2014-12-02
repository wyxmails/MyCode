/*
Problem Statement
    
You are out for Chinese food with a bunch of friends. You are all sitting at a round table, and in the center of the table is a turntable onto which all of the entrees are placed. There is one entree immediately in front of each of you.
Each of you likes certain items, given as a vector <string> favorites, each element of which is a space delimited list of integers. Each integer corresponds to an entree, where 0 is the entree initially in front of person 0, etc. Element i of favorites contains the indexes of all the entrees that person i likes.
The turntable rotates in either direction. When someone is serving himself, he can only take from the entree that is directly in front of him. However, he is not required to take the entree presented to him, even if it is one of his favorites.
It takes 2 seconds to rotate the turntable by one position. But, to rotate it by two positions takes 3 seconds, and in general it takes n+1 seconds to rotate the turntable by n positions. It takes 15 seconds for a person to serve himself the entree in front of him. If multiple people have favorite entrees in front of them, they can serve themselves simultaneously. The turntable cannot be rotated while anyone is serving himself.
You are to return an int indicating the minimum number of seconds it takes for each person to have served himself one entree.
Definition
    
Class:
TurntableService
Method:
calculateTime
Parameters:
vector <string>
Returns:
int
Method signature:
int calculateTime(vector <string> favorites)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
You may assume that each of the entrees on the turntable is unique.
Constraints
-
favorites will contain between 1 and 15 elements, inclusive.
-
Each element of favorites will be a list of integers, separated by a single space, with no leading or trailing spaces.
-
Each element of favorites will contain only digits ('0'-'9') and spaces (' ').
-
Each element of favorites will contain between 1 and 50 characters, inclusive.
-
Each number in each element of favorites will be between 0 and n - 1, inclusive, where n is the number of elements in favorites. Leading zeros are permitted, and numbers may be repeated.
Examples
0)

    
{"0 2", "1", "0 1"}
Returns: 32
The first two people serve themselves immediately (15 seconds). Then, we have to turn the turntable one unit, in either direction (2 seconds), so the last person can serve himself (another 15 seconds). This takes 32 seconds.
1)

    
{"0", "0", "0"}
Returns: 49
Here, each person only likes one entree, so they have to be served one at a time. Three servings (15 seconds each) and two single-unit rotations (2 seconds each) takes a total of 49 seconds.
2)

    
{"4", "1", "2", "3", "0"}
Returns: 50
First, the middle three people take their entrees (15 seconds). Then, we rotate one unit--either way (2 seconds), serve the entree (15 seconds), and then rotate back two units (3 seconds) and serve the last person (15 seconds). All together this takes 50 seconds.
3)

    
{"0 004", "2 3", "0 01", "1 2 3 4", "1 1"}
Returns: 35
Note here that leading zeros are permitted, and that elements may contain repeats.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;
int mark[15][65536];

class TurntableService{
public:
	int calculateTime(vector <string> fav){
		memset(mark,-1,sizeof(mark));
		int n = fav.size();
		vector<vector<bool> > ffav(n,vector<bool>(n,false));
		favRestore(fav,ffav);
		queue<pair<int,int> > mq;
		int perm = (1<<n)-1;
		mq.push(make_pair(0,perm));
		mark[0][perm] = 0;
		int reach = -1;
		while(!mq.empty()){
			int c=mq.front().first,status=mq.front().second;
			mq.pop();
			for(int i=0;i<n;++i){
				int next = (c+i)%n;
				int res = eat(next,status,ffav);
				if(res<status){
					int step = i==0?0:min(i+1,n-i+1);
					int time = mark[c][status]+15+step;
					if(mark[next][res]==-1||mark[next][res]>time){
						mark[next][res] = time;
						if(reach==-1) mq.push(make_pair(next,res));
						if(res==0) 
							if(reach==-1||reach>time) reach = time;
					}
				}
			}
		}
		return reach;
	}
	int eat(int c,int status,const vector<vector<bool> >&ffav){
		int n = ffav.size();
		int res = status;
		for(int i=0,j=c;i<n;++i,j=(j+1)%n){
			if(ffav[i][j]&&(res&(1<<i))) res = res&(~(1<<i));
		}
		return res;
	}
	void favRestore(const vector<string>&fav, vector<vector<bool> > &ffav){
		int n = fav.size();
		for(int i=0;i<n;++i){
			stringstream ss(fav[i]);
			int course;
			while(ss>>course) ffav[i][course] = true;
		}
	}
};
