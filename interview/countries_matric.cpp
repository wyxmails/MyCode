/*
 2D matrix with 0s and 1s. Try to find out how many countries in this matrix? 

 For example: 
 [[1,1,1,0] 
 [1,1,0,0] 
 [0,0,0,1]] 
 return 3, because one for 1s, one for 0s, and one for the last one. 

 another example: 
 [[1,1,1,1] 
 [0,0,0,0] 
 [1,0,0,1]] 
 return 4
 Country means a group of numbers that are connected (adjacent to each other). For his first example 
 [[1,1,1,0] 
 [1,1,0,0] 
 [0,0,0,1]] 

 First country is 
 [[1,1,1,] 
 [1,1,] 
 [,,,] 

 likewise, second country then becomes all the zeros, and the third country is the one in the right bottom corner.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//BFS solution
int countries(vector<vector<int> > matrix){
	int m = matrix.size();
	if(m==0) return 0;
	int n = matrix[0].size();
	if(n==0) return 0;
	int cntry=0;
	vector<vector<bool> > mark(m,vector<bool>(n,false));
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			if(!mark[i][j]){
				cntry++;
				queue<pair<int,int> > mq;
				mq.push(make_pair(i,j));
				mark[i][j] = true;
				while(!mq.empty()){
					pair<int,int> cur = mq.front();
					mq.pop();
					int x=cur.first,y=cur.second;
					if(x-1>=0&&!mark[x-1][y]&&matrix[x-1][y]==matrix[x][y]){
						mark[x-1][y] = true;
						mq.push(make_pair(x-1,y));
					}
					if(x+1<m&&!mark[x+1][y]&&matrix[x+1][y]==matrix[x][y]){
						mark[x+1][y] = true;
						mq.push(make_pair(x+1,y));
					}
					if(y-1>=0&&!mark[x][y-1]&&matrix[x][y-1]==matrix[x][y]){
						mark[x][y-1] = true;
						mq.push(make_pair(x,y-1));
					}
					if(y+1<n&&!mark[x][y+1]&&matrix[x][y+1]==matrix[x][y]){
						mark[x][y+1] = true;
						mq.push(make_pair(x,y+1));
					}
				}
			}
		}
	}
	return cntry;
}
int main(int argc,char*argv[]){
	//int arr[3][4] = {1,1,1,0,1,1,0,0,0,0,0,1};
	int arr[3][4] = {1,1,1,1,0,0,0,0,1,0,0,1};
	vector<vector<int> > vec(3);
	int n=3,m=4;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;j++)
			vec[i].push_back(arr[i][j]);
	}
	cout << countries(vec) << endl;
	return 0;
}
