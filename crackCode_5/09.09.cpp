/*
 Write an algorithm to prim all ways of arranging eight queens on an 8x8 chess board so that none of them share the same row, column or diagonal. In this case, "diagonal" means all diagonals, not just the two that bisect the board.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Queens(int row,vector<int> &mark){
	int n = mark.size();
	static int cnt = 0;
	if(row>=n){
		cnt++;
		cout << "arrange " << cnt << endl;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(j==mark[i]) cout << "Q";
				else cout << ".";
			}
			cout << endl;
		}
		return;
	}
	for(int c=0;c<n;++c){
		bool conflict = false;
		for(int r=0;r<row;++r){
			if(mark[r]==c||abs(row-r)==abs(c-mark[r])){
				conflict = true;
				break;
			}
		}
		if(!conflict){
			mark[row] = c;
			Queens(row+1,mark);
		}
	}
	return;
}

void Queens(int n){
	vector<int> mark(n,-1);
	Queens(0,mark);
}

int main(){
	cout << "Queens(1)" << endl;
	Queens(1);
	cout << "Queens(2)" << endl;
	Queens(2);
	cout << "Queens(3)" << endl;
	Queens(3);
	cout << "Queens(4)" << endl;
	Queens(4);
	cout << "Queens(5)" << endl;
	Queens(5);
	return 0;
}
