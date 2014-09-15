/**/

#include <iostream>
#include <vector>
using namespace std;

int countFlow(const vector<vector<int> >&M){
	int m=M.size();
	if(m<=1) return 0;
	vector<vector<int> > mark(m,vector<int>(m,-1));
	for(int s=1;s<m;++s){
		for(int i=0,j=i+s;i<m&&j<m;++i,++j){
			if(i==j-1){
				if(M[i][j]>M[i][j-1])
					if((j-1>0&&M[i][j-1]>M[i][j-2])||
							(i+1<m&&M[i][j-1]>M[i+1][j-1]))
						mark[i][j] = 1;
			}
			if(mark[i][j]==-1&&i+1==j){
				if(M[i][j]>M[i+1][j])
					if((j>0&&M[i+1][j]>M[i+1][j-1])||
							(i+2<m&&M[i+1][j]>M[i+2][j]))
						mark[i][j] = 1;
			}
			if(mark[i][j]==-1){
				if(i+1<m&&mark[i+1][j]==1&&M[i][j]>M[i+1][j])
					mark[i][j] = 1;
				if(j>0&&mark[i][j-1]==1&&M[i][j]>M[i][j-1])
					mark[i][j] = 1;
			}
			if(mark[i][j]==-1) mark[i][j] = 0;
		}
		for(int j=0,i=j+s;i<m&&j<m;++i,++j){
			if(j+1==i){
				if(M[i][j]>M[i][j+1])
					if((j+2<m&&M[i][j+1]>M[i][j+2])||
							(i>0&&M[i][j+1]>M[i-1][j+1]))
						mark[i][j] = 1;
			}
			if(mark[i][j]==-1&&i-1==j){
				if(M[i][j]>M[i-1][j])
					if((j+1<m&&M[i-1][j]>M[i-1][j+1])||
						(i-1>0&&M[i-1][j]>M[i-2][j]))
						mark[i][j] = 1;
			}
			if(mark[i][j]==-1){
				if(j+1<m&&mark[i][j+1]==1&&M[i][j]>M[i][j+1])
					mark[i][j] = 1;
				if(i>0&&mark[i-1][j]==1&&M[i][j]>M[i-1][j])
					mark[i][j] = 1;
			}
			if(mark[i][j]==-1) mark[i][j] = 0;
		}
	}
	int res = 0;
	for(int i=0;i<m;++i){
		for(int j=0;j<m;++j){
			cout << mark[i][j] << " ";
			res += mark[i][j]==-1?0:mark[i][j];
		}
		cout << endl;
	}
	return res;
}
int main(int argc,char*argv[]){
	//vector<vector<int> > vec(2,vector<int>(2,0));
	//vec[0][0] = 5;vec[0][1] = 1;
	//vec[1][0] = 3;vec[1][1] = 2;
	vector<vector<int> > vec(4,vector<int>(4,0));
	vec[0][0]=11;vec[0][1]=6;vec[0][2]=7;vec[0][3]=8;
	vec[1][0]=4;vec[1][1]=5;vec[1][2]=1;vec[1][3]=7;
	vec[2][0]=5;vec[2][1]=4;vec[2][2]=3;vec[2][3]=2;
	vec[3][0]=3;vec[3][1]=1;vec[3][2]=2;vec[3][3]=1;
	cout << countFlow(vec) << endl;
	return 0;
}
