/*

Problem Statement
    
You are the famous explorer Indiana Jones, or Lara Croft, take your pick. You are exploring the ruins of the dungeons beneath King Lockumup IV the Good's castle in Flatlandia. Of course, the dungeon layout is two-dimensional (like your character), East-West and Up-Down in this case, in a regular grid.
                        Surface
                    | | | | | | | | |
level 0            -R-R-R-R-R-R-R-R-R-
                    | | | | | | | | |
level 1   <- West  -R-R-R-R-R-R-R-R-R- East ->
                    | | | | | | | | |
level 2            -R-R-R-R-R-R-R-R-R-  
                    | | | | | | | | |
                    Depths of Despair
"R" indicates a room. "-" indicates an east-west passageway. "|" indicates an up-down passageway.
Because it is rough going in the passageways between the rooms (there has been no dungeon maintenance for centuries), it is frequently easier to travel through a passageway in a particular direction than in the opposite direction. Each room has four passageways leaving in the directions East (right), West (left), Up, and Down which lead to adjacent rooms (except the Down in the bottom-most rooms, the East in the east-most rooms, and the West in the west-most rooms, which have dead-end passageways due to ancient budget cuts, and Up in the topmost rooms which lead to the surface). The time it takes to travel through a passageway from a given room to the adjacent rooms is given in four vector <string>s depending on your direction of travel. A digit between 0 and 9 indicates how many time units (in the local system of decimillifortnights, dmfs) are taken to leave the room in that direction and travel through the passageway to the adjacent room. An 'x' character indicates that the travel in that direction is too difficult and can not be done. The dead end passageways (at the edges of the dungeon) have time values, or 'x', specified (because they were in the original plans for the dungeon and we have an old map), but we can not actually travel through these passageways in this problem. The dungeon does *not* wrap in any direction (you are probably thinking of the castle of Queen Mobius the One Sided, the former stripper).
In other words, if you are in room (i,j), where i is the up-down level and j is your easting (ie. how far east you are) coordinate, then
up[i][j] tells how many dmfs it takes to get to (i-1,j).
down[i][j] tells how many dmfs it takes to get to (i+1,j).
east[i][j] tells how many dmfs it takes to get to (i,j+1).
west[i][j] tells how many dmfs it takes to get to (i,j-1).
If it is obvious to you how these four directional time value arrays map to a directed graph of the dungeon, then skip this next section of the problem description, which goes into detail, and continue reading below for more of the important problem description information.
For example if given the inputs up and west (shown below)
up = {"123",      west = {"222",
      "111",              "131",
      "121"}              "444"}
You would have the following time values for each passageway while going up or west.
                   Surface
                    1 2 3 
level 0            2R2R2R-      Up and West going
                    1 1 1       Passageway times
level 1      West  1R3R1R- East 
                    1 2 1
level 2            4R4R4R-      
                    | | |
              Depths of Despair
The dead-end passageways on the far west with times {2, 1, 4} are useless and can be ignored.
 
Similarly if you have the inputs down and east (shown below)
down = {"987",      east = {"222",
        "111",              "3x3",
        "121"}              "111"}
You would have the following time values for each passageway while going down or east.
                   Surface
                    | | |
level 0            -R2R2R2     Down and East going
                    9 8 7      Passageway times
level 1      West  -R3RxR3 East 
                    1 1 1
level 2            -R1R1R1
                    1 2 1 
               Depths of Despair
The dead-end passageways on the far east with times {2, 3, 1} and the very bottom with times {1, 2, 1} are also useless to you and can be ignored.
We are back from the boring details, here is some more important information.
Unfortunately for you, Dr. Jones or Dr. Croft, you have just triggered an ancient trap, and the dungeon is beginning to to fill with water. First the lowest level fills with water. If the East-West width of the dungeon is n rooms, then each level of the dungeon takes n decimillifortnights to fill. Once full of water, the rooms on that level are no longer accessible. While partly full of water, they are still fully accessible. Time starts at time = 0, at time = n the lowest level becomes inaccessible, at time = 2n the second lowest level becomes inaccessible, etc. So if you are in, or pass through, a room on the lowest level at time >= n, you are dead.
For simplicity, we will only consider if the room is completely filled with water when you enter. So if you leave a nearly filled room, going up through a slow passageway, and arrive somewhat later in a now nearly filled room one level up, this is ok. We will ignore the physics which would lead us to think the passageway would fill with water before the room above it. Only check for drowning when you enter the room. Also the surface (above level 0) never fills with water (we run out of water before then), so you can not drown on the surface.
Your goal is to get to the surface as fast as possible. You start at the location (startLevel, startEasting). "Easting" is how far east you are in the local coordinate system. Rooms have Easting coordinates between 0 and n-1 inclusive, where n is the number of rooms on each level. Return the number of time units (decimillifortnights) it takes to escape, or -1 if escape is impossible.
For example:
up = {"0x4",  down = {"0x9",   east = {"1x9",   west = {"0x9",
      "0x3",          "009",           "0x9",           "0x0",
      "0x3"}          "0x9"}           "009"}           "009"}
startLevel = 2, startEasting = 2
We start in the lower right corner. If water were not an issue, we could reach each of the various rooms with various paths, and the earliest possible times in which we could reach each room are shown below. If we go straight up, the passageways take 3, 3 and 4 dmfs reaching the surface in 10 dmfs. We could also follow the path: up (3 dmfs), west (0 dmfs), down (0 dmfs), west (0 dmfs), up (0 dmfs), up (0 dmfs), and up (0 dmfs) reaching the surface in 3 dmfs. The diagram below shows the minimum time in which we could first get to each room (if water were not an issue), and the passageways used are shown with '|' for up-down, and '-' for east-west.
      3  10      - surface
      |   |  -------------
      3-4 6      - level 0
      |   |
      3 3-3      - level 1
      | | |
      3-3 0      - level 2
But since level 2 fills with water at time 3, we can not move from (1,1) down to (2,1) at time = 3 dmfs. The actual rooms we can reach, considering flooding, are shown below, where 'w' represents a room which is full of water when we first could move into it, and 'x' represents a room we can never reach:
         10      - surface
          |   ------------
      x w-6      - level 0
          |
      x 3-3      - level 1
        | |
      x w 0      - level 2
In this example we can reach the surface in 10 dmfs by going straight up, and this is the minimum, so return 10.
Definition
    
Class:
DungeonEscape
Method:
exitTime
Parameters:
vector <string>, vector <string>, vector <string>, vector <string>, int, int
Returns:
int
Method signature:
int exitTime(vector <string> up, vector <string> down, vector <string> east, vector <string> west, int startLevel, int startEasting)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
up, down, east and west have the same constraints, only up is described.
-
up will contain between 1 and 50 elements inclusive.
-
each element of up will contain between 1 and 50 characters inclusive.
-
each character in each element of up will be a digit between '0' and '9' inclusive or 'x'.
-
up, down, east and west will all have exactly the same number of elements in each.
-
All elements of up, down, east and west will contain the same number of characters.
-
startLevel will be between 0 and (the number of elements in up) - 1 inclusive.
-
startEasting will be between 0 and (the number of characters in up[0]) - 1 inclusive.
Examples
0)

    
{"0x4",
 "0x3",
 "0x3"}
{"0x9",
 "009",
 "0x9"}
{"0x9",
 "1x9",
 "009"}
{"0x9",
 "0x0",
 "009"}
2
2
Returns: 10
The example from above.
1)

    
{"xxxxxxxxx1",
 "1xxxxxxxxx",
 "xxxxxxxxx1"}
{"xxxxxxxxxx",
 "xxxxxxxxxx",
 "xxxxxxxxxx"}
{"1111111111",
 "xxxxxxxxxx",
 "1111111111"}
{"xxxxxxxxxx",
 "1111111111",
 "xxxxxxxxxx"}
2
0
Returns: 30
Only one serpentine path out, just avoiding the water.
2)

    
{"xxxxxxxxx1",
 "xxxx999991",
 "x999999991"}
{"1111111111",
 "1111111111",
 "1111111111"}
{"1111122242",
 "2222222241",
 "2111111111"}
{"xxxxxxxxx1",
 "1111111111",
 "xxxxxxxxx1"}
2
0
Returns: -1
No way out that is fast enough, glub, glub...
3)

    
{"1x2x3x4x5x6x7x8x9",
 "00000000000000000",
 "98765432223456789",
 "12345678987654321"}
{"00000000000000000",
 "00000000000000000",
 "00000000000000000",
 "00000000000000000"}
{"xxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxx",
 "22222222222222222",
 "33333333333333333"}
{"xxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxx",
 "22222222222222222",
 "33333333333333333"}
3
12
Returns: 17

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

bool visited[51][51];

struct Q{
	int x,y,time;
	Q(int x,int y,int time):x(x),y(y),time(time){}
	friend bool operator <(const Q&a,const Q&b){
		return a.time>b.time;
	}
};

class DungeonEscape{
public:
	int exitTime(vector <string> up, vector <string> down, vector <string> east, 
			vector <string> west, int sL, int sE){
		memset(visited,false,sizeof(visited));
		int m = up.size();
		int n = up[0].size();
		priority_queue<Q> mq;
		Q nn(sL,sE,0);
		mq.push(nn);
		while(!mq.empty()){
			Q cur = mq.top();
			mq.pop();
			if(cur.x<0) return cur.time;
			if(visited[cur.x][cur.y]) continue;
			visited[cur.x][cur.y] = true;
			if(up[cur.x][cur.y]!='x'){
				if(cur.x==0||cur.time+(up[cur.x][cur.y]-'0')<(m+1-cur.x)*n){
					Q next(cur.x-1,cur.y,cur.time+(up[cur.x][cur.y]-'0'));
					mq.push(next);
				}
			}
			if(cur.x+1<m&&down[cur.x][cur.y]!='x'&&cur.time+(down[cur.x][cur.y]-'0')<(m-1-cur.x)*n){
				Q next(cur.x+1,cur.y,cur.time+(down[cur.x][cur.y]-'0'));
				mq.push(next);
			}
			if(cur.y-1>=0&&west[cur.x][cur.y]!='x'&&cur.time+(west[cur.x][cur.y]-'0')<(m-cur.x)*n){
				Q next(cur.x,cur.y-1,cur.time+(west[cur.x][cur.y]-'0'));
				mq.push(next);
			}
			if(cur.y+1<n&&east[cur.x][cur.y]!='x'&&cur.time+(east[cur.x][cur.y]-'0')<(m-cur.x)*n){
				Q next(cur.x,cur.y+1,cur.time+(east[cur.x][cur.y]-'0'));
				mq.push(next);
			}
		}
		return -1;
	}
};
