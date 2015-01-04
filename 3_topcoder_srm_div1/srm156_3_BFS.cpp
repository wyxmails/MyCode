/*

Problem Statement
    
Given a board consisting of empty space, walls, and the starting positions of two players A and B, determine the minimum number of turns it will take for players A and B to switch positions on the board.
During a turn, one or both players may take a step. A step is defined as a unit movement up, down, left, right, or in any of the four diagonals. Players may not step into walls or off the board. Players may never share the same square at the end of a turn. Players may not cross paths during a turn. Crossing paths occurs when players A and B switch positions in a single turn. For example, assume player A is in the upper left corner of the board, and player B is in the square immediately to his right. Player A may not move right while player B moves left, since they would be passing each other. Player A can, however, move right if player B moves in any other direction.
You will be given a vector <string> board, representing the game board. board will contain exactly one 'A' and exactly one 'B'; each other character will be either '.' (empty space), or 'X' (a wall). Your method should return the minimum number of turns necessary for players A and B to switch positions, or -1 if this is impossible.
Definition
    
Class:
PathFinding
Method:
minTurns
Parameters:
vector <string>
Returns:
int
Method signature:
int minTurns(vector <string> board)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
(In the following notes, assume that the coordinate system is given as (row, col). For example, the upper-left corner of the board is (0,0), and the square immedately below it is (1,0).)
-
If player A is at (0,0) and player B is at (0,1), player A would be allowed to move down-right at the same time that player B moves down-left. This is not considered crossing paths, even though the two players would meet at (0.5, 0.5).
-
However, if player A is at (0,0) and player B is at (1,1), player A would not be allowed to move down-right at the same time that player B moves up-left. This is considered crossing paths because players A and B have switched positions at the end of a single turn.
-
It is permissible to move diagonally through walls. That is, a player may move from (0,0) to (1,1) even if there are walls at (0,1) and (1,0).
Constraints
-
board will contain between 2 and 20 elements, inclusive.
-
Each element of board will contain between 2 and 20 characters, inclusive.
-
Each element of board will contain the same number of characters.
-
Each element of board will consist of only the characters '.', 'X'. 'A', and 'B'.
-
board will contain exactly one 'A' and exactly one 'B'.
Examples
0)

    
{"....",
 ".A..",
 "..B.",
 "...."}
Returns: 2
There are many ways to switch positions in two turns. For example, on turn one, player A could move right while player B moves up-right. Then, on turn two, player A could move down while player B stays where he is. It is illegal for the players to switch positions in a single turn. Therefore, the method returns 2.
1)

    
{"XXXXXXXXX",
 "A...X...B",
 "XXXXXXXXX"}
Returns: -1
Since the players cannot reach each other, they obviously cannot switch positions.
2)

    
{"XXXXXXXXX",
 "A.......B",
 "XXXXXXXXX"}
Returns: -1
Even though the players can reach each other, there is still no way for player B to ever get on the left side of player A.
3)

    
{"XXXXXXXXX",
 "A.......B",
 "XXXX.XXXX"}
Returns: 8
Players A and B spend the first three turns moving towards each other. On turn four, player A moves down-right while player B moves left. On turn five, player A moves up-right while player B moves left. It then takes three more turns of the players moving away from each other before they have switched positions, for a total of 8 turns.
4)

    
{"...A.XXXXX.....",
 ".....XXXXX.....",
 "...............",
 ".....XXXXX.B...",
 ".....XXXXX....."}
Returns: 13

5)

    
{"AB.................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "...................X",
 ".XXXXXXXXXXXXXXXXXXX"}
Returns: 379

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int rim[][2] = {1,0,1,-1,0,-1,-1,-1,-1,0,-1,1,0,1,1,1};
bool visited[20][20][20][20];

class nnode{
public:
	int ax,ay,bx,by;
	int step;
	nnode(int ax,int ay,int bx,int by,int s):ax(ax),ay(ay),bx(bx),by(by),step(s){}
};

class PathFinding{
public:
	int minTurns(vector <string> board){
		int m = board.size();
		int n = board[0].size();
		memset(visited,false,sizeof(visited));
		int Ax,Ay,Bx,By;
		Ax=Ay=Bx=By=0;
		nnode nn(0,0,0,0,0);
		for(int i=0;i<m;++i)
		for(int j=0;j<n;++j){
			if(board[i][j]=='A') {Ax=nn.ax=i;Ay=nn.ay=j;}
			if(board[i][j]=='B') {Bx=nn.bx=i;By=nn.by=j;}
		}
		queue<nnode> mq;
		mq.push(nn);
		while(!mq.empty()){
			nnode cur = mq.front();
			mq.pop();
			//cout << cur.ax << " " << cur.ay << " " << cur.bx << " " << cur.by << " " << cur.step<< endl;
			if(cur.ax==Bx&&cur.ay==By&&cur.bx==Ax&&cur.by==Ay) return cur.step;
			for(int i=0;i<8;++i){
				int ax = cur.ax+rim[i][0],ay=cur.ay+rim[i][1];
				if(ax<0||ax>=m||ay<0||ay>=n) continue;
				if(board[ax][ay]=='X') continue;
				for(int j=0;j<8;++j){
					int bx=cur.bx+rim[j][0],by=cur.by+rim[j][1];
					if(ax==bx&&ay==by) continue;
					if(bx<0||bx>=m||by<0||by>=n) continue;
					if(board[bx][by]=='X') continue;
					if(ax==cur.bx&&ay==cur.by&&bx==cur.ax&&by==cur.ay) continue;
					if(visited[ax][ay][bx][by]) continue;
					visited[ax][ay][bx][by] = true;
					nnode nn1(ax,ay,bx,by,cur.step+1);
					mq.push(nn1);
				}
			}
			//if(!move){
				for(int i=0;i<8;++i){
					int ax = cur.ax+rim[i][0],ay=cur.ay+rim[i][1];
					if(ax<0||ax>=m||ay<0||ay>=n) continue;
					if(board[ax][ay]=='X') continue;
					if(ax==cur.bx&&ay==cur.by) continue;
					if(visited[ax][ay][cur.bx][cur.by]) continue;
					visited[ax][ay][cur.bx][cur.by] = true;
					nnode nn2(ax,ay,cur.bx,cur.by,cur.step+1);
					mq.push(nn2);
				}
				for(int j=0;j<8;++j){
					int bx=cur.bx+rim[j][0],by=cur.by+rim[j][1];
					if(bx<0||bx>=m||by<0||by>=n) continue;
					if(board[bx][by]=='X') continue;
					if(bx==cur.ax&&by==cur.ay) continue;
					if(visited[cur.ax][cur.ay][bx][by]) continue;
					visited[cur.ax][cur.ay][bx][by] = true;
					nnode nn3(cur.ax,cur.ay,bx,by,cur.step+1);
					mq.push(nn3);
				}
		}
		return -1;
	}
};
