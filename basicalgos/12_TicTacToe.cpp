#include <iostream>
using namespace std;
#define N  3

int row[N];
int col[N];
int diagonal;
int anti_diagonal;

void init()
{
	for (int i = 0; i < N; i++) row[i] = 0, col[i] = 0;
	diagonal = anti_diagonal = 0;
}

/*
*  The player's step on setting A[x][y] to 1 or 0
*/
bool hasWin(int x, int y, int p)
{
	if (p == 1){
		row[x]++;
		col[y]++;
		if (x == y) diagonal++;
		if (x + y == N-1) anti_diagonal++;
	}
	else{
		row[x]--;
		col[y]--;
		if (x == y) diagonal--;
		if (x + y == N-1) anti_diagonal--;
	}
	
	return (row[x] == N || col[y] == N || diagonal==N || anti_diagonal == N);
}

int main(){
	int x,y,p;
	init();
	cin>>x>>y>>p;
	while(!hasWin(x,y,p)){
		cin>>x>>y>>p;
	}
	cout << "win" << endl;
}
