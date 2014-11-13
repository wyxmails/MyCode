/*
Problem Statement
    
You have decided that too many people do not know how to play chess. So, in an effort to teach the rules you must write some software that helps to understand how chess-pieces affect one another. Your current project involves the knight and its ability to threaten one or more pieces at once. The knight has an unusual style of "jumping" around the board. One move consists of traveling two squares in one of the four cardinal directions, followed by one square perpendicular to the original direction. For example, if a knight is on (0,0), it may move to (2,1), (2,-1), (1,2), (1,-2), (-2, 1), (-2,-1), (-1,2), or (-1,-2). In addition, if a piece is on any of those locations, it is threatened by the knight on (0,0).

You will be given a vector <string> pieces, where each element is a comma delimited set of coordinates. Every element in pieces is formatted as "<x-coordinate>,<y-coordinate>" (quotes and angle brackets for clarity). Calculate and return a vector <string> where each element represents a position from which a knight threatens every piece in pieces. Your return vector <string> must be in the same format as pieces and sorted in increasing order by the x-coordinate. If two sets of coordinates have the same x-coordinate, the one with the smaller y-coordinate must come first.
Definition
    
Class:
GeneralChess
Method:
attackPositions
Parameters:
vector <string>
Returns:
vector <string>
Method signature:
vector <string> attackPositions(vector <string> pieces)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
pieces will contain between 1 and 8 elements, inclusive.
-
Each element in pieces will be formatted as "<x-coordinate>,<y-coordinate>" (quotes and angle brackets for clarity).
-
Each <x-coordinate> will be an integer between -10000 and 10000, inclusive and will not contain leading zeros.
-
Each <y-coordinate> will be an integer between -10000 and 10000, inclusive and will not contain leading zeros.
-
Each element in pieces will be unique.
Examples
0)

    
{"0,0"}
Returns: { "-2,-1",  "-2,1",  "-1,-2",  "-1,2",  "1,-2",  "1,2",  "2,-1",  "2,1" }
This location is threatened from eight different places.
1)

    
{"2,1", "-1,-2"}
Returns: { "0,0",  "1,-1" }
A knight may be in two places such that both pieces are threatened. In chess, placing your pieces in such positions is usually undesirable when your opponent has a knight.
2)

    
{"0,0", "2,1"}
Returns: { }

3)

    
{"-1000,1000", "-999,999", "-999,997"}
Returns: { "-1001,998" }
No three pieces can ever be threatened by a knight from more than one position.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <cstdlib>
using namespace std;
int rim[8][2] = {2,1,2,-1,1,2,1,-2,-2,1,-2,-1,-1,2,-1,-2};
class GeneralChess{
public:
	vector <string> attackPositions(vector <string> pieces){
		int n = pieces.size();
		map<pair<int,int>,int> mark;
		for(int i=0;i<n;++i){
			stringstream ss(pieces[i]);
			int x,y;
			ss>>x;
			ss.ignore();
			ss>>y;
			for(int j=0;j<8;++j){
				mark[make_pair(x+rim[j][0],y+rim[j][1])]++;
			}
		}
		vector<string> res;
		for(auto it=mark.begin();it!=mark.end();++it){
			if(it->second==n){
				ostringstream con1,con2;
				con1<<it->first.first;
				con2<<it->first.second;
				string tmp = con1.str()+","+con2.str();
				res.push_back(tmp);
			}
		}
		return res;
	}
};
