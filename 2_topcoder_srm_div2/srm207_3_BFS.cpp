/*
 Problem Statement
     
 Harry is playing magical chess. In this version of the game, all pieces move the same way as in regular chess, but players can cast some magical spells. Unfortunately, Harry's opponent, Joe, has captured all of Harry's pieces except one knight; Joe, on the other hand, still has a queen and a rook. The only chance Harry has to win this game is to cast a spell, "Haste", that will allow Harry's knight to make several moves in a row. You should determine the minimal number of moves the knight needs to capture both the rook and the queen, assuming neither of them moves. You may capture them in either order - rook first or queen first.  You will be given a string, knight, containing information about the knight. You will also be given a string, queen, and a string, rook, giving you information about Joe's pieces. knight, rook and queen will be formatted as "cr", where c is a character between 'a' and 'h', inclusive, determining the column on the board ('a' is the first column, 'h' is the last), and r is a digit between '1' and '8', inclusive, determining the row (1 is the lowest, 8 is the highest).
 Definition
     
Class:
CaptureThemAll
Method:
fastKnight
Parameters:
string, string, string
Returns:
int
Method signature:
int fastKnight(string knight, string rook, string queen)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
A knight's jump moves him 2 cells along one of the axes, and 1 cell along the other one. In other words, if knight is in the (0,0) now, it can be in (-2, -1), (-2, 1), (2, -1), (2, 1), (-1, -2), (1, -2), (-1, 2) or (1, 2) after his move.
-
The knight will capture one of Joe's pieces if it ends its move in the cell that the piece occupies.
-
The knight cannot jump out of the board.
-
A chessboard has 8 rows and 8 columns.
Constraints
-
knight, rook and queen will all be distinct.
-
knight, rook and queen will be formatted as "cr", where c is a lowercase character between 'a' and 'h', inclusive, and r is a digit between '1' and '8', inclusive.
Examples
0)

    
"a1"
"b3"
"c5"
Returns: 2
From "a1", the knight can move directly to "b3" and capture the rook. From there, the knight can move directly to "c5" and capture the queen.
1)

    
"b1"
"c3"
"a3"
Returns: 3
The rook and the queen are both 1 move away from the knight. Once the knight captures one of them (it doesn't matter which one), it can return to its starting location, and capture the other piece in one more move.
2)

    
"a1"
"a2"
"b2"
Returns: 6
The rook and the queen are close, but it takes 6 moves to capture them.
3)

    
"a5"
"b7"
"e4"
Returns: 3

4)

    
"h8"
"e2"
"d2"
Returns: 6

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <queue>
using namespace std;
int dict[8][8];

class CaptureThemAll{
	public:
		int fastKnight(string k, string r, string q){
			W = 8;
			int kr=0,kq=0,rq=0;
			for(int round=0;round<3;++round){
				for(int i=0;i<W;++i)
				for(int j=0;j<W;++j)
					dict[i][j] = -1;
				if(round==0) kr = bfs(k,r);
				if(round==1) kq = bfs(k,q);
				if(round==2) rq = bfs(r,q);
			}
			if(kr+kq<rq) return min(kr,kq)*2+max(kr,kq);
			else return min(kr,kq)+rq;
		}
	private:
		int W;
		int bfs(string S,string E){
			int is = S[0]-'a',js = S[1]-'1';
			int ie = E[0]-'a',je = E[1]-'1';
			dict[is][js] = 0;
			queue<pair<int,int> > my_q;
			my_q.push(make_pair(is,js));
			while(!my_q.empty()){
				pair<int,int> p = my_q.front();
				my_q.pop();
				for(int i=-2;i<=2;i+=4)
				for(int j=-1;j<=1;j+=2){
					int x = p.first+i;
					int y = p.second+j;
					if(x>=0&&x<8&&y>=0&&y<8&&dict[x][y]==-1){
						dict[x][y] = dict[p.first][p.second]+1;
						if(x==ie&&y==je) return dict[x][y];
						my_q.push(make_pair(x,y));
					}
					x = p.first+j; y = p.second+i;
					if(x>=0&&x<8&&y>=0&&y<8&&dict[x][y]==-1){
						dict[x][y] = dict[p.first][p.second]+1;
						if(x==ie&&y==je) return dict[x][y];
						my_q.push(make_pair(x,y));
					}
				}
			}
			return -1;
		}
};
