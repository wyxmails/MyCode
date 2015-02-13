/*

Problem Statement
    
A shadow sculpture is a 3D object that seems amorphous but casts a beautiful shadow.   You want to create a simple shadow sculpture that will consist of unit cubes. More precisely, imagine an n*n*n cube that is aligned with the coordinate axes and divided into unit cubes. Your sculpture will consist of some of those unit cubes (possibly none or all of them). The unit cubes have coordinates (x,y,z) where 0 <= x,y,z < n.   You have already determined three shadows your sculpture should cast: its orthogonal projections onto the XY, YZ, and ZX plane. You are given their description in three vector <string>s: XY, YZ, and ZX.   Their meaning is as follows: For each i and j, the character XY[i][j] is either 'Y' or 'N'. The character 'Y' means that the unit square (i,j) of the projection is dark. In other words, if XY[i][j] is 'Y', at least one of the cubes with coordinates (i,j,k) has to be a part of your sculpture. On the other hand, if XY[i][j] is 'N', none of the cubes with coordinates (i,j,k) may belong into your sculpture. YZ and ZX describe the other two projections in the same way. E.g., if ZX[i][j] is 'Y', you have to use at least one of the cubes (j,k,i).   Finally, there is one last constraint: Your entire sculpture has to be 6-connected. (Formally: Your sculpture must form one connected component, given that two cubes are adjacent iff they share a common face.)   Return "Possible" if it is possible to construct a sculpture that matches all the given constraints. Otherwise, return "Impossible".
Definition
    
Class:
ShadowSculpture
Method:
possible
Parameters:
vector <string>, vector <string>, vector <string>
Returns:
string
Method signature:
string possible(vector <string> XY, vector <string> YZ, vector <string> ZX)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
n will be between 1 and 10, inclusive.
-
XY, YZ and ZX will contain exactly n elements.
-
Each element of XY, YZ and ZX will contain exactly n characters.
-
Each element of XY, YZ and ZX will contain only 'Y' and 'N'.
Examples
0)

    
{"YN","NN"}
{"YN","NN"}
{"YN","NN"}
Returns: "Possible"
It is possible: we only have one solid cell at (0, 0, 0).
1)

    
{"YN","NY"}
{"YN","NY"}
{"YN","NY"}
Returns: "Impossible"
Here it is impossible to make a valid sculpture. Note that you can make all three projections look right by using exactly two cubes: (0,0,0) and (1,1,1). However, this sculpture is not 6-connected.
2)

    
{"YYY","YNY","YYY"}
{"YYY","YNY","YYY"}
{"YYY","YNY","YYY"}
Returns: "Possible"

3)

    
{"YYY","YNY","YYY"}
{"NYY","YNY","YYY"}
{"YYY","YNY","YYN"}
Returns: "Impossible"

4)

    
{"N"}
{"N"}
{"N"}
Returns: "Possible"
A sculpture that consists of no cubes is connected.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <algorithm>
using namespace std;

vector<vector<vector<int> > > cube;

class ShadowSculpture{
public:
	string possible(vector <string> XY, vector <string> YZ, vector <string> ZX){
		int n = XY.size();
		cube.assign(n,vector<vector<int> >(n,vector<int>(n,0)));
		int x,y,z;
		x=y=z=0;
		bool poss=true;
		for(x=0;x<n;++x)
		for(y=0;y<n;++y){
			if(poss&&(XY[x][y]=='Y'||YZ[y][z]=='Y'||ZX[z][x]=='Y')) poss = false;
			if(XY[x][y]=='Y')
			for(z=0;z<n;++z){
				if(YZ[y][z]=='Y'){
					if(ZX[z][x]=='Y') cube[x][y][z] = 1;
				}
			}
		}
		x=y=z=0;
		for(int i=0;i<n&&!poss;++i)
		for(int j=0;j<n&&!poss;++j)
		for(int k=0;k<n;++k)
			if(cube[i][j][k]==1){
				poss = true;
				x=i;y=j;z=k;
			vector<vector<vector<int> > > tmp = cube;
			bool xy[n][n], yz[n][n], zx[n][n];
			memset(xy,false,sizeof(xy));
			memset(yz,false,sizeof(yz));
			memset(zx,false,sizeof(zx));
			//erase sculpture
			queue<tuple<int,int,int> > mq;
			cube[x][y][z] = 0;
			mq.push(make_tuple(x,y,z));
			while(!mq.empty()){
				tuple<int,int,int> cur = mq.front();
				mq.pop();
				x = get<0>(cur); y = get<1>(cur); z = get<2>(cur);
				cube[x][y][z] = 0;
				xy[x][y] = true; yz[y][z] = true; zx[z][x] = true;
				if(x+1<n&&cube[x+1][y][z]) {
					mq.push(make_tuple(x+1,y,z));
					cube[x+1][y][z] = 0;
				}
				if(x-1>=0&&cube[x-1][y][z]){
					mq.push(make_tuple(x-1,y,z));
					cube[x-1][y][z] = 0;
				}
				if(y+1<n&&cube[x][y+1][z]){
					mq.push(make_tuple(x,y+1,z));
					cube[x][y+1][z] = 0;
				}
				if(y-1>=0&&cube[x][y-1][z]){
					mq.push(make_tuple(x,y-1,z));
					cube[x][y-1][z] = 0;
				}
				if(z+1<n&&cube[x][y][z+1]){
					mq.push(make_tuple(x,y,z+1));
					cube[x][y][z+1] = 0;
				}
				if(z-1>=0&&cube[x][y][z-1]){
					mq.push(make_tuple(x,y,z-1));
					cube[x][y][z-1] = 0;
				}
			}
			//check possible
			for(x=0;x<n&&poss;++x)
			for(y=0;y<n&&poss;++y)
				if((XY[x][y]=='Y'&&!xy[x][y])
					||(YZ[x][y]=='Y'&&!yz[x][y])
					||(ZX[y][x]=='Y'&&!zx[y][x])){
					 poss = false;
					 cube = tmp;
				}
				
		}
		if(poss) return "Possible";
		return "Impossible";
	}
};
