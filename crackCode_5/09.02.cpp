/*
 Imagine a robot sitting on the upper left comer of an X by Ygrid. Therobot can only move in two directions: right and down. How many possible paths are there for the robot togofrom (0,0) to (X, Y)?
 FOLLOW UP
 Imagine certain spots are "off limits," such that the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to the bottom right.
 */

#include <iostream>
#include <vector>
using namespace std;

int GetPathNum(int X,int Y){
	vector<int> mark(Y+1,0);
	mark[Y] = 1;
	for(int i=X;i>=0;--i){
		for(int j=Y-1;j>=0;--j)
			mark[j] = mark[j]+mark[j+1];
	}
	return mark[0];
}

struct Point{
	int x;
	int y;
	Point(int x,int y):x(x),y(y){}
};

bool GetPath(const vector<vector<char> > &board,int x,int y,vector<Point>&path){
	if(x>=board.size()||y>=board[0].size()){
		if(x==board.size()-1||y==board[0].size()-1) return true; 
		return false;
	}
	if(board[x][y]==' '){
		path.push_back(Point(x,y));
		if(GetPath(board,x+1,y,path)) return true;
		if(GetPath(board,x,y+1,path)) return true;
		path.pop_back();
		return false;
	}else return false;
}

vector<Point> GetPath(const vector<vector<char> > &board){
	vector<Point> path;
	int X = board.size();
	if(X==0) return path;
	int Y = board[0].size();
	if(Y==0) return path;
	GetPath(board,0,0,path);
   	return path;
}

int main(int argc,char*argv[]){
	int X=2,Y=2;
	cout << X << " " << Y << " : " << GetPathNum(X,Y) << endl;
	X=2,Y=3;
	cout <<  X << " " << Y << " : " << GetPathNum(X,Y) << endl;
	X=1,Y=4;
	cout << X << " " << Y << " : " <<  GetPathNum(X,Y) << endl;
	X=2,Y=4;
	cout << X << " " << Y << " : " <<  GetPathNum(X,Y) << endl;
	X=1,Y=5;
	cout << X << " " << Y << " : " <<  GetPathNum(X,Y) << endl;
	X=2,Y=4;
	cout << X << " " << Y << " : " <<  GetPathNum(X,Y) << endl;
	X=3,Y=3;
	cout << X << " " << Y << " : " <<  GetPathNum(X,Y) << endl;
	X=3,Y=4;
	cout << X << " " << Y << " : " <<  GetPathNum(X,Y) << endl;
	X=2,Y=5;
	cout << X << " " << Y << " : " <<  GetPathNum(X,Y) << endl;
	X=3,Y=5;
	cout << X << " " << Y << " : " <<  GetPathNum(X,Y) << endl;
	vector<vector<char> > board(2,vector<char>(2,' '));
	board[0][1] = '.';
	vector<Point> res = GetPath(board);
	for(int i=0;i<res.size();++i)
		cout << res[i].x << " " << res[i].y << endl;
	return 0;
}
