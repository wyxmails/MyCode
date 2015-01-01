/*

Problem Statement
    
Bomb Man is trapped inside a maze shaped like a grid. You must help him find the exit as fast as possible. The maze will be given as a vector <string> where each element corresponds to a row in the grid and each character in an element corresponds to a cell in that row. '#' marks a wall, '.' an empty cell, 'B' the start position of Bomb Man and 'E' the exit. Below is an example of a maze in this format, given as a vector <string>:
{".....B.",
 ".#####.",
 ".#...#.",
 ".#E#.#.",
 ".###.#.",
 "......."}
In each time unit, Bomb Man can move one cell up, down, left or right. Thus, in the maze above, he can reach the exit in 14 time units by just walking.
To be able to reach the exit quicker, Bomb Man is in possession of a number of bombs, each of which can blow a hole in a wall and thus open up new passages. Instead of moving in any of the four cardinal directions, Bomb Man can (if he has bombs left) blow a hole in a wall located in any of the four neighboring squares. The bomb will go off in the time unit after he has placed the bomb, creating an empty cell that Bomb Man can enter in the time unit after that. That is, if he places a bomb in time unit t, he can enter the cell earliest in time unit t+2. In the maze above, Bomb Man can then reach the exit in 8 time units by first walking left, placing a bomb, waiting for the bomb to explode, and then walking down, down, left, left and down.
Create a class BombMan containing the method shortestPath which takes a vector <string> maze, containing the maze in the format described above, and an int bombs, the number of bombs in Bomb Man's possession. The method should return an int, the least number of time units required for Bomb Man to reach the exit. If it's not possible for Bomb Man to reach the exit, return -1 (see example 1).
Definition
    
Class:
BombMan
Method:
shortestPath
Parameters:
vector <string>, int
Returns:
int
Method signature:
int shortestPath(vector <string> maze, int bombs)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
maze will contain between 1 and 50 elements, inclusive.
-
Each element in maze will contain between 1 and 50 characters, inclusive.
-
Each element in maze will contain the same number of characters.
-
maze will only contain the characters '#', '.', 'B' and 'E'.
-
Exactly one character in maze will be a 'B'.
-
Exactly one character in maze will be a 'E'.
-
bombs will be between 0 and 100, inclusive.
Examples
0)

    
{".....B.",
 ".#####.",
 ".#...#.",
 ".#E#.#.",
 ".###.#.",
 "......."}
1
Returns: 8
This is the example mentioned in the problem statement.
1)

    
{"B.#.#.#...E"}
2
Returns: -1
Bomb Man can only blow through the first two walls, but not the third. Hence the method returns -1.
2)

    
{"..#####",
 "B.#####",
 "..#####",
 "#######",
 "####...",
 "####.E."}
4
Returns: 17
Here Bomb Man has just enough bombs to reach the exit. One way to do this is to walk down, right, down (bomb), down (bomb), right (bomb), right (bomb), right, right, down. This takes 1+1+3+3+3+3+1+1+1 = 17 time units.
3)

    
{".#.#.#.#B#...#.#...#.#...#.#...#.#...#.#.#.......",
 ".#.#.#.#.#.###.###.#.###.#.#.###.###.#.#.#.###.##",
 ".#.#.#...#.#.#.#.#.#...#.....#.#.#...#...#.#.#...",
 ".#.#.###.#.#.#.#.#.###.#.#####.#.###.###.#.#.###.",
 ".............#.#...#...#.....#.#.#...#.#.#.....#.",
 "##.#######.###.#.#####.#.#####.#.###.#.#.#.#.####",
 ".#.#.....#...#...#.#...#...#.#.#...#...#...#.....",
 ".#######.#.#####.#.#.#.#.###.#.###.#.#####.#.####",
 ".#.#.#.#...#.#.#.#.#.#.......#...#.#...#.#.#.....",
 ".#.#.#.###.#.#.#.#.#####.#####.###.###.#.#.######",
 ".....#...#.#...#...#...#...#...#...#.#.#.........",
 "####.###.#.###.###.#.###.#.#.###.###.#.#.########",
 ".......#.........#.#.#.#.#.#.#.#.........#...#...",
 ".#.###.#########.#.#.#.#.###.#.#####.#.#.#.###.##",
 ".#.#.........#.#.#.#.#.....#.#.#.....#.#.........",
 "############.#.#.#.#.#.#####.#.#.################",
 ".#...........#...#.#.#.#...#.#.#...#.#.#.....#...",
 ".#####.#####.###.#.#.#.#.###.#.#.###.#.#.#####.##",
 ".......#...#.#.#.....#...#...#.#.#.#.#...........",
 "##########.#.#.#####.#.###.###.#.#.#.#.##########",
 ".....#...#.....#.#...#.......#.#...#.......#.....",
 "##.#.###.#.###.#.#.#.#.#####.#.#.###.#######.####",
 "...#...#...#.......#.....#.#...#...#.......#.....",
 "####.#.#.#########.#.###.#.#####.###.#.#######.##",
 ".#...#...#.........#.#.....#.........#.#.#.#.....",
 ".#####.#.#.###.#######.#.###.#.#########.#.#.####",
 ".......#.#.#...#.......#.....#.#.#.......#.#.#.#.",
 "########.#.#.#.#####.#.###.#.###.#.#######.#.#.#.",
 ".........#.#.#.#.....#...#.#.........#.#.........",
 "################.#.#.#.#.#.#.#.#######.#.########",
 ".................#.#.#.#.#.#.#...........#.......",
 "########.#####.#.###.#.#.#####.###.#.#####.###.##",
 ".........#...#.#...#.#.#...#.....#.#.........#...",
 ".#####.#####.#.###.#.###.#.#.#.#.#.#####.#.###.#.",
 ".#.....#.........#.#.#...#.#.#.#.#.#.....#...#.#.",
 "####.#####.###.#.#.#.#.#.#.###.###.#.#.#.#.#####.",
 ".....#.....#.#.#.#.#.#.#.#.#...#...#.#.#.#...#...",
 "####.#.#.###.#.#.###.#.###.#.#.#####.#.#.#.######",
 ".....#.#.#.#...#...#.#...#.#.#...#...#.#.#.......",
 "##########.#.#.#.#####.###.#.#.###.#.###.#####.##",
 "...#.#...#...#.#.....#.#...#.#...#.#.#.......#...",
 ".#.#.#.#.#.#.#.#.#.#.###.#.#########.###.#.#.#.#.",
 ".#.#...#...#.#.#.#.#...#.#...#.......#...#.#.#.#.",
 "##.###.#.#.###.#.#.#.#.#####.#.#.#.###.#.########",
 ".......#.#...#.#.#.#.#.#.....#.#.#...#.#.........",
 "####.#######.#.#####.#.###.#.#.###.#.#.#.########",
 "E..#.......#.#.....#.#.#.#.#.#.#...#.#.#.........",
 "##.#.#.#.###.###.###.###.#.#.###.#.#.#.#.#######.",
 ".....#.#...#.#.....#.#.....#...#.#.#.#.#.....#..."}
3
Returns: 76

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int rim[][2] = {1,0,0,-1,-1,0,0,1};
bool visited[51][51];
struct Q{
	int x,y,t,b;
	Q(int x,int y,int t,int b):x(x),y(y),t(t),b(b){}
	friend bool operator<(const Q&a,const Q&b){
		if(a.t!=b.t) return a.t>b.t;
		if(a.b!=b.b) return a.b>b.b;
		return false;
	}
};

class BombMan{
public:
	int shortestPath(vector <string> maze, int bombs){
		memset(visited,false,sizeof(visited));
		int bx,by,ex,ey;
		bx=by=ex=ey=0;
		int m = maze.size();
		int n = maze[0].size();
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				if(maze[i][j]=='B'){bx=i;by=j;}
				if(maze[i][j]=='E'){ex=i;ey=j;}
			}
		}
		//cout << bx << " " << by << " " << ex << " " << ey << endl;
		priority_queue<Q> mq;
		Q nn(bx,by,0,0);
		mq.push(nn);
		while(!mq.empty()){
			Q cur = mq.top();
			mq.pop();
			if(cur.x==ex&&cur.y==ey) return cur.t;
			if(visited[cur.x][cur.y]) continue;
			visited[cur.x][cur.y] = true;
			for(int i=0;i<4;++i){
				int x=cur.x+rim[i][0],y=cur.y+rim[i][1];
				if(x<0||x>=m||y<0||y>=n) continue;
				if(maze[x][y]!='#'){
					Q next(x,y,cur.t+1,cur.b);
					mq.push(next);
				}else if(cur.b<bombs){
					Q next(x,y,cur.t+3,cur.b+1);
					mq.push(next);
				}
			}
		}
		return -1;
	}
};
