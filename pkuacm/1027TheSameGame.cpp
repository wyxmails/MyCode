#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct node{
	int row;
	int column;
	int score;
	friend bool operator<(node a,node b){
		if(a.score!=b.score){
			return a.score>b.score;
		}else if(a.column!=b.column){
			return a.column<b.column;
		}else if(a.row!=b.row){
			return a.row<b.row;
		}
	}
	friend bool operator>(node a,node b){
		if(a.score!=b.score){
			return a.score<b.score;
		}else if(a.column!=b.column){
			return a.column>b.column;
		}else if(a.row!=b.row){
			return a.row>b.row;
		}
	}
}node;
char board[15][20];
int mark[10][15];

void dfs(int row,int column,int& score,int move,int value){
	mark[row][column] += value;
	score++;
	//cout << "board[" << row << "][" << column << "]: " << board[row][column] << endl;
	if(score>50) return;
	if(row<9&&mark[row+1][column]<move
			&&board[row+1][column]==board[row][column])	
		dfs(row+1,column,score,move,value);
	if(row>0&&mark[row-1][column]<move
			&&board[row-1][column]==board[row][column])
	{
		dfs(row-1,column,score,move,value);
	}
	if(column<14&&mark[row][column+1]<move
			&&board[row][column+1]==board[row][column])
	{
		dfs(row,column+1,score,move,value);
	}
	if(column>0&&mark[row][column-1]<move
			&&board[row][column-1]==board[row][column])
	{
		dfs(row,column-1,score,move,value);
	}
	return;	
}

int main(int argc,char*argv[]){
	int t,score,move,finalscore,remains,tmp=1;
	//cin>>t;
	scanf("%d",&t);
	priority_queue<node,vector<node>,greater<node> > mypq;
	node tmpnode;
	while(tmp<=t){
		for(int i=9;i>=0;--i){
			scanf("%s",board[i]);
			//cin>>board[i];
		}
		for(int i=0;i<10;++i){
			for(int j=0;j<15;++j){
				mark[i][j] = 0;
			}
		}
		remains = 10*15;
		move = 1;
		finalscore=0;
		cout << "Game " << tmp << ":" << endl << endl;
		while(remains>1){
			for(int j=0;j<15;++j){
				for(int i=0;i<10;++i){
					if(move>mark[i][j]){
						//cout << "mark[" << i << "][" << j << "]: " << mark[i][j] << endl;
						score=0;
						dfs(i,j,score,move,1);
						tmpnode.row = i;
						tmpnode.column = j;
						tmpnode.score = score;
						mypq.push(tmpnode);
					}
				}
			}
			tmpnode = mypq.top();
			if(tmpnode.score>=2){
				remains -= tmpnode.score;
				score = (tmpnode.score-2)*(tmpnode.score-2);
				cout << "Move " << move << " at (" << tmpnode.row+1 << "," 
					<< tmpnode.column+1 << "): removed " << tmpnode.score 
					<< " balls of color " << board[tmpnode.row][tmpnode.column] 
					<< ", got " << score << " points." << endl;
				finalscore += score;
				score = 0;
				move++;
				dfs(tmpnode.row,tmpnode.column,score,move,150);
				while(!mypq.empty()){
					mypq.pop();
				}
			}else{
				break;
			}
			//move down
			int sinval,tmp;
			for(int j=0;j<15;++j){
				sinval=10;
				for(int i=0;i<10;++i){
					if(mark[i][j]>150&&i<sinval){
						sinval = i;
					}
					if(mark[i][j]<150&&i>sinval){
						tmp = mark[sinval][j];
						mark[sinval][j] = mark[i][j];
						board[sinval][j] = board[i][j];
						mark[i][j] = tmp;
						sinval++;
					}
				}
			}
			//move left
			bool flag;
			int max=0;
			for(int j=0;j<15;++j){
				if(max>15) break;
				flag = true;
				for(int i=0;i<10;++i){
					if(mark[i][j]<150){
						flag = false;
						break;
					}
				}
				if(flag){
					max++;
					for(int k=j+1;k<15;++k){
						for(int i=0;i<10;++i){
							tmp = mark[i][k-1];
							mark[i][k-1] = mark[i][k];
							board[i][k-1] = board[i][k];
							mark[i][k] = tmp;
						}
					}
					j--;
				}
			}
		}
		if(remains==0) finalscore+=1000;
		cout << "Final score: " << finalscore << ", with " << remains << " balls remaining." << endl << endl;
		tmp++;
	}
	return 0;
}
