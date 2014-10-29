/*
 Implement the "paint fill" function that one might see on many image editing programs. That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color, fill in the surrounding area until the color changes from the original color.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PaintFill(vector<vector<int> > & screen,int x,int y,int color){
	int m = screen.size();
	if(m==0) return;
	int n = screen[0].size();
	if(n==0) return;
	if(x>=m||y>=n) return;
	int cur = screen[x][y];
	screen[x][y] = color;
	if(x+1<m&&screen[x+1][y]==cur) PaintFill(screen,x+1,y,color);
	if(x-1>=0&&screen[x-1][y]==cur) PaintFill(screen,x-1,y,color);
	if(y+1<n&&screen[x][y+1]==cur) PaintFill(screen,x,y+1,color);
	if(y-1>=0&&screen[x][y-1]==cur) PaintFill(screen,x,y-1,color);
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	int m = rand()%5+1;
	int n = rand()%5+1;
	cout << "m: " << m << " n: " << n << endl;
	vector<vector<int> > vec(m,vector<int>(n,0));
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			int tmp = rand()%5;
			cout << tmp << " ";
			vec[i][j] = tmp;
		}
		cout << endl;
	}
	int x = rand()%m;
	int y = rand()%n;
	int color = rand()%5+5;
	cout << "x: " << x << " y: " << y << " color: " << color << endl;
	PaintFill(vec,x,y,color);
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
