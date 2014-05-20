#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct node{
	bool inpath;
	bool upwall;
	bool rtwall;
	int sdist;
	int edist;
}node;

int main(int argc,char*argv[]){
	int t,width,height,pathlen,outsize;
	int x,y,x1,y1,xdes,ydes;
	string strPath;
	node maze[100][100];
	queue<pair<int,int> > q;
	cin>>t;
	while(t){
		for(int i=0;i<100;++i){
			for(int j=0;j<100;++j){
				maze[i][j].inpath = false;
				maze[i][j].upwall = false;
				maze[i][j].rtwall = false;
				maze[i][j].sdist = -1;
				maze[i][j].edist = -1;
			}
		}
		cin>>width>>height>>strPath>>outsize;
		pathlen = strPath.size();
		x=0,y=0;
		maze[x][y].inpath = true;;
		for(int i=0;i<pathlen;++i){
			switch(strPath[i]){
				case 'U':
					y++;
					break;
				case 'R':
					x++;
					break;
				case 'L':
					x--;
					break;
				case 'D':
					y--;
					break;
			}
			maze[x][y].inpath = true;
		}
		xdes = x;
		ydes = y;
		for(int i=0;i<outsize;++i){
			cin>>x>>y>>x1>>y1;
			if(1==(x1-x))	maze[x][y].rtwall = true;
			if(1==(x-x1))	maze[x1][y1].rtwall = true;
			if(1==(y1-y))	maze[x][y].upwall = true;
			if(1==(y-y1))	maze[x1][y1].upwall = true;
		}
		//(BFS)compute distance from start node
		q.push(make_pair(0,0));
		maze[0][0].sdist = 0;
		while(!q.empty()){
			x=q.front().first, y=q.front().second;
			if(x<width-1&&maze[x][y].rtwall==false&&maze[x+1][y].sdist==-1){
				maze[x+1][y].sdist = maze[x][y].sdist + 1;
				q.push(make_pair(x+1,y));
			}
			if(x>0&&maze[x-1][y].rtwall==false&&maze[x-1][y].sdist==-1){
				maze[x-1][y].sdist = maze[x][y].sdist + 1;
				q.push(make_pair(x-1,y));
			}
			if(y<height-1&&maze[x][y].upwall==false&&maze[x][y+1].sdist==-1){
				maze[x][y+1].sdist = maze[x][y].sdist + 1;
				q.push(make_pair(x,y+1));
			}
			if(y>0&&maze[x][y-1].upwall==false&&maze[x][y-1].sdist==-1){
				maze[x][y-1].sdist = maze[x][y].sdist + 1;
				q.push(make_pair(x,y-1));
			}
			q.pop();
		}
		//(BFS)compute distance from destination(end) node
		q.push(make_pair(xdes,ydes));
		maze[xdes][ydes].edist = 0;
		while(!q.empty()){
			x=q.front().first,y=q.front().second;
			if(x>0&&maze[x-1][y].rtwall==false&&maze[x-1][y].edist==-1){
				maze[x-1][y].edist = maze[x][y].edist + 1;
				q.push(make_pair(x-1,y));
			}
			if(x<width-1&&maze[x][y].rtwall==false&&maze[x+1][y].edist==-1){
				maze[x+1][y].edist = maze[x][y].edist + 1;
				q.push(make_pair(x+1,y));
			}
			if(y>0&&maze[x][y-1].upwall==false&&maze[x][y-1].edist==-1){
				maze[x][y-1].edist = maze[x][y].edist + 1;
				q.push(make_pair(x,y-1));
			}
			if(y<height-1&&maze[x][y].upwall==false&&maze[x][y+1].edist==-1){
				maze[x][y+1].edist = maze[x][y].edist + 1;
				q.push(make_pair(x,y+1));
			}
			q.pop();
		}
		//judgement
		bool flag = true;
		for(int i=0;i<width&&flag;++i){
			for(int j=0;j<height&&flag;++j){
				if(maze[i][j].sdist==-1&&maze[i][j].edist==-1){
					flag = false;
				}
				if(maze[i][j].inpath==false&&
					maze[i][j].sdist+maze[i][j].edist<=pathlen){
					flag = false;
				}
				if(j<height-1&&maze[i][j].upwall&&
					(maze[i][j].sdist+maze[i][j+1].edist+1>pathlen&&//because shortestpath,so must be && signal
					maze[i][j].edist+maze[i][j+1].sdist+1>pathlen)){
					flag = false;
				}
				if(x<width-1&&maze[i][j].rtwall&&
						(maze[i][j].sdist+maze[i+1][j].edist+1>pathlen&&//because shortestpath,so must be && signal
						 maze[i][j].edist+maze[i+1][j].sdist+1>pathlen)){
					flag = false;
				}
			}
		}
		if(flag) cout << "CORRECT" << endl;
		else cout << "INCORRECT" << endl;
		t--;
	}
}
