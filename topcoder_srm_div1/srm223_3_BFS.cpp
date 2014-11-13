/*
Problem Statement
    
You are in a maze containing revolving doors. The doors can be turned 90 degrees by pushing against them in either direction. You are to find a route from the start square to the end square that involves revolving as few doors as possible. Given a map of the maze, determine the fewest number of door revolutions necessary to get from the start to the end.
In the map:
' ': empty space
'#': wall
'O': center of a revolving door (letter "oh", not zero)
'-': horizontal door (always adjacent to a 'O')
'|': vertical door (always adjacent to a 'O')
'S': start square
'E': end square
Each revolving door will always be oriented horizontally (with two horizontal segments) or vertically (with two vertical segments):
|
O  or  -O-
|
Doors can be revolved 90 degrees by moving onto a door segment from any of the 4 squares diagonally adjacent to the door center, i.e., the 'X' characters below:
X|X     X X
O  or  -O-
X|X     X X
Here is an example map:
###
#E#
## #
####  ##
# S -O-#
# ###  #
#      #
########
In this example, 2 door revolutions are necessary to get from 'S' to 'E'. The first turn is shown here:
###         ###
#E#         #E#
## #        ## #
####  ##    #### |##
# S -O-#    # S  OX#
# ### X#    # ###| #
#      #    #      #
########    ########
And the second turn is shown here:
###         ###
#E#         #E#
## #        ## #
####X|##    #### X##
# S  O #    # S -O-#
# ###| #    # ###  #
#      #    #      #
########    ########
Your method should return an int, the minimum number of door revolutions necessary to get from the start square to the end square. If there is no way to reach the end square, return -1.
Definition
    
Class:
RevolvingDoors
Method:
turns
Parameters:
vector <string>
Returns:
int
Method signature:
int turns(vector <string> map)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
Assume that all squares off the edge of the map are walls.
Constraints
-
map will contain between 3 and 50 elements, inclusive.
-
Each element of map will contain between 3 and 50 characters, inclusive.
-
Each element of map will contain the same number of characters.
-
Each character in map will be one of 'S', 'E', 'O', '-', '|', '#', and ' ' (space).
-
There will be exactly one 'S' and one 'E' in map.
-
There will be between 1 and 10 doors, inclusive, and they will be formatted in map as described in the problem statement.
-
No two doors will be close enough for any part of them to occupy the same square.
-
It is not allowed for a door to be blocked and unable to turn. There will not be any walls in any of the 4 squares immediately adjacent to the center of a door, nor will a door be on the edge of the map.
Examples
0)

    
{ "    ### ",
"    #E# ",
"   ## # ",
"####  ##",
"# S -O-#",
"# ###  #",
"#      #",
"########" }
Returns: 2
This is the example from the problem statement.
1)

    
{ "#### ",
"#S|##",
"# O #",
"##|E#",
" ####" }
Returns: -1
There is no way to reach the end square.
2)

    
{ " |  |  |     |  |  |  |  |  | ",
" O  O EO -O- O  O  O  O  OS O ",
" |  |  |     |  |  |  |  |  | " }
Returns: 7
The optimal path involves turning the 3rd door twice, and the 5th, 6th, 7th, 8th, and 9th doors once each (counting from the left). Note that the 'S' and 'E' do not block doors, and in fact you must turn the 3rd door twice to end up on the 'E'.
3)

    
{ "###########",
"#    #    #",
"#  S | E  #",
"#    O    #",
"#    |    #",
"#         #",
"###########" }
Returns: 0

4)

    
{ "        E",
"    |    ",
"    O    ",
"    |    ",
" -O-S-O- ",
"    |    ",
"    O    ",
"    |    ",
"         " }
Returns: -1
You are stuck, unable to move or turn any doors from this position.
5)

    
{ "##E#   ",
"#  ##  ",
" -O-## ",
" #  ## ",
" ##  ##",
"  -O-  ",
"##  ## ",
" # ### ",
" #  S  " }
Returns: 5

6)

    
{ "#############",
"#  #|##|#   #",
"#   O  O    #",
"# E || || S #",
"#    O  O   #",
"#   #|##|#  #",
"#############" }
Returns: 4
After all the doors have been turned, the map looks like this:
#############
#  # ## #   #
#  -O--O-   #
# E       S #
#   -O--O-  #
#   # ## #  #
#############
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>
using namespace std;
bool dict[51][51][1025];
int doors[51][51];
int m,n;
int rim[4][2] = {-1,0,1,0,0,-1,0,1};
int reachable[51][51];

struct Q{
	int x,y,st,step;
	Q(){}
	Q(int x,int y,int st,int step):x(x),y(y),st(st),step(step){}
	friend bool operator < (Q a,Q b){
		return a.step>b.step;
	}
};
priority_queue<Q> pq;

class RevolvingDoors{
public:
	int turns(vector <string> map){
		memset(doors,-1,sizeof(doors));
		m = map.size(); n = map[0].size();
		int dn=0;
		int sr=0,sc=0;
		for(int i=0;i<m;++i)
		for(int j=0;j<n;++j){
			if(map[i][j]=='S'){sr=i;sc=j;}
			if(map[i][j]=='O'){
			doors[i][j] = dn*10+2;
			for(int k=0;k<4;++k){
				int x = i+rim[k][0],y=j+rim[k][1];
				if(x>=0&&x<m&&y>=0&&y<n){
					if(map[x][y]=='|'||map[x][y]=='-') doors[x][y] = dn*10+0;
					else doors[x][y] = dn*10+1;
				}
			}
			dn++;
			}else if(map[i][j]=='#')
			doors[i][j] = -2;
		}
		Q now(sr,sc,0,0);
		pq.push(now);
		memset(reachable,-1,sizeof(reachable));
		if(dfs(sr,sc,map)){
		return bfs(map);
		}
		return -1;
	}
private:
	bool dfs(int r,int c,vector<string> & map){
		if(r<0||r>=m||c<0||c>=n||doors[r][c]==-2||doors[r][c]%10==2||reachable[r][c]==0) return false;
		if(map[r][c]=='E') return true;
		reachable[r][c] = 0;
		for(int i=0;i<4;++i){
			int x = r+rim[i][0],y=c+rim[i][1];
			if(dfs(x,y,map)) return true;
		}
		return false;
	}
	int bfs(vector<string>&map){
		while(!pq.empty()){
			int x = pq.top().x,y=pq.top().y,st = pq.top().st,step = pq.top().step;
			if(map[x][y]=='E') return step;
			pq.pop();
			for(int i=0;i<4;++i){
				int px = x+rim[i][0],py = y+rim[i][1];
				if(px<0||px>=m||py<0||py>=n||doors[px][py]==-2||doors[px][py]%10==2) continue;
				Q next(px,py,st,step);
				if(doors[px][py]!=-1){
					int id = doors[px][py]/10;
					int dst = ((1<<id)&st)?1:0;
					if(dst==doors[px][py]%10){//a door
						if(doors[px+rim[i][0]][py+rim[i][1]]%10==2) continue; //can not turn
						next.st ^= (1<<id);
						next.step++;
					}
				}
				if(dict[px][py][next.st]) continue;
				pq.push(next);
				dict[px][py][next.st] = true;
			}//for(int i=0;i<4;++i)
		}//while
		return -1;
	}
};
